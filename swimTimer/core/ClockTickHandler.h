/*
 * ClockTickHandler.h
 *
 *  Created on: May 21, 2014
 *      Author: Stuart
 */

#ifndef CLOCKTICKHANDLER_H_
#define CLOCKTICKHANDLER_H_

#include "TickHandler.h"

class ClockTickHandler: public TickHandler {
public:
	ClockTickHandler();
	virtual ~ClockTickHandler() {}
	void handleTick() { return; }
};

#endif /* CLOCKTICKHANDLER_H_ */
