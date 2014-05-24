/*
 * IntervalTest.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Stuart
 */

#ifndef INTERVALTEST_H_
#define INTERVALTEST_H_

#include "UnitTest.h"
#include "..\SwimTimer\core\Interval.h"

class IntervalTest: public UnitTest {
public:
	void runTest() {
		Interval * testinterval = Interval::getInterval(10, 10);
		UT_ASSERT(testinterval->decrementCounters() == false);
		delete(testinterval);
	}

	void testCounters() {

		Interval * testinterval = Interval::getInterval(3,3);

		struct ExpectedValues {
			int expectedSeconds;
			int expectedCount;
		};
		ExpectedValues expectedValues[] = { 3, 3, 2, 3, 1, 3, 3, 2, 2, 2, 1, 2,
				3, 1, 2, 1, 1, 1, 0, 0 };

		ExpectedValues * expectedValue = &expectedValues[0];

		// Initial values
		UT_ASSERT(testinterval->getSeconds() == expectedValue->expectedSeconds);
		UT_ASSERT(testinterval->getCount() == expectedValue->expectedCount);

		do {
			testinterval->decrementCounters();
			expectedValue++;
			UT_ASSERT(testinterval->getSeconds() == expectedValue->expectedSeconds);
			UT_ASSERT(testinterval->getCount() == expectedValue->expectedCount);
		} while (!testinterval->isAtEnd());

		// test going off the bottom
		testinterval->decrementCounters();
		UT_ASSERT(testinterval->getSeconds() == 0);
		UT_ASSERT(testinterval->getCount() == 0);

		delete(testinterval);
	}
};

#endif /* INTERVALTEST_H_ */
