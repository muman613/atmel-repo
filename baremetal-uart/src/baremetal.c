#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"
#include "pins.h"

#define OFF_DELAY       500
#define ON_DELAY_1      1000
#define ON_DELAY_2      2000

int on_delay  = ON_DELAY_1;
int off_delay = OFF_DELAY;



#define BAUD_RATE    115200

char msgBuffer[128];


void delay_ms(int ms) {
    for (int i = 0 ; i < ms ; i++) {
        _delay_ms(1);
    }
}

int main (void) {
    int i = 0;
    int index = 0;

    pinMode(BUILTIN_LED, MODE_OUTPUT);
    uart_config(BAUD_RATE, SERIAL_8N1);

    while(1) {
        if (UCSR0A & (1<<RXC0)) {
            char data = UDR0;

            switch (data) {
                case 'A':
                    on_delay = ON_DELAY_1;
                    break;
                case 'B':
                    on_delay = ON_DELAY_2;
                    break;
            }
        }
        snprintf(msgBuffer, 128, "Hello World (%d) (%d)\n\r", index++, on_delay);
        uart_print(msgBuffer);

        digitalWrite(BUILTIN_LED, VALUE_HIGH);
        /*Wait 3000 ms */
        delay_ms(on_delay);

        digitalWrite(BUILTIN_LED, VALUE_LOW);
        /*Wait 3000 ms */
        delay_ms(off_delay);
    }
}
