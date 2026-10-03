#ifndef ANALOGINPUT_H
#define ANALOGINPUT_H

#include <Arduino.h>
#include "Vector2.h"

typedef struct {
    const uint8_t Pin;
    float CurrentValue;
    Vector2 Thresholds;


} AnalogInput;

#endif