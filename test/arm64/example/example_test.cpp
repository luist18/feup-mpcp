#ifndef TEST_H_
#define TEST_H_

#include "../../../src/test/asserts.h"

extern "C" long example(long n);

using namespace asserts;

class example_test {
public:
	static void test1() {
		long n = 0;

		long expected = 0;
		long value = example(n);

		assert_eq<long>(expected, value);
	}

	static void test2() {
		long n = 2;

		long expected = 3;
		long value = example(n);

		assert_eq<long>(expected, value);
	}

	static void test3() {
		long n = 10;

		long expected = 55;
		long value = example(n);

		assert_eq<long>(expected, value);
	}
};

#endif
