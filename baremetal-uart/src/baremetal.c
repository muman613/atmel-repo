#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"


#define OFF_DELAY   500
#define ON_DELAY    1000

#if defined(__AVR_ATmega2560__)
    const int ddb   = DDB7;
    const int portb = PORTB7;
#elif defined(__AVR_ATmega328P__)
    const int ddb   = DDB5;
    const int portb = PORTB5;
#endif



unsigned long baud = 115200;

//char * msg = "Hello World \n\r";
char msgBuffer[128];

int main (void) {
    int i = 0;
    int index = 0;

    uart_config(baud);

    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */
    DDRB |= _BV(ddb);

    while(1) {

        snprintf(msgBuffer, 128, "Hello World (%d)\n\r", index++);
        uart_print(msgBuffer);

        /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        PORTB |= _BV(portb);

        /*Wait 3000 ms */
        _delay_ms(ON_DELAY);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        PORTB &= ~_BV(portb);

        /*Wait 3000 ms */
        _delay_ms(OFF_DELAY);
    }
}
