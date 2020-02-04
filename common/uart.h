#ifndef __UART_H__
#define __UART_H__

#include <avr/io.h>
#include <util/delay.h>
#include "macros.h"

#define SERIAL_8N1 0x06

void uart_config(uint16_t baudrate);
void uart_print(const char *data);

#endif
