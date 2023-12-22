#include "icicle.h"

//--------------------------------
void Icicle::init(uint8_t sour){
    if(!numLeds)throw "numLeds is 0";
    sPos.source = sour;
    if(sour == 0){
        sPos.step = rand() % 2? 1: -1;
        sPos.pos = numLeds / 2;
    } else {
        sPos.step = sour;
        sPos.pos = sour > 0? 0: numLeds - 1;
    }
   	color = CRGB(rand() % (155 + 100), rand() % (155 + 100), rand() % (155 + 100));
    uint8_t luma = color.getLuma();
    steps = len = luma / 40 + 1;
    dT = len * 20 + 100;
    setDt(dT);
    setTimer();
    status = true;
}
//--------------------------------
Icicle::Icicle(uint16_t nl, uint8_t sour): numLeds(nl) {
    init(sour);
}
//--------------------------------
Icicle::Icicle(uint16_t nl): numLeds(nl) {
    uint8_t sour = rand() % 3 - 1;
    init(sour);
}
//--------------------------------
bool Icicle::cycle(CRGB* leds){
    if(status && !getTimer()){
        uint16_t l = sPos.pos + len * sPos.step;
        for(uint8_t i = 0; i < len; i++){
            if(l >= 0 && l < numLeds){
                leds[l]= color;
                leds[l].subtractFromRGB(40 * i);
                l += sPos.step;
            }
        }
        setTimer();
        sPos.pos += sPos.step;
    } else {
        // Serial.println("***");
    }
    if(sPos.pos == 0 || sPos.pos == numLeds - 1){
        status = false;
    }
    return status;
}