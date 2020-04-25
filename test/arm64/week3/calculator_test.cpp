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
		int vec2[] = { 1, 0, 2, 4 };
		int vec3[] = { 1, 4, 3, 4 };

		int value = Calculator(size, vec1, vec2, vec3);

		int res[] = { 0, 1, 9, 8 };
		assert_eq<int>(0, value);

		for (int i = 0; i < size; ++i) {
			assert_eq<int>(res[i], vec3[i]);
		}
	}

	static void test1() {
		unsigned int size = 6;
		int vectA[] = { 13, 2, 8, 4, 5, 25 };
		int vectB[] = { 9, 2, 3, 0, 1, -25 }; // com overflow : exemplo (a)
		// int vectB[] = {1, 2, 3, 0, 1, -25}; // sem overflow  : exemplo (b);
		char vectOP[] = { 'P', '+', 'P', '*', '-', '+' };

		int value = Calculator(size, vectOP, vectB, vectA);

		assert_eq<int>(1, value);
	}

	static void test2() {
		int size = 6;
		int vectA[] = { 13, 2, 8, 4, 5, 25 };
		int vectB[] = { 1, 2, 3, 0, 1, -25 }; // sem overflow  : exemplo (b);
		char vectOP[] = { 'P', '+', 'P', '*', '-', '+' };

		int vectC[] = { 13, 4, 512, 0, 4, 0 };

		int value = Calculator(size, vectOP, vectB, vectA);

		assert_eq<int>(0, value);

		for (int i = 0; i < size; ++i) {
			assert_eq<int>(vectA[i], vectC[i]);
		}
	}

	static void test3() {
		int size = 5;
		int vec1[] = { 9, 4, 7, -1, 4 };
		int vec2[] = { -9, 5, 8, 0, 1 };
		char vec3[] = { '-', 'P', '*', 'P', '+' };

		int res[] = { 18, 1024, 56, 1, 5 };

		int value = Calculator(size, vec3, vec2, vec1);

		assert_eq<int>(0, value);

		for (int i = 0; i < size; ++i) {
			assert_eq<int>(vec1[i], res[i]);
		}
	}

	static void test4() {
		int size = 5;
		int vec1[] = { 9, 1, 7, -1, 4 };
		int vec2[] = { -9, 2147483647, 8, 0, 1 };
		char vec3[] = { '-', '+', '*', 'P', '+' };

		int res[] = { 18, 1024, 56, 0, 5 };

		int value = Calculator(size, vec3, vec2, vec1);

		assert_eq<int>(2, value);

		for (int i = 0; i < value - 1; ++i) {
			assert_eq<int>(vec1[i], res[i]);
		}
	}

	static void test5() {
		int size = 5;
		int vec1[] = { 9, -2147483648, 7, -1, 4 };
		int vec2[] = { -9, 1, 8, 0, 1 };
		char vec3[] = { '-', '-', '*', 'P', '+' };

		int res[] = { 18, 1024, 56, 0, 5 };

		int value = Calculator(size, vec3, vec2, vec1);

		assert_eq<int>(2, value);

		for (int i = 0; i < value - 1; ++i) {
			assert_eq<int>(vec1[i], res[i]);
		}
	}

	static void test6() {
		int size = 5;
		int vec1[] = { 9, 20, 7, -1, 4 };
		int vec2[] = { -9, 8, 8, 0, 1 };
		char vec3[] = { '-', 'P', '*', 'P', '+' };

		int res[] = { 18, 1024, 56, 0, 5 };

		int value = Calculator(size, vec3, vec2, vec1);

		assert_eq<int>(2, value);

		for (int i = 0; i < value - 1; ++i) {
			assert_eq<int>(vec1[i], res[i]);
		}
	}

	static void test7() {
		int size = 5;
		int vec1[] = { 9, 2147482641, 7, -1, 4 };
		int vec2[] = { -9, 8, 8, 0, 1 };
		char vec3[] = { '-', '*', '*', 'P', '+' };

		int res[] = { 18, 1024, 56, 0, 5 };

		int value = Calculator(size, vec3, vec2, vec1);

		assert_eq<int>(2, value);

		for (int i = 0; i < value - 1; ++i) {
			assert_eq<int>(vec1[i], res[i]);
		}
	}

	static void test8() {
		int size = 4;

		char vec1[] = { '-', 'P', 'P', '+' };
		int vec2[] = { 1, 33, 0, 4 };
		int vec3[] = { 1, -2, 3, 4 };

		int value = Calculator(size, vec1, vec2, vec3);

		assert_eq<int>(2, value);
	}

	static void test9() {
		int size = 4;

		char vec1[] = { '-', 'P', 'P', '+' };
		int vec2[] = { 1, 1, 0, 2147483647 };
		int vec3[] = { 1, -2, 3, 1 };

		int value = Calculator(size, vec1, vec2, vec3);

		assert_eq<int>(4, value);
	}

	static void test10() {
		int size = 4;

		char vec1[] = { '-', '+', 'P', '*' };
		int vec2[] = { 0, 0, 0, 0 };
		int vec3[] = { 0, 0, 0, 0 };

		int value = Calculator(size, vec1, vec2, vec3);

		int res[] = { 0, 0, 1, 0 };
		assert_eq<int>(0, value);

		for (int i = 0; i < size; ++i) {
			assert_eq<int>(res[i], vec3[i]);
		}
	}
};

#endif
