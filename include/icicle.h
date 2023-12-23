#ifndef ICICLE_H
#define ICICLE_H
#include "Timer.h"
#include <FastLED.h>

#define ICICLE_STEP 20
struct Spos {
    int8_t step;   //+-1
    int8_t source; //1 - начало, 0 - середина, -1 - конец
    uint16_t pos;   //номер светодиода
};

class Icicle: public Timer {
        Spos sPos;   //направление { -1 - вниз, +1 - вверх }, {-1 начало, 0 середина, 1 конец}
        uint16_t len;   //число светодиодов
        uint8_t steps;
        uint16_t numLeds;
        uint32_t dT;
        CRGB color;
        bool status;
    public:
        Icicle(uint16_t nl, uint8_t sour);
        Icicle(uint16_t nl);
        bool cycle(CRGB*);   //возвращает true, если итерация завершена
        void init(int8_t sour);
};

#endif //ICICLE_H