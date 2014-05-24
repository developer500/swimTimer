#include <SPI.h>
#include <MAX7219.h>

// Do not remove the include below
#include "SwimTimer.h"

static MAX7219 max7219(10);

MAX7219::Characters getMax7219FromChar(char inChar) {

	switch (inChar) {
	case '0':
		return MAX7219::Character_Zero;
	case '1':
		return MAX7219::Character_One;
	case '2':
		return MAX7219::Character_Two;
	case '3':
		return MAX7219::Character_Three;
	case '4':
		return MAX7219::Character_Four;
	case '5':
		return MAX7219::Character_Five;
	case '6':
		return MAX7219::Character_Six;
	case '7':
		return MAX7219::Character_Seven;
	case '8':
		return MAX7219::Character_Eight;
	case '9':
		return MAX7219::Character_Nine;
	case '-':
		return MAX7219::Character_Dash;
	case 'E':
		return MAX7219::Character_E;
	case 'H':
		return MAX7219::Character_H;
	case 'L':
		return MAX7219::Character_L;
	case 'P':
		return MAX7219::Character_P;
	case ' ':
		return MAX7219::Character_Blank;
	default:
		return MAX7219::Character_Blank;
	}
}

//The setup function is called once at startup of the sketch
void setup() {
	// Initiliaze MAX7219.
	max7219.initialize();
	// Set scan limit.
	max7219.setScanLimit(MAX7219::ScanLimit_Digit0To7);
	// Set decode mode.
	max7219.setDecodeMode(MAX7219::DecodeMode_AllDigits);
	// Set intensity.
	max7219.setIntensity(MAX7219::Intensity_Level15);
	// Set shutdown mode.
	max7219.setShutdownMode(MAX7219::ShutdownMode_NormalOperation);

	for (int clearIndex = MAX7219::Digit_0; clearIndex <= MAX7219::Digit_7;
			clearIndex++) {
		MAX7219::Digits clearIndexDigit =
				static_cast<MAX7219::Digits>(clearIndex);

		max7219.writeDigit(clearIndexDigit, MAX7219::Character_Blank);
	}
}

// The loop function is called in an endless loop
void loop() {

	static int digit = MAX7219::Character_Zero;

	MAX7219::Characters digitChar = static_cast<MAX7219::Characters>(digit);

	max7219.writeDigit(MAX7219::Digit_0, digitChar);

	digit++;

	if (digit > MAX7219::Character_Nine) {
		digit = MAX7219::Character_Zero;
	}

	// Wait a little before next loop.
	delay(1000);
}
