/*
 * Program.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Stuart
 */

#include "Program.h"

Program::Program() {
	intervalCount = 0;
	nonPausedIntervalCount = 0;
}

Program::~Program() {
	for (int intervalIndex = 0 ; intervalIndex < intervalCount; intervalIndex++) {
		IntervalWithCount * intervalWithCount = intervals[intervalIndex];
		delete (intervalWithCount->interval);
		delete (intervalWithCount);
	}
}

void Program::addInterval(Interval * inInterval) {

	IntervalWithCount * intervalWithCount = new(IntervalWithCount);

	intervalWithCount->interval = inInterval;
	intervalWithCount->intervalNumber = nonPausedIntervalCount;

	intervals[intervalCount] = intervalWithCount;
	intervalCount++;

	if (!inInterval->isPaused()) {
		nonPausedIntervalCount++;
	}
}

int Program::getNonPausedIntervalCountAtIndex(int inIndex) {

	return intervals[inIndex]->intervalNumber;
}

