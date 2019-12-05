/*Libreria per la gestione di tre digit fatti di led e shift register*/
#include "OneDigitsLeds.h"


#define MIN_NUM_SHIFT_REG	1
#define EXIT_NUMBER	        8
#define MAX_ODG			   20

typedef enum 
{
	TOP = 0,
	RIGHT_TOP,
	RIGHT_BOTTOM,
	BOTTOM,
	LEFT_BOTTOM,
	LEFT_TOP,
	MIDDLE,
	DOT,
	MAX_LEDS_POS
}LEDS_POSITION;

typedef struct 
{
	int32_t Odg;
	uint8_t NDigit;
}ODG_DIGIT;

ODG_DIGIT Odg[MAX_ODG]
{
	{-1000000000, 11},
	{-100000000,  10},
	{-10000000,    9},
	{-1000000,     8},
	{-100000,      7},
	{-10000,       6},
	{-1000,        5},
	{-100,         4},
	{-10,          3},
	{-1,           2},
	{0,            1},
	{10,           2},
	{100,          3},
	{1000,         4},
	{10000,        5},
	{100000,       6},
	{1000000,      7},
	{10000000,     8},
	{100000000,    9},
	{1000000000,  10}
};

const uint8_t ZeroChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 1, 1, 0, 0
};
const uint8_t OneChar[EXIT_NUMBER] = 
{
	0, 1, 1, 0, 0, 0, 0, 0
};
const uint8_t TwoChar[EXIT_NUMBER] = 
{
	1, 1, 0, 1, 1, 0, 1, 0
};
const uint8_t ThreeChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 0, 0, 1, 0
};
const uint8_t FourChar[EXIT_NUMBER] = 
{
	0, 1, 1, 0, 0, 1, 1, 0
};
const uint8_t FiveChar[EXIT_NUMBER] = 
{
	1, 0, 1, 1, 0, 1, 1, 0
};
const uint8_t SixChar[EXIT_NUMBER] = 
{
	1, 0, 1, 1, 1, 1, 1, 0
};
const uint8_t SevenChar[EXIT_NUMBER] = 
{
	1, 1, 1, 0, 0, 0, 0, 0
};
const uint8_t EightChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 1, 1, 1, 0
};
const uint8_t NineChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 0, 1, 1, 0
};
const uint8_t MinusChar[EXIT_NUMBER] = 
{
	0, 0, 0, 0, 0, 0, 1, 0
};
const uint8_t GradeChar[EXIT_NUMBER] = 
{
	1, 1, 0, 0, 0, 1, 1, 0
};
const uint8_t DotChar[EXIT_NUMBER] = 
{
	0, 0, 0, 0, 0, 0, 0, 1
};
const uint8_t ZeroDotChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 1, 1, 0, 1
};
const uint8_t OneDotChar[EXIT_NUMBER] = 
{
	0, 1, 1, 0, 0, 0, 0, 1
};
const uint8_t TwoDotChar[EXIT_NUMBER] = 
{
	1, 1, 0, 1, 1, 0, 1, 1
};
const uint8_t ThreeDotChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 0, 0, 1, 1
};
const uint8_t FourDotChar[EXIT_NUMBER] = 
{
	0, 1, 1, 0, 0, 1, 1, 1
};
const uint8_t FiveDotChar[EXIT_NUMBER] = 
{
	1, 0, 1, 1, 0, 1, 1, 1
};
const uint8_t SixDotChar[EXIT_NUMBER] = 
{
	1, 0, 1, 1, 1, 1, 1 ,1
};
const uint8_t SevenDotChar[EXIT_NUMBER] = 
{
	1, 1, 1, 0, 0, 0, 0 ,1
};
const uint8_t EightDotChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 1, 1, 1 ,1
};
const uint8_t NineDotChar[EXIT_NUMBER] = 
{
	1, 1, 1, 1, 0, 1, 1 ,1
};
const uint8_t ClearDisplay[EXIT_NUMBER] = 
{
	0, 0, 0, 0, 0, 0, 0, 0
};

const uint8_t *CharacterLedDescriptor[MAX_CHARATERS] = 
{
	ZeroChar,
	OneChar,
	TwoChar,
	ThreeChar,
	FourChar,
	FiveChar,
	SixChar,
	SevenChar,
	EightChar,
	NineChar,
	MinusChar,
	GradeChar,
	DotChar,
	ZeroDotChar,
	OneDotChar,
	TwoDotChar,
	ThreeDotChar,
	FourDotChar,
	FiveDotChar,
	SixDotChar,
	SevenDotChar,
	EightDotChar,
	NineDotChar,
	ClearDisplay
};

SHIFTY_REG ShiftyReg;

void ODL::PutCharInArray(uint8_t WichChar, uint8_t WichDisplay)
{
	if(WichDisplay > 0)
		WichDisplay--;
	for(int i = 0; i < EXIT_NUMBER; i++)
	{
		ledStatusArray[i + (WichDisplay * EXIT_NUMBER)] = CharacterLedDescriptor[WichChar][i];
	}	
}

void ODL::setDataPin(uint8_t DataPin)
{
	dataPin = DataPin;
	if(alreadyBeginCalled)
	{
		uint8_t OutputEnablePin = OUT_PUT_EN_DFLT, ClearRegPin = CLEAR_REG_PIN_DFLT;
		ShiftyReg.begin(dataPin, clockPin, latchPin, OutputEnablePin, ClearRegPin, EXIT_NUMBER * numberOfDisplay, MIN_NUM_SHIFT_REG * numberOfDisplay);
	}
}
void ODL::setClockPin(uint8_t ClockPin)
{
	clockPin = ClockPin;
	if(alreadyBeginCalled)
	{
		uint8_t OutputEnablePin = OUT_PUT_EN_DFLT, ClearRegPin = CLEAR_REG_PIN_DFLT;
		ShiftyReg.begin(dataPin, clockPin, latchPin, OutputEnablePin, ClearRegPin, EXIT_NUMBER * numberOfDisplay, MIN_NUM_SHIFT_REG * numberOfDisplay);
	}
}
void ODL::setLatchPin(uint8_t LatchPin)
{
	latchPin = LatchPin;
	if(alreadyBeginCalled)
	{
		uint8_t OutputEnablePin = OUT_PUT_EN_DFLT, ClearRegPin = CLEAR_REG_PIN_DFLT;
		ShiftyReg.begin(dataPin, clockPin, latchPin, OutputEnablePin, ClearRegPin, EXIT_NUMBER * numberOfDisplay, MIN_NUM_SHIFT_REG * numberOfDisplay);
	}
}
void ODL::setComPins(uint8_t DataPin, uint8_t ClockPin, uint8_t LatchPin)
{
	dataPin = DataPin;
	clockPin = ClockPin;
	latchPin = LatchPin;
	if(alreadyBeginCalled)
	{
		uint8_t OutputEnablePin = OUT_PUT_EN_DFLT, ClearRegPin = CLEAR_REG_PIN_DFLT;
		ShiftyReg.begin(dataPin, clockPin, latchPin, OutputEnablePin, ClearRegPin, EXIT_NUMBER * numberOfDisplay, MIN_NUM_SHIFT_REG * numberOfDisplay);
	}	
}

void ODL::beginDisplays (uint8_t NumOfDisplay)
{
	uint8_t OutputEnablePin = OUT_PUT_EN_DFLT, ClearRegPin = CLEAR_REG_PIN_DFLT;
	ShiftyReg.begin(dataPin, clockPin, latchPin, OutputEnablePin, ClearRegPin, EXIT_NUMBER * NumOfDisplay, MIN_NUM_SHIFT_REG * NumOfDisplay);
	numberOfDisplay = NumOfDisplay;
	totalLedNum = EXIT_NUMBER * numberOfDisplay;
	ledStatusArray = new uint8_t [totalLedNum];
	if(!alreadyBeginCalled)
	{
#ifdef DEBUG
		Serial.begin(9600);
#endif		
	}
	alreadyBeginCalled = true;
	// ledStatusArray = new uint8_t*[EXIT_NUMBER];
	// for(int i = 0; i < EXIT_NUMBER; ++i)
 //    	ledStatusArray[i] = new uint8_t[numberOfDisplay];
} 

void ODL::drawChar(uint8_t WichChar, uint8_t WichDisplay)
{
	if(WichDisplay > numberOfDisplay)
	{
		DBG(MSG_MAX_CHAR("drawChar"));
		return;
	}
	// memset(ledStatusArray, 0x00, sizeof(uint8_t) * EXIT_NUMBER * numberOfDisplay);

	PutCharInArray(WichChar, WichDisplay);
	ShiftyReg.setAllExit(ledStatusArray);
	ShiftyReg.loadAllExit();
}

void ODL::drawChar(char WichChar, uint8_t WichDisplay)
{
	uint8_t WichCharNum = 0;
	if(WichDisplay > numberOfDisplay)
	{
		DBG(MSG_MAX_CHAR("drawChar + char"));
		return;
	}

	switch(WichChar)
	{
		case '0':
			WichCharNum = ZERO;
			break;
		case '1':
			WichCharNum = UNO;
			break;
		case '2':
			WichCharNum = DUE;
			break;
		case '3':
			WichCharNum = TRE;
			break;
		case '4':
			WichCharNum = QUATTRO;
			break;
		case '5':
			WichCharNum = CINQUE;
			break;
		case '6':
			WichCharNum = SEI;
			break;
		case '7':
			WichCharNum = SETTE;
			break;
		case '8':
			WichCharNum = OTTO;
			break;
		case '9':
			WichCharNum = NOVE;
			break;																											
		case '-':
			WichCharNum = MENO;
			break;
		case '°':
			WichCharNum = GRADI;
			break;
		case '.':
			WichCharNum = PUNTO;
			break;	
		default:
			WichCharNum = CLEAR;
			break;
	}

	PutCharInArray(WichCharNum, WichDisplay);
	ShiftyReg.setAllExit(ledStatusArray);
	ShiftyReg.loadAllExit();
}

void ODL::drawChar(const char *WichCharPtr, uint8_t WichDisplay)
{
	char CharDotted = '0';
	uint8_t WichCharNum = 0;
	String WichChar = String(WichCharPtr);
	if(WichChar.length() > WichDisplay + 1)
	{
		DBG(MSG_MAX_CHAR("drawChar + char ptr"));
		return;
	}
	if((WichChar.indexOf('.') > 0 || WichChar.indexOf(',') > 0) && WichChar.length() == 2)
	{
		if(WichChar.indexOf('.') > 0 )
			CharDotted = WichChar.charAt(WichChar.indexOf('.') - 1);
		if(WichChar.indexOf(',') > 0)
			CharDotted = WichChar.charAt(WichChar.indexOf(',') - 1);
		switch(CharDotted)
		{
			case '0':
				WichCharNum = ZERO_PUNTO;
				break;
			case '1':
				WichCharNum = UNO_PUNTO;
				break;
			case '2':
				WichCharNum = DUE_PUNTO;
				break;
			case '3':
				WichCharNum = TRE_PUNTO;
				break;
			case '4':
				WichCharNum = QUATTRO_PUNTO;
				break;
			case '5':
				WichCharNum = CINQUE_PUNTO;
				break;
			case '6':
				WichCharNum = SEI_PUNTO;
				break;
			case '7':
				WichCharNum = SETTE_PUNTO;
				break;
			case '8':
				WichCharNum = OTTO_PUNTO;
				break;
			case '9':
				WichCharNum = NOVE_PUNTO;
				break;																											
			default:
				WichCharNum = CLEAR;
				break;
		}	
		PutCharInArray(WichCharNum, WichDisplay);
		ShiftyReg.setAllExit(ledStatusArray);
		ShiftyReg.loadAllExit();
	}
	else
		return;
}

void ODL::drawNumber(int16_t Number)
{
	uint8_t HowManyChar = 0;
	String NumToStr = "";
	for(int i = 0; i < MAX_ODG; i++)
	{
		if(Number < Odg[i].Odg)
		{
			HowManyChar = Odg[i - 1].NDigit;
			break;
		}
	}
	if(HowManyChar > numberOfDisplay)
	{
		DBG(MSG_MAX_CHAR("drawNumber + int"));
		return;
	}
	else
	{
		NumToStr = String(Number);
		char NumberInChar[HowManyChar];
		NumToStr.toCharArray(NumberInChar, HowManyChar);
		for(int i = 0; i < HowManyChar; i++)
		{
			drawChar(NumberInChar[i], i + 1);
		}
	}
}

void ODL::drawNumber(float Number)
{
	uint8_t HowManyChar = 0;
	String NumToStr = "";
	NumToStr = String(Number);
	if(NumToStr.indexOf('.') > 0 ||  NumToStr.indexOf(',') > 0 )
	{
		HowManyChar = NumToStr.length() - 1;
		if(HowManyChar > numberOfDisplay)
		{
			DBG(MSG_MAX_CHAR("drawNumber + float"));
			return;
		}
		else
		{
			char NumToChar[HowManyChar];
			NumToStr.toCharArray(NumToChar, HowManyChar);
			for(int i = 0; i < HowManyChar;)
			{
				if(NumToChar[i + 1] == '.' || NumToChar[i + 1] == ',')
				{
					String CharDot = String(NumToChar[i]) + String(NumToChar[i + 1]);
					drawChar(CharDot.c_str(), i + 1);
					i += 2;
				}
				else
				{
					drawChar(NumToChar[i], i + 1);
					i++;
				}
			}
		}
	}
}

void ODL::ClearDisplay(uint8_t WichDisplay)
{
	memset(ledStatusArray, 0x00, sizeof(uint8_t) * totalLedNum);
	ShiftyReg.setAllExit(ledStatusArray);
	ShiftyReg.loadAllExit();
}