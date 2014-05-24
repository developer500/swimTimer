/*
 * DisplayHelper.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Stuart
 */

#ifndef DISPLAYHELPER_H_
#define DISPLAYHELPER_H_



#include "DisplayPacket.h"

class DisplayHelper {
public:
	DisplayHelper();
	virtual ~DisplayHelper();

	// Takes a basic char array and converts it to an 8 byte only
	// representation for the 7219. Also outputs array of whether
	// a decimal point is required on that position.
	void convertCharArrayToDisplayPacket(char * inChars, DisplayPacket * inOutDP);
	bool isValid7219Char(char inChar);
	void intToRJustChar(int inInt, int inDP, char * outChars);

private:
	void padRemaining(int inOffset, DisplayPacket * inOutDP);
	int processCharacter(int inIndex, char * inChars, DisplayPacket * inOutDP, int inOffset);
};

#endif /* DISPLAYHELPER_H_ */
