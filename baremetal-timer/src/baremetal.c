#include <avr/io.h> 
#include <avr/interrupt.h>
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


// this code sets up a timer0 for 4ms @ 16Mhz clock cycle
// an interrupt is triggered each time the interval occurs.

int main(void)
{
    uart_config((uint16_t)115200);
    OCR1A = 0x1f40;

    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer


    sei();
    // enable interrupts


    while (1)
    {
        // we have a working Timer
    }
}

ISR (TIMER1_COMPA_vect)
{
    // action to be done every 1 sec
    uart_print("ISR\n\r");
}