from nrf802154_sniffer import Nrf802154Sniffer

sniffer = Nrf802154Sniffer()

sniffer.extcap_capture(fifo="zigbee.pcap",dev="/dev/tty.usbmodem1101", channel=11, metadata="ieee802154-tap")

def stop():
    sniffer.stop_sig_handler()

import threading
threading.Timer(5.0,stop).start()