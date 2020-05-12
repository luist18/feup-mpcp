#ifndef WEEK4_TEST_H_
#define WEEK4_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" void eStep(unsigned int N, float *seq_P, unsigned int M,
		double *seq_C, unsigned int *seq_Out);

using namespace asserts;

class estep_test {
public:
	static void example() {
		unsigned int N = 5, M = 3;
		float seq_P[] = { -3.1, 0, 2.5, -2, 3, 2, 0.5, 1, -5, -1 };
		double seq_C[] = { -2, -2, 0, 0, 2, 2 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 0, 1, 2, 1, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test1() {
		unsigned int N = 5, M = 4;
		float seq_P[] = { -3.1, 0, 2.5, -2, 3, 2, 0.5, 1, -5, -1 };
		double seq_C[] = { -2, -2, 0, 0, 2, 2, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 0, 1, 2, 1, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test2() {
		unsigned int N = 5, M = 5;
		float seq_P[] = { -3.1, 0, 2.5, -2, 3, 2, 0.5, 1, -5, -1 };
		double seq_C[] = { 0, 0, -2, -2, 0, 0, 2, 2, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 0, 3, 0, 1 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test3() {
		unsigned int N = 5, M = 1;
		float seq_P[] = { -3.1, 0, 2.5, -2, 3, 2, 0.5, 1, -5, -1 };
		double seq_C[] = { 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 0, 0, 0, 0, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test4() {
		unsigned int N = 1, M = 1;
		float seq_P[] = { 0, 0 };
		double seq_C[] = { 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test5() {
		unsigned int N = 5, M = 3;
		float seq_P[] = { -3.1, 0, 2.5, -2, 3, 2, 0.5, 1, -5, -1 };
		double seq_C[] = { -2, -2, 0, 0, 2, 2 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 0, 1, 2, 1, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test6() {
		unsigned int N = 2, M = 2;
		float seq_P[] = { 0, 0, 2, 3 };
		double seq_C[] = { -10, -10, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 1 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test7() {
		unsigned int N = 2, M = 2;
		float seq_P[] = { 0, 0, -8, 1 };
		double seq_C[] = { -2, -2, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test8() {
		unsigned int N = 2, M = 2;
		float seq_P[] = { 0, 0, 1.5, 45.7 };
		double seq_C[] = { -10.1, -9.9, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 1 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test9() {
		unsigned int N = 2, M = 2;
		float seq_P[] = { 0, 0, -8.1, 0.5 };
		double seq_C[] = { -2, -2, 0, 0 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 0 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test10() {
		unsigned int N = 2, M = 3;
		float seq_P[] = { 0, 0, 10.5, 10.5 };
		double seq_C[] = { -2.123456789, -2.987654321, 0, 0, 10.123456789,
				10.987654321 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 2 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}

	static void test11() {
		unsigned int N = 2, M = 4;
		float seq_P[] = { 0, 0, 10.5, 10.5 };
		double seq_C[] = { -2.123456789, -2.987654321, 0, 0, 10.123456789,
				10.987654321, 3.4028234664e+40, 1.1754943508e-39 };
		unsigned int seq_Out[N];

		eStep(N, seq_P, M, seq_C, seq_Out);

		unsigned int expected[] = { 1, 2 };

		assert_vector_eq<unsigned int>(expected, seq_Out, N);
	}
};

#endif
