The following repository contains some examples of how to use the Tundra Labs RP2040 Breakout Board with Tundra Tracker to send custom controller information.

## Structure
Each example is composed of some folders:
* Arduino
    * This is the RP2040 Arduino code that is programmed into the Dev board
    * Example will include a snapshot of the TMI library that was tested at the time of uploading
    * Future inprovements could have been made to the library in other examples
* Device JSON
    * ALWAYS BEFORE WRITING JSON Files, perform a `downloadconfig backup.json` command  
    * The example.json is partially defined file that does not contain sensor calibration data
    * to merge the `backup.json` and `example.json` files together, copy the `"lighthouse_config"` and `"imu"` blocks from `backup.json` into `example.json`, save as to `new.json`
    * ALWAYS preserve a copy of `backup.json` to revert your tracker to the original calibration
    * upload a new json config to your device in lighthouse console using `uploadconfg new.json`
    * Inevitably everyone at some point looses a Json file or writes it to the wrong device :(
        * Find archives in your PC in the following folder: `C:\Program Files (x86)\Steam\config\lighthouse`
        * Here you will find a json file from every serial number device that you have ever connected to steam (Thanks Valve!)
* Driver folder
    * Drivers are a collection of files that tell SteamVR about your device.
    * Drivers are added to the following folder: `C:\Program Files (x86)\Steam\steamapps\common\SteamVR\drivers`
    * The Device JSON will indicate the search directory to find your driver
    * Inside of the driver folder there resources structure
        * icons - This is where you store your SteamVR icons, the primary icons that you should have are:
            * x_status_error.png
            * x_status_ready.png
            * x_status_off.png
            * x_status_searching.gif
            * x_status_standby.png
            * (SteamVR will autogenerate other versions of your icons)
        * rendermodels - This is where you store the .obj and .mtl files for your device.
            * Creates the 3D model that appears in SteamVR when your device is active
        * localization - a json file that translates your device strings to other languages
        * input - a folder that contains all of the details of your device inputs.  There will be an entire section on this one...

## Input Files
Input files are a collection of files that describe to SteamVR the structure of your input data and how to publish it to the SteamVR input system.  This is the PC side of the customization that is done in the Arduino code.  This section shall describe in more detail how to author the input json files and get your controller inputs into SteamVR.

### x_input_profile.json file
    * `"input_components"`
        

## Input Debugging
To debug your input, you can access the debugger gui located here: (location TBD, need to find this thing, it is always hiding, grr)