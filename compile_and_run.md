# HOW TO COMPILE AND RUN

- Have the VSCode extension for nordic installed, using the latest sdk make sure the applications in the nrf connect extension view has a build configuration. Clean it and then on actions run build.
- if successful, a build/ folder (default for build configs if unchanged) is created and a merged.hex file is created.
- Open nRF Connect for Desktop and install the programmer app and open it. 
- Press the Select device button on the top left corner, making sure the dongle is in bootloader mode (blinking red led, achieved by pressing the sideways reset button), and select the device (enable auto connect for easier deployment). Then add the build/merged.hex file, and press write. 
- Afterwards, to deploy again just press the reset button, reload the file and write again.
