How to run firmware Micropython in Thonny

-select port
-select package

edit port and username 
```$ cd Documents/Arduino```
=============================
```$ "/Users/drgmark7/Library/Arduino15/packages/esp32/tools/esptool_py/4.5.1/esptool" --chip esp32s3 --port "/dev/cu.usbserial-130" --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dout --flash_freq 80m --flash_size 32MB 0x0 bootloader.bin 0x8000 partitions.bin 0x10000 micropython.bin```
