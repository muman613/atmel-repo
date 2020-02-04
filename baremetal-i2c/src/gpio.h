#ifndef __GPIO_H__
#define __GPIO_H__

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);

#define MODE_INPUT      0
#define MODE_OUTPUT     1

#define VALUE_HIGH      1
#define VALUE_LOW       0

#endif
