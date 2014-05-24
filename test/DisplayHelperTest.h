/*
 * DisplayHelperTest.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Stuart
 */

#ifndef DISPLAYHELPERTEST_H_
#define DISPLAYHELPERTEST_H_

#include "UnitTest.h"
#include "..\SwimTimer\core\DisplayHelper.h"

class DisplayHelperTest: public UnitTest {
public:
	void testisValid7219Char() {
		DisplayHelper displayHelper;

		UT_ASSERT(displayHelper.isValid7219Char('A') == false);
		UT_ASSERT(displayHelper.isValid7219Char('b') == false);
		UT_ASSERT(displayHelper.isValid7219Char('0') == true);
		UT_ASSERT(displayHelper.isValid7219Char('9') == true);
		UT_ASSERT(displayHelper.isValid7219Char('-') == true);
		UT_ASSERT(displayHelper.isValid7219Char(' ') == true);
		UT_ASSERT(displayHelper.isValid7219Char('E') == true);
		UT_ASSERT(displayHelper.isValid7219Char('Q') == false);
	}

	void testconvertCharArrayToDisplay() {

		DisplayHelper displayHelper;

		const int displaySize = 8;
		bool decimals[displaySize];
		char display[displaySize + 1]; // +1 to account for the \n at the end

		DisplayPacket displayPacket;

		displayPacket.displayChars = display;
		displayPacket.hasDecimalPoint = decimals;

		const int columns = 3;
		const char *testArray[][columns] = {
				{ "12345678", "12345678", "        " },
				{ "123456  ", "123456  ", "        " },
				{ "12345", "12345   ", "        " },
				{ "1", "1       ", "        " },
				{ "", "        ", "        " },
				{ "123456789", "12345678", "        " },
				{ "EEEEEEEE", "EEEEEEEE", "        " },
				{ "1.2     ", "12      ", "1       " },
				{ "1.2 1.2 ", "12 12   ", "1  1    " },
				{ "2..", "2       ", "11     " },
				{ "2.......", "2       ", "1111111 " },
				{ "2........", "2       ", "11111111" },
				{ "12345678.", "12345678", "       1" }, //special case.
				{ "AAAAAAAA", "        ", "        " }
		};

		int rows = sizeof(testArray) / sizeof(*testArray);

		for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
			displayHelper.convertCharArrayToDisplayPacket(
					(char *) testArray[rowIndex][0], &displayPacket);

			UT_ASSERT(strcmp(displayPacket.displayChars, testArray[rowIndex][1])== 0);

			for (int dpIndex = 0; dpIndex < displaySize; dpIndex++) {
				bool expectedValue =
						testArray[rowIndex][2][dpIndex] == '1' ? true : false;

				UT_ASSERT(displayPacket.hasDecimalPoint[dpIndex]== expectedValue);
			}
		}
	}

	void testintToChar() {

		DisplayHelper displayHelper;

		const int displaySize = 8;
		char display[displaySize + 1]; // +1 to account for the \n at the end

		struct {
			int inputValue;
			int places;
			char * expected;
		} testArray[] = {
				{ 0, 3, "  0" } ,
				{ 1, 3, "  1" } ,
				{ 10, 3, " 10" } ,
				{ 100, 3, "100" } ,
				{ 1000, 3, "000" } ,
				{ -1, 3, " -1" } ,
				{ -10, 3, "-10" } ,
				{ -100, 3, "100" } ,
				{ -1000, 3, "000" }
		};

		int rows = sizeof(testArray) / sizeof(*testArray);
		for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
			strcpy(display, "");
			displayHelper.intToRJustChar(testArray[rowIndex].inputValue, testArray[rowIndex].places, display);

			UT_ASSERT(strcmp(testArray[rowIndex].expected, display)== 0);
		}
	}

};

#endif /* DISPLAYHELPERTEST_H_ */
