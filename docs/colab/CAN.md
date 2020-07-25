# CAN
CAN is a multi-master bus for connecting electronic control units. The communication
relies on a voltage differential between these two lines and so is not sensitive to noise.
A node consists of:
 * Micro controller - STM32
 * CAN controller - MCP 2515
 * Transceiver - MCP 2551

A circuit layout for a node controlled by Arduino UNO: [link](https://cdn.instructables.com/ORIG/F2K/IS9L/J5X0IES3/F2KIS9LJ5X0IES3.jpg?auto=webp&fit=bounds)

### Installing CAN Library for Arduino IDE:
* Download the zip file from [https://github.com/Seeed-Studio/CAN_BUS_Shield](https://github.com/Seeed-Studio/CAN_BUS_Shield)

### Basic Arduino Codes:
* Code for [Sender](https://cdn.instructables.com/ORIG/F1V/YKNY/J5X0MJVM/F1VYKNYJ5X0MJVM.ino)
* Code for [Reciever](https://cdn.instructables.com/ORIG/FVF/4ZTO/J5X0MJVN/FVF4ZTOJ5X0MJVN.ino)

### For any References: [CAN instructables ](https://www.instructables.com/id/Yes-We-CAN-BUS-With-Arduino-in-30-Seconds/)