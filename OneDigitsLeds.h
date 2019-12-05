/*Libreria per la gestione di tre digit fatti di led e shift register*/
#ifndef THREE_DIGITS_LEDS_H
#define THREE_DIGITS_LEDS_H
#include <Arduino.h>
#include <ShiftyReg.h>
#include <stdint.h>

#define DEBUG

#ifdef DEBUG
#define DBG(msg)			Serial.println(msg)
#define MSG_MAX_CHAR(Func)	("Superamento caratteri per il display corrente" + String(Func))
#else
#define DBG(msg)
#endif

#define DATA_PIN_DFLT		          2
#define CLOCK_PIN_DFLT  			  3
#define LATCH_PIN_DFLT 				  4
#define OUT_PUT_EN_DFLT 		      NOT_DEFINED_PIN
#define CLEAR_REG_PIN_DFLT 			  NOT_DEFINED_PIN
#define N_DISPLAYS_DFLT 			  1

typedef enum 
{
	ZERO = 0,
	UNO,
	DUE,
	TRE,
	QUATTRO,
	CINQUE,
	SEI,
	SETTE,
	OTTO,
	NOVE,
	MENO,
	GRADI,
	PUNTO,
	ZERO_PUNTO,
	UNO_PUNTO,
	DUE_PUNTO,
	TRE_PUNTO,
	QUATTRO_PUNTO,
	CINQUE_PUNTO,
	SEI_PUNTO,
	SETTE_PUNTO,
	OTTO_PUNTO,
	NOVE_PUNTO,	
	CLEAR,
	MAX_CHARATERS
}CHARATERS_NAME;

class ODL
{
	public:
		void setDataPin(uint8_t DataPin = DATA_PIN_DFLT);
		void setClockPin(uint8_t ClockPin = CLOCK_PIN_DFLT);
		void setLatchPin(uint8_t LatchPin = LATCH_PIN_DFLT);
		void setComPins(uint8_t DataPin, uint8_t ClockPin, uint8_t LatchPin);
		void beginDisplays(uint8_t NumOfDisplay = N_DISPLAYS_DFLT);	
		void drawChar(uint8_t WichChar = ZERO, uint8_t WichDisplay = N_DISPLAYS_DFLT);
		void drawChar(char WichChar, uint8_t WichDisplay = N_DISPLAYS_DFLT);
		void drawChar(const char *WichChar, uint8_t WichDisplay = N_DISPLAYS_DFLT);
		void drawNumber(int16_t Number);
		void drawNumber(float Number);
		void ClearDisplay(uint8_t WichDisplay = N_DISPLAYS_DFLT);
	private:
		uint8_t dataPin = DATA_PIN_DFLT;
		uint8_t clockPin = CLOCK_PIN_DFLT;
		uint8_t latchPin = LATCH_PIN_DFLT;
		uint8_t numberOfDisplay = N_DISPLAYS_DFLT;
		uint8_t *ledStatusArray;
		uint8_t totalLedNum;
		bool alreadyBeginCalled = false;
		void PutCharInArray(uint8_t WichChar, uint8_t WichDisplay = N_DISPLAYS_DFLT);
		// uint8_t **ledStatusArray;

};





#endif


