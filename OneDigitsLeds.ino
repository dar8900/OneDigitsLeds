/*Libreria per la gestione di tre digit fatti di led e shift register*/
#include "OneDigitsLeds.h"
#define N_DISPLAY 	5

ODL Leds;

void setup()
{
	Leds.beginDisplays(N_DISPLAY);

}


void loop()
{
	Leds.drawNumber(32);

}
