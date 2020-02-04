#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

/**
 * Configure the UART peripheral.
 */
void uart_config(uint16_t baudrate) {
    uint16_t baud_setting = (F_CPU / 4 / baudrate - 1) / 2;

    UCSR0A = 1 << U2X0;
    if (((F_CPU == 16000000UL) && (baudrate == 57600)) || (baud_setting >4095)) {
        UCSR0A = 0;
        baud_setting = (F_CPU / 8 / (baudrate - 1)) / 2;
    }

    // baud_setting = 17;
    // assign the baud_setting, a.k.a. ubrr (USART Baud Rate Register)
    UBRR0H = baud_setting >> 8;
    UBRR0L = baud_setting;
    UBRR0H = 0;
    UBRR0L = 17;

    UCSR0C = SERIAL_8N1;

    sbi(UCSR0B, RXEN0);
    sbi(UCSR0B, TXEN0);
}

void uart_print(const char *data) {
    int i = 0;
    while (data[i] != 0) {
        while (!( UCSR0A & (1<<UDRE0)));
        UDR0 = data[i];					 /* Put data into buffer, sends the data */
        i++;
    }
}
