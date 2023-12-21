#ifndef LEDIK_H
#define LEDIK_H
#include "Arduino.h"
#include "Timer.h"
#include <FastLED.h>

class Ledik: public Timer {
        uint16_t _pos;
        uint16_t numLeds;
        uint32_t dT{50};
        CRGB color;
    public:
        Ledik(uint16_t nL, uint16_t pos, uint32_t d);
        void init();
        void show(CRGB* leds);
};

#endif