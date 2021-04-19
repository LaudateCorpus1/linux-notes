Biscuit
=======

Biscuit is an open source firmware for TI CC2540 SoC (designed for Bluetooh 4.0 Low Energy applications).

This source code is designed and tested on BLE Mini hardware platform but it can be run on other CC2540 platforms with some modifications.


Features
========

1. BLE peripheral role running TXRX Service (with 128-bit UUID) which allows BLE central role devices to connect with it (e.g. iOS Devices)
2. UART driver which can redirect data to/from UART for connecting external devices (e.g. Arduino)
3. I2C driver (software implementation), for controlling I2C components (e.g. EEPROM on BLE Mini)
4. Firmware upgradable via USB port (support TI CC2540 UBL 1.3)
5. USB CDC which provides a virtual UART via USB port for connecting to an external device with the USB port (e.g. PC Windows/Linux or Mac OSX)

Note: USB upgrade can be done on Windows PC only (XP and up to 8.0, but except 8.1), also not Mac OSX nor Linux.


Requirement
===========

1. CC2540 hardware (e.g. BLE Mini).
2. To compile the Biscuit source code, obtain a copy of IAR Embedded Workbench for 8051 version 8.10 or latest. Refer to TI CC254x development resources.
3. TI CC254x SDK version 1.4.
4. UBL version 1.3 - We make use of the new USB bootloader so UBL 1.3 code is required.
5. Besides using the bootloader, if you want to program/debug the firmware with hardware (e.g. BLE Mini), you need a CC Debugger.


Examples
========

1. Biscuit-UART, it relays TX/RX data to/from Central device via BLE and forwards data to UART, so that you can connect to external MCU for processing.<br/>
<br/>
2. Biscuit-RGB, it shows how to control a RGB LED (Flora NeoPixel) using 1-wire I/O, it connects to the TX pin of the BLE Mini.


How to Compile
==============

1. Make sure you know how to do before trying to compile and load the firmware because incorrect configuration can cause the pre-loaded bootloader fails to function.

2. For details, see current\readme.txt or wiki,

  https://github.com/RedBearLab/Biscuit/wiki


Q&A
===

1. How to change the baudrate of the UART?

  > The charateristic, UUID: 0x713D0004-503E-4C75-BA94-3148F18D941E can be used for changing the baudrate. You can use LightBlue or BLExplr Apps available on iOS or B-BLE on Android to change it.

  > To change the baudrate, write a byte 0x00 (9600bps), 0x01 (19200bps), 0x02 (38400bps), 0x03 (57600bps) or 0x04 (115200bps) to the characteristic.

  > See our wiki for details, https://github.com/RedBearLab/Biscuit/wiki


More Information
================

1. Upgrade Firmware via USB Bootloader - TI's reference design or BLE Mini have a button connected to P1_2 pin is for triggering the USB upgrade mode. Press and hold the button, connect to a Windows PC, it will show a Mass Storage Drive, you can delete the old firmware and drag the new firmware to it.

2. USB Boot Loader - USB boot loader which is different from typical implementation, please refer to TI's document "Universal Boot Loader for SOC-8051 by USB-MSD Developer's Guide.pdf" and their sample project "HostTestApp" in their latest BLE SDK v1.3

3. TI CC2540 Wiki (resources and other related information for the CC2540 SoC)
   http://processors.wiki.ti.com/index.php/Category:BluetoothLE


License
=======

Copyright (c) 2013 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
