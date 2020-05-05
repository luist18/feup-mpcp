#ifndef FP_TEST_H_
#define FP_TEST_H_

#include "../../../src/test/asserts.h"

using namespace asserts;

extern "C" long interval_counter(float *V, long int n, float a, float b);

extern "C" double internal_product(float *X, float *Y, int n);

extern "C" double cosx(double x);

extern "C" double func_cosx(double x);

class floatingpoint_test {
public:
	static void example() {
		double value = func_cosx(45);

		double expected = 0.70710;

		assert_eq<double>(expected, value);
	}
};

#endif
