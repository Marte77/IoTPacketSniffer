# how to capture 802.15.4 packets:
Download the [firmware for the dongle here](https://github.com/NordicSemiconductor/nRF-Sniffer-for-802.15.4/blob/master/nrf802154_sniffer/nrf802154_sniffer_nrf52840dongle.hex). Put the dongle in bootloader mode (red led blinking) and open the nrf connect app and then the programmer tool. Select the device on the top left and in add file choose the downloaded hex. then click write and wait. When it's done, run the python script `sniffsniff.py`, and it'll capture for 5 seconds. its possible to change the channels and stuff by altering the constructor used in the file.

<sub>__bootloader mode is set by pressing the sideways button__</sub>
# how to capture BLE packets:
Install nrfutils CLI tool by following [this guide (keep track where it was installed as that place contains the firmware needed)](https://docs.nordicsemi.com/bundle/nrfutil/page/guides/installing.html). Then install wireshark and plugins by following [this guide](https://docs.nordicsemi.com/bundle/nrfutil/page/guides/installing_wireshark.html). Now you can Follow [this guide to install the firmware. Dont forget to put the dongle in bootloader mode](https://docs.nordicsemi.com/bundle/nrfutil/page/nrfutil-ble-sniffer/guides/requirements.html).

# report
explain how capture works and what was used
analyze zigbee communication in a smart home environment - explain the environment (so zigbee2mqtt and the type of radio and devices) try to check if i can turn on the light without using my zigbee2mqtt
ble - if headset with BLE analyze and identify audio packets for example
verify if security measures are used in BLE and 802.15.4





---------------------
ignore these

~~Build instructions [here](https://github.com/Marte77/IoTPacketSniffer/blob/main/compile_and_run.md)~~


~~https://github.com/nrfconnect/sdk-nrf/blob/main/samples/bluetooth/central_and_peripheral_hrs/prj.conf~~

