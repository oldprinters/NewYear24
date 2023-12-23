#include "icicle.h"

//--------------------------------
void Icicle::init(int8_t sour){
    if(!numLeds)throw "numLeds is 0";
    sPos.source = sour;
   	color = CRGB(rand() % 255, rand() % 255, rand() % 255);
    uint8_t luma = color.getLuma();
    steps = len = luma / ICICLE_STEP + 1;
    if(sour == 0){
        sPos.step = rand() % 2? 1: -1;
        sPos.pos = numLeds / 2;
    } else {
        sPos.step = sour;
        sPos.pos = sour > 0? len: numLeds - len;
    }
    dT = len * ICICLE_STEP + 50;
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
        // uint16_t l = sPos.pos + len * sPos.step;
        uint16_t s1 = sPos.pos;
        uint16_t len1 = len;

        if(sPos.step > 0){
            if(sPos.pos + len >= numLeds - 1){
                s1 = 0;
                len1 = numLeds - sPos.pos;
            }
            fill_gradient_RGB(leds + s1, len1, leds[sPos.pos], color);
        } else {
            if(sPos.pos - len <= 0){
                len1 = sPos.pos; 
            }
            fill_gradient_RGB(leds + s1, len1, color, leds[sPos.pos]);
        }
        // for(uint8_t i = 0; i < len; i++){
            // if(l >= 0 && l < numLeds){
            //     leds[l]= color;
            //     leds[l].subtractFromRGB(ICICLE_STEP * i);
            //     l += sPos.step;
            // }
        // }
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