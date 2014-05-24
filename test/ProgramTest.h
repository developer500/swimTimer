/*
 * ProgramTest.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Stuart
 */

#ifndef PROGRAMTEST_H_
#define PROGRAMTEST_H_

#include "UnitTest.h"
#include "..\SwimTimer\core\Program.h"

class ProgramTest: public UnitTest {
public:
	void runTest() {

		Program * testProgram = new Program();

		testProgram->addInterval(Interval::getInterval(10, 2));
		testProgram->addInterval(Interval::getInterval(30, 4));
		testProgram->addInterval(Interval::getInterval(10, 5));
		testProgram->addInterval(Interval::getPausedInterval(20));
		testProgram->addInterval(Interval::getInterval(60, 6));

		UT_ASSERT(testProgram->getIntervalCount()==5);
		UT_ASSERT(testProgram->getNonPausedIntervalCount()==4);

		Interval * interval = testProgram->getIntervalAtIndex(4);

		UT_ASSERT(interval->getSeconds()==60);
		UT_ASSERT(interval->getCount()==6);

		UT_ASSERT(testProgram->getNonPausedIntervalCountAtIndex(4)==3);
	}


};

#endif /* PROGRAMTEST_H_ */
