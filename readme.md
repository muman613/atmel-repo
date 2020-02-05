# README

## Overview

This repository contains examples of programming the AtMega328p & AtMega2560 AVR chipsets using bare-metal access to the chips registers (rather than through HAL layers).

## Building

This repo has been tested on Ubuntu 18.04 Linux and Windows 10 using the `avr` tools.

### Windows WinAVR

Download the AVR tools for Windows from this link: 

http://winavr.sourceforge.net/download.html

### Ubuntu Linux or WSL Ubuntu

The AVR tools are available for installation through `apt`:

```
$> apt install avrdude gcc-avr avr-libc
```

## Flashing Bootloader

Scripts in the `scripts` directory are provided to flash the bootloaders for the supported chipsets.


Flashing of the bootloaders requires the `atmelice` programmer through the `isp` connection.


| Script | Description |
| ------ | ----------- |
| `flash_atmega328p.sh` | Script to flash the optiboot bootloader for Arduino |
| `flash_atmega2560.sh` | Script to flash the stk500 bootloader for Arduino Mega|

```
$> ./scripts/flash_atmega328p.sh

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: erasing chip
avrdude: reading input file "bootloaders/optiboot_atmega328.hex"
avrdude: writing flash (32768 bytes):

Writing | ################################################## | 100% 0.00s

avrdude: 32768 bytes of flash written
avrdude: verifying flash memory against bootloaders/optiboot_atmega328.hex:
avrdude: load data flash data from input file bootloaders/optiboot_atmega328.hex:
avrdude: input file bootloaders/optiboot_atmega328.hex contains 32768 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.00s

avrdude: verifying ...
avrdude: 32768 bytes of flash verified

avrdude: safemode: Fuses OK (E:FD, H:D6, L:FF)

avrdude done.  Thank you.
```

## Example Projects

| Directory | Description | Platforms |
| --------- | ----------- | --------- |
| `baremetal-blink` | Simple LED blinking application | ATMega328p/ATMega2560 |
| `baremetal-uart` | Simple application sends data to UART periodically | ATMega328p/ATMega2560 |
| `baremetal-timer` | Simple application programs timer 1 w/interrupt | ATMega328p/ATMega2560 |

