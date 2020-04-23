#ifndef FP_TEST_H_
#define FP_TEST_H_

#include "../../../src/test/asserts.h"

using namespace asserts;

extern "C" double internal_product(float *X, float *Y, int n);

class floatingpoint_test {
public:
	static void example() {
		int size = 3;

		float a[] = {3.5, 0.9, -2.1};

		float b[] = {4.3, 0.1, 3.7};

		double expected = 3.5 * 4.3 + 0.9 * 0.1 + -2.1 * 3.7;

		double value = internal_product(a, b, size);

		assert_eq<double>(expected, value);
	}
};

#endif
