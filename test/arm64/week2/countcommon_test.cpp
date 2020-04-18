#ifndef COUNTCOMMON_TEST_H_
#define COUNTCOMMON_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" unsigned int CountCommon(unsigned int N, int *seq_A, unsigned int M,
		int *seq_B);

using namespace asserts;

class count_common_test {
public:
	static void example() {
		unsigned int sizeA = 8, sizeB = 3;

		int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7 };
		int vecB[] = { 5, 7, -2 };

		unsigned int expected = 4;
		unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

		assert_eq<int>(expected, value);
	}

	static void test1() {
		unsigned int sizeA = 8, sizeB = 3;

		int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7 };
		int vecB[] = { 99, 100, 101 };

		unsigned int expected = 0;
		unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

		assert_eq<int>(expected, value);
	}

	static void test2() {
		unsigned int sizeA = 8, sizeB = 4;

		int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7 };
		int vecB[] = { 5, 7, -2, -5 };

		unsigned int expected = 6;
		unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

		assert_eq<int>(expected, value);
	}

	static void test3() {
		unsigned int sizeA = 8, sizeB = 5;

		int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7 };
		int vecB[] = { -8, -5, -2, 7, 40 };

		unsigned int expected = 8;
		unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

		assert_eq<int>(expected, value);
	}

	static void test4() {
		unsigned int sizeA = 9, sizeB = 5;

		int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7, -7 };
		int vecB[] = { -8, -5, -2, 7, 40 };

		unsigned int expected = 8;
		unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

		assert_eq<int>(expected, value);
	}

	static void test5() {
			unsigned int sizeA = 10, sizeB = 6;

			int vecA[] = { 7, -8, -5, -2, -5, -2, 40, 7, -7, -2147483648 };
			int vecB[] = { -8, -5, -2, -2147483648, 7, 40 };

			unsigned int expected = 9;
			unsigned int value = CountCommon(sizeA, vecA, sizeB, vecB);

			assert_eq<int>(expected, value);
		}
};

#endif
