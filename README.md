# PanTiltCameraRig
Project aims to build a Camera rig with pan and tilt capbilities that is controlled using websockets. 

Layout is described in the fritzing diagram, however the version used for esp32 is somewhat different then shown in scehmatic.
if using this version please use correct pins according to your ESP32 version.

Future version: Aims to implement streaming video using the ESP32 CAM module.

### Parts
To build this plattform the following parts required
smal pan tilt brackets, available at ebay such as(https://www.ebay.com/itm/284723847214?hash=item424add202e:g:m3AAAOSwi7piPVUx).
2 SG 90  micro servo engines, alternativly use mg 90(made in metall compared to sg90 plastic)
1 ESP32D Wroom developent board.

### Requirements
This project is dependent on the ESP32Servo Library by Kevin Harrington.

### Wiering

![Alt text](/RigSchema.jpg?raw=true "Wireing schema")



### Code
To use the code, there are two lines of code that need to be altered to make it applicable on your network. The ssid and password must match
the credidential on your wifi setup.
