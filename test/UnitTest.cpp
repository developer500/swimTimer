/*
 * UnitTest.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: Stuart
 */

#include <stdio.h>
#include <stdlib.h>
#include "UnitTest.h"

int UnitTest::num_test_success = 0;

void UnitTest::assertTrue(bool condition, const char *file,
			int line, const char *msg) {

	if (!(condition)) {
		printf("FAILURE!\n");
		printf("%s:%d:%s\n", file , line, msg);
		exit(1);
	}
	++num_test_success;
}
