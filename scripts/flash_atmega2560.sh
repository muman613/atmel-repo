#!/bin/bash

avrdude -c atmelice_isp -p atmega2560 -e -Uflash:w:bootloaders/stk500boot_v2_mega2560.hex:i

