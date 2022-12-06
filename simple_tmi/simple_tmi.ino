
#include "tundra_mapped_input.h"

#define RP2040_BB_LED           (25)

TMI tundra_tracker;

void csn_irq( uint gpio, uint32_t event_mask );

typedef struct __attribute__( ( packed, aligned( 1 ) ) )
{
  uint8_t       system: 1;
  uint8_t       menu: 1;
  uint8_t       a: 1;
  uint8_t       b: 1;
  uint8_t       trigger: 1;
  uint8_t       reserved: 3;
}
controller_buttons_t;

typedef struct __attribute__( ( packed, aligned( 1 ) ) )
{
  controller_buttons_t  button;
  uint8_t               trigger;
  int16_t               trackpad_x;
  int16_t               trackpad_y;
} 
controller_data_t;

controller_data_t controller_data;

uint32_t interval = 250;
uint32_t next_time = 0;

bool led_state = false;

void setup() {
  
  pinMode(RP2040_BB_LED, OUTPUT);

  tundra_tracker.init( );
  gpio_set_irq_enabled_with_callback( tundra_tracker.get_cs_pin(), GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &csn_irq );
}


// the loop function runs over and over again forever
void loop() {
  if ( tundra_tracker.data_ready() )
  {
    tundra_tracker.send_data( &controller_data, sizeof(controller_data) );
    tundra_tracker.handle_rx_data( );
  }
  
  if ( millis() > next_time )
  {
    controller_data.button.a = led_state;
    controller_data.trigger ++;
    
    next_time = millis() + interval;
    digitalWrite(RP2040_BB_LED, led_state ^= true);
  }
}

void csn_irq( uint gpio, uint32_t event_mask )
{
  tundra_tracker.csn_irq( gpio, event_mask );
}
