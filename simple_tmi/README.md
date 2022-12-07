## simple_tmi
This project demonstrates standalone code running on RP2040 the generate simulated input data.  In this code a couter toggles the a button every 250ms and ingrements the 8bit value of the trigger input.

You can use the provided cables to upload the Arduino sketch to the RP2040 Breakout Board

*** Caution, do not connect any other SteamVR devices to your PC during testing.  Especially your HMD ***
To verify that this input data is being sent to the PC, you must:
1) Start lighthouse_console from `C:\Program Files (x86)\Steam\steamapps\common\SteamVR\tools\lighthouse\bin\win32`
2) download the Tracker json file using `downloadconfig t.json`
3) open the configuration and add the following line to the `"firmware_config":{...}` block
  `"mapped_input" : true`
4) save t.json
5) start lighthouse_console again and use 'uploadconfig t.json' to upload the revised JSON file to the tracker
6) use the command `reboot` to restart the tracker
7) when the tracker is restarted, type the `axis` command to dump out input data to the console

You should see an output like below:
![lighthouse_console Axis Output](../images/simple_tmi_lh_output.png)

Here we can see that the alternating 0x00 and 0x04 is the toggling of the a button
The 2nd byte that is incrementing upward represents the trigger value
