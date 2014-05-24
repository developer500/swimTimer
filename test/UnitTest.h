/*
 * UnitTest.h
 *
 *  Created on: Apr 17, 2014
 *      Author: Stuart
 */

#ifndef UNITTEST_H_
#define UNITTEST_H_

#define UT_ASSERT( condition ) \
	assertTrue(condition, __FILE__,__LINE__,#condition)

class UnitTest {
public:
	virtual ~UnitTest() {}
protected:
	void assertTrue(bool condition, const char *file,
			int line, const char *msg);
	static int num_test_success;
};

#endif /* UNITTEST_H_ */
