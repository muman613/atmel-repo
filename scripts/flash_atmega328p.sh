#!/bin/bash

avrdude -c atmelice_isp -p atmega328p -e -Uflash:w:bootloaders/optiboot_atmega328.hex:i

