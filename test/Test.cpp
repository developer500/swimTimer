/*
 * Test.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: Stuart
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "IntervalTest.h"
#include "DisplayHelperTest.h"
#include "ProgramTest.h"

using namespace std;

int main() {
	IntervalTest intervalTest;
	intervalTest.testCounters();

	DisplayHelperTest displayHelperTest;
	displayHelperTest.testisValid7219Char();
	displayHelperTest.testconvertCharArrayToDisplay();
	displayHelperTest.testintToChar();

	ProgramTest programTest;
	programTest.runTest();

	return 0;
}
