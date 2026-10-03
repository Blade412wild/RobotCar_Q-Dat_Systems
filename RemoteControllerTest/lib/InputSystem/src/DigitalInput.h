#ifndef DIGITALINPUT_H
#define DIGITALINPUT_H

#include <Arduino.h>

typedef struct
{
    const uint8_t Pin;
    uint8_t CurrentValue; // high or low 
    uint8_t PreviousValue;

} DigitalInput;

#endif