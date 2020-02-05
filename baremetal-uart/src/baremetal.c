#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"
#include "pins.h"

#define OFF_DELAY   500
#define ON_DELAY    1000

#define BAUD_RATE    115200

char msgBuffer[128];

int main (void) {
    int i = 0;
    int index = 0;

    pinMode(BUILTIN_LED, MODE_OUTPUT);
    uart_config(BAUD_RATE, SERIAL_8N1);

    while(1) {
        snprintf(msgBuffer, 128, "Hello World (%d)\n\r", index++);
        uart_print(msgBuffer);

        digitalWrite(BUILTIN_LED, VALUE_HIGH);
        /*Wait 3000 ms */
        _delay_ms(ON_DELAY);

        digitalWrite(BUILTIN_LED, VALUE_LOW);
        /*Wait 3000 ms */
        _delay_ms(OFF_DELAY);
    }
}
