#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"
#include "pins.h"
#include "timer.h"


static void timer_cb(uint16_t count);

static void hw_init() {
    uart_config(115200, SERIAL_8N1);
    init_timer1_interrupt(2000, timer_cb);
    pinMode(BUILTIN_LED, MODE_OUTPUT);
}

int main(void)
{
    hw_init();

    while (1)
    {
        // we have a working Timer
    }
}

void timer_cb(uint16_t count) {
    static char msgBuffer[32];
    snprintf(msgBuffer, 32, "Hello ISR (%d)\n\r", count);
    uart_print(msgBuffer);
    togglePin(BUILTIN_LED);
}