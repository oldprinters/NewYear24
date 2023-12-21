#include "ledik.h"

Ledik::Ledik(uint16_t nL, uint16_t pos, uint32_t d): Timer(d), numLeds(nL), _pos(pos){
	init();
}
//------------------------------------
void Ledik::init(){
	dT = rand() % 10 * 100 + 500;
	color = CRGB(rand() % 256, rand() % 256, rand() % 256);
	_pos = rand() % numLeds;
	// Serial.print("dT = ");
	// Serial.println(dT);
}
//------------------------------------
void Ledik::show(CRGB* leds){
	leds[_pos] = color;
}
//------------------------------------
// void Ledik::update(){
// 	if(isTime()){
// 		init();
// 	}
// }
