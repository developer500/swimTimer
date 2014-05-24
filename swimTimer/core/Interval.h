/*
 * Interval.h
 *
 *  Created on: Apr 10, 2014
 *      Author: Stuart
 */

#ifndef INTERVAL_H_
#define INTERVAL_H_

class Interval {
public:
	static Interval * getInterval(int inSeconds , int inCount) {
		return new Interval(inSeconds, inCount, false);
	};

	static Interval * getPausedInterval(int inSeconds) {
		return new Interval(inSeconds, 1, true);
	};

	bool decrementCounters();
	bool isAtEnd();
	int getSeconds() {return seconds;}
	int getCount() {return count;}
	bool isPaused() {return isPausedInterval;}

protected:
	Interval(int inSeconds, int inCount, bool isPaused);

private:
	void decrement();
	int initialSeconds;
	int seconds;
	int count;
	bool isPausedInterval;
};

#endif /* INTERVAL_H_ */
