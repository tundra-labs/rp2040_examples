## tmi_hand_controller
This project demonstrates standalone code running on RP2040 the generate simulated input data for a index controller like device.  If includes datastructures for a thumbstick, A and B button plus a menu and system button.

You can use the provided cables to upload the Arduino sketch to the RP2040 Breakout Board

## Step 1: SteamVR Driver installation 
In order to install the tmi_hand_controller Controller StewamVR driver you must copy the `tmi_ hand_controller\driver/tmi_hand_controller` folder to the SteamVR directory typically located at 
`C:\Program Files (x86)\Steam\steamapps\common\SteamVR\drivers`
![Driver folder](../images/driver_folder2.PNG)
the structure inside of `C:\Program Files (x86)\Steam\steamapps\common\SteamVR\drivers\tmi_hand_controller` should look like this:
![Inside tmi_hand_controller](../images/driver_folder2.PNG)

## Step 2: Modify the Tundra Tracker Device JSON Configuration
*** Caution, do not connect any other SteamVR devices to your PC during testing.  Especially your HMD ***

To verify that this input data is being sent to the PC, you must:
0) Connect your tracker to your PC via USB, disconnect all dongles, HMD, controller, etc
1) Start lighthouse_console from `C:\Program Files (x86)\Steam\steamapps\common\SteamVR\tools\lighthouse\bin\win32`
2) Verify that there is only one device connected:
![Only 1 device!!!](../images/only1.png)

***If you have more than one device listed here, do not move forward, disconnect everything else!***

3) download the Tracker json file using `downloadconfig t.json`
4) open the configuration and add the following line to the `"firmware_config":{...}` block
  `"mapped_input" : true`
5) Modify these other lines of your JSON at the root of the structure
```
   "device_class" : "controller",
   "device_serial_number" : "LHR-A6B3A15B",
   "manufacturer" : "Tundra Labs",
   "model_number" : "Tundra Hand Controller",
   "render_model" : "{tmi_hand_controller}/tmi_hand_controller",
   "resource_root" : "tmi_hand_controller",
   "input_profile" : "{tmi_hand_controller}/input/tmi_hand_controller_profile.json",
   "revision" : 1,
```
5) save t.json
6) start lighthouse_console again and use 'uploadconfig t.json' to upload the revised JSON file to the tracker
7) use the command `reboot` to restart the tracker
8) when the tracker is restarted, type the `axis` command to dump out input data to the console

You should see an output like below:
![lighthouse_console Axis Output](../images/simple_tmi_lh_output.png)

## Step 3: Start SteamVR
You should be able to launch SteamVR and see a controller icon, once tracking is established, the Icon will turn from flashing to solid:
![SteamVR Screen](../images/tmi_hand_steamVR.png)

*** Note: Controller outputs will not be published unless tracking is established ***

Use the Devices > Controller Settings > Test Controller to verify that the outputs are changing:

![Controller Debugger](../images/ControllerDebugger.PNG)

## Step 4: Modification
The sample code in this repository creates the datastructure and then uses code in the loop function to increment the inputs.  This makes a quick demo without the need for someone to attach sensors or write additional Arduino code to read sensors.  Now that you have the rest of the demo verified, modify the Arduino code to mix in your own sensors and build something fun!

Please be sure to share your projects with us on twitter!

@tundra_labs