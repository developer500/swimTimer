/*
 * TickHandler.h
 *
 *  Created on: May 21, 2014
 *      Author: Stuart
 */

#ifndef TICKHANDLER_H_
#define TICKHANDLER_H_

class TickHandler {
public:
	virtual ~TickHandler() {}
	virtual void handleTick() =0;
private:
	TickHandler();
protected:
};

#endif /* TICKHANDLER_H_ */
