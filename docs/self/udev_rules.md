## Remapping udev rules to something intuitive
Reference: https://unix.stackexchange.com/questions/66901/how-to-bind-usb-device-under-a-static-name
 ### Commands
* `lsusb` gives the info of USB device as XXXX:YYYY where XXXX is vendor_id and YYYY is product_id 
* Edit `/etc/udev/rules.d/10-local.rules` as

    * `ACTION=="add", ATTRS{idVendor}=="XXXX", ATTRS{idProduct}=="YYYY", SYMLINK+="drive_arduino"`

***

 ### To get more info about the USB device you may use these commands -
  * `lsusb -v -d XXXX:YYYY` or
  * `udevadm info -a -p  $(udevadm info -q path -n /dev/ttyUSB0)`

***

## Binding a dev-name to a particular physical USB port 
A particular physical port is linked to a desired dev-name
Reference: https://superuser.com/a/536648
 ### Commands
* `udevadm info /dev/ttyUSB0` gives the info of USB device `\dev\ttyUSB0` and note the `ID_PATH`
* Edit `/etc/udev/rules.d/10-local.rules` as

    * `SUBSYSTEM=="tty", ENV{ID_PATH}=="pci-0000:00:1d.0-usb-0:1.2:1.0", SYMLINK+="imu"`
