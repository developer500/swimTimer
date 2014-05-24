/*
 * DisplayHelper.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Stuart
*/

#include "DisplayHelper.h"

#ifdef __GNUC__
#include <stdlib.h>
#endif

#include <string.h>

DisplayHelper::DisplayHelper() {
	// TODO Auto-generated constructor stub

}

DisplayHelper::~DisplayHelper() {
	// TODO Auto-generated destructor stub
}

bool DisplayHelper::isValid7219Char(char inChar) {

	if ((inChar >= '0') && (inChar <= '9')) {
		return true;
	}

	const char otherValid[] = "-EHLP ";

	for (int i = 0; otherValid[i] != '\0'; i++) {
		if (inChar == otherValid[i]) {
			return true;
		}
	}

	return false;
}

const int maxDisplaySize = 8;

int DisplayHelper::processCharacter(int inIndex, char * inChars,
		DisplayPacket * inOutDP, int inOffset) {

	if (inChars[inIndex] == '.') {
		if ((inIndex > 1) && (inChars[inIndex - 1] == '.')) {
			// consecutive dps - set a space.
			inOutDP->displayChars[inOffset] = ' ';
			inOffset++;
		}
		if (inIndex > 0) {
			// not possible to set a . on the 1st in char hence inIndex > 0
			inOutDP->hasDecimalPoint[inOffset - 1] = true;
		}
		return inOffset;
	}

	inOutDP->displayChars[inOffset] =
			isValid7219Char(inChars[inIndex]) ? inChars[inIndex] : ' ';

	inOutDP->hasDecimalPoint[inOffset] = false;

	inOffset++;
	return inOffset;

}

void DisplayHelper::convertCharArrayToDisplayPacket(char * inChars,
		DisplayPacket * inOutDP) {

	int outOffset = 0;
	for (int i = 0; inChars[i] != '\0'; i++) {
		outOffset = processCharacter(i, inChars, inOutDP, outOffset);

		if (outOffset == maxDisplaySize) {
			// special case of last character being .
			if (inChars[i+1] == '.') {
				inOutDP->hasDecimalPoint[outOffset - 1] = true;
			}
			break;
		}
	}

	padRemaining(outOffset, inOutDP);
}

void DisplayHelper::padRemaining(int inOffset, DisplayPacket * inOutDP) {

	for (; inOffset < maxDisplaySize; inOffset++) {
		inOutDP->displayChars[inOffset] = ' ';
		inOutDP->hasDecimalPoint[inOffset] = false;
	}
	inOutDP->displayChars[maxDisplaySize] = '\0';
}

void DisplayHelper::intToRJustChar(int inInt, int inDP, char * outChars) {

	static char temp[10];
	*temp = '\0';
	itoa(inInt, temp, 10);
	int tempIndex = strlen(temp) - 1;

	outChars[inDP] = '\0';
	inDP--;

	for (; inDP >=0 ; inDP--) {
		outChars[inDP] = (tempIndex >= 0) ? temp[tempIndex] : ' ';
		tempIndex--;
	}
}

