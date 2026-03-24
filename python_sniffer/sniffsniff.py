from nrf802154_sniffer import Nrf802154Sniffer

sniffer = Nrf802154Sniffer()
import subprocess
device = [f.decode().split("Ports")[1].strip() for f in subprocess.run(["nrfutil","device","list"], stdout=subprocess.PIPE).stdout.splitlines() if f.decode().startswith("Ports")][0]
sniffer.extcap_capture(fifo="zigbee.pcap",dev=device, channel=11, metadata="ieee802154-tap")

def stop():
    sniffer.stop_sig_handler()

import threading
threading.Timer(5.0,stop).start()