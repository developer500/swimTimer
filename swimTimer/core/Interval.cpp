/*
 * Interval.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Stuart
 */

#include "interval.h"

Interval::Interval(int inSeconds, int inCount, bool inIsPaused) {

	seconds = inSeconds;
	initialSeconds = inSeconds;
	count = inCount;
	isPausedInterval = inIsPaused;
}

bool Interval::isAtEnd() {

	if ((seconds==0) && (count==0)) {
		return true;
	}

	return false;
}

bool Interval::decrementCounters() {

	decrement();
	return isAtEnd();
}

void Interval::decrement() {

	if (seconds > 1) {
		seconds--;
		return;
	}

	if (count > 0) {
		count--;
	}

	if (count!=0) {
		seconds=initialSeconds;
	} else {
		seconds=0;
	}

	return;
}

