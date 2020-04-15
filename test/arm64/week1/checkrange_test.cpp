#ifndef TEST_H_
#define TEST_H_

#include "../../../src/test/asserts.h"

extern "C" int CheckRange(int lim, int tam, int *seq);

using namespace asserts;

class check_range_test {
public:
	static void example() {
		int edge = 20;
		int vec_size = 8;
		int ve[] = { 7, -8, -23, 56, 20, -10, 0, 40 };

		int expected = 3;
		int value = CheckRange(edge, vec_size, ve);

		assert_eq<int>(expected, value);
	}

	static void test1() {
		int edge = 0;
		int vec_size = 8;
		int ve[] = { 7, -8, -23, 56, 20, -10, 0, 40 };

		int expected = 7;
		int value = CheckRange(edge, vec_size, ve);

		assert_eq<int>(expected, value);
	}

	static void test2() {
		int edge = 50;
		int vec_size = 8;
		int ve[] = { 7, -8, -23, 56, 20, -10, 0, 40 };

		int expected = 1;
		int value = CheckRange(edge, vec_size, ve);

		assert_eq<int>(expected, value);
	}

	static void test3() {
		int edge = 8;
		int vec_size = 8;
		int ve[] = { 7, -8, -23, 56, 20, -10, 0, 40 };

		int expected = 5;
		int value = CheckRange(edge, vec_size, ve);

		assert_eq<int>(expected, value);
	}
};

#endif
