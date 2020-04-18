#ifndef REVERSE_STRING_TEST_H_
#define REVERSE_STRING_TEST_H_

#include "../../../src/test/asserts.h"
#include <string.h>

extern "C" int reverse_string(char *string);

using namespace asserts;

class reverse_string_test {
public:
	static void test1() {
		char string[] = "total banter";

		printf("%s\n", string);

		reverse_string(string);

		printf("%s\n", string);
	}
};

#endif
