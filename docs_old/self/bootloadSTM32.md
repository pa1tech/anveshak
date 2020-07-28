---
title: Bluepill bootloading
navigation: 2

---
## STM32 Bluepill - Flashing bootloader to enable USB interfacing

### Installing stm32flash
* Download stm32flash source from <https://github.com/stm32duino/stm32flash>
* Extract the file, navigate into the extracted folder and build it using the command 
     `sudo make install`
* Also download the binary file <https://github.com/rogerclarkmelbourne/STM32duino-bootloader/raw/master/binaries/generic_boot20_pc13.bin> , which is to be flashed

***

### Connections
* Make the boot0 jumper HIGH and boot1 jumper LOW
* Connect USB-Serial converter 
    RX - PA9 || TX - PA10 and power pins
* Connect the serial converter to your computer and run the command `stm32flash /dev/ttyUSB0` to check if the STM is detected, if not reset the STM and try again 
* Once STM is initialized, navigate to the folder conatining the binary file and run
   `stm32flash -v -w ./generic_boot20_pc13.bin /dev/ttyUSB0`
* Change the boot pins to default configuartion

***

Reference: <http://wiki.stm32duino.com/index.php?title=Bootloader>