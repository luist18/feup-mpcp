#ifndef CALCULATOR_TEST_H_
#define CALCULATOR_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" long int power(int base, int exp);

extern "C" int Calculator(unsigned int N, char *seq_OP, int *seq_B, int *seq_A);

using namespace asserts;

class calculator_test {
public:
	static void example() {
		int size = 4;

		char vec1[] = { '-', 'P', 'P', '+' };
		int vec2[] = { 1, 4, 3, 4 };
		int vec3[] = { 1, 0, 2, 4 };

		int value = Calculator(size, vec1, vec2, vec3);

		int res[] = { 0, 1, 9, 8 };
		assert_eq<int>(0, value);

		for (int i = 0; i < size; ++i) {
			assert_eq(vec2[i], res[i]);
		}
	}
};

#endif
