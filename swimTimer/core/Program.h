/*
 * Program.h
 *
 *  Created on: May 4, 2014
 *      Author: Stuart
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "Interval.h"

struct IntervalWithCount {
	Interval * interval;
	int intervalNumber;
};

class Program {
public:
	Program();
	virtual ~Program();
	void addInterval(Interval * inInterval);
	int getIntervalCount() {
		return intervalCount;
	}
	int getNonPausedIntervalCount() {
		return nonPausedIntervalCount;
	}

	Interval * getIntervalAtIndex(int inIndex) {return intervals[inIndex]->interval;}

	int getNonPausedIntervalCountAtIndex(int inIndex);

private:
	IntervalWithCount * intervals[100];
	int intervalCount;
	int nonPausedIntervalCount;
};

#endif /* PROGRAM_H_ */
