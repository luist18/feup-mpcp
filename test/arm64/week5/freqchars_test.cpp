#ifndef WEEK5_TEST_H_
#define WEEK5_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" char freqchars(unsigned int N, char *text, char nl, char *lett,
		float *freq);

using namespace asserts;

class freqchars_test {
public:
	static void example() {
		unsigned int N = 48;
		char text[] = "A funcao retorna a frequencia absoluta da letra ";
		char nl = 4;
		char lett[] = { 'p', 'a', 'u', 'r' };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>('a', res);

		float expected[] = { 0.0f * 100.0f, 9.0f * 100.0f / 48.0f, 3.0f * 100.0f
				/ 48.0f, 4.0f * 100.0f / 48.0f };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test1() {
		unsigned int N = 48;
		char text[] = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccc";
		char nl = 3;
		char lett[] = { 'a', 'b', 'c' };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>('a', res);

		float expected[] = { 16.0f * 100.0f / 48.0f, 16.0f * 100.0f / 48.0f,
				16.0f * 100.0f / 48.0f };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test2() {
		unsigned int N = 48;
		char text[] = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccc";
		char nl = 3;
		char lett[] = { 'p', 'e', 'f' };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>(0, res);

		float expected[] = { 0.0f, 0.0f, 0.0f };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test3() {
		unsigned int N = 48;
		char text[] = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccc";
		char nl = 0;
		char lett[] = { };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>(0, res);

		float expected[] = { };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test4() {
		unsigned int N = 0;
		char text[] = "";
		char nl = 0;
		char lett[] = { };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>(0, res);

		float expected[] = { };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test5() {
		unsigned int N = 0;
		char text[] = "";
		char nl = 3;
		char lett[] = { 'd', 'e', 'f' };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>(0, res);

		float expected[] = { 0.0f, 0.0f, 0.0f };

		assert_vector_eq<float>(expected, freq, nl);
	}

	static void test6() {
		unsigned int N = 48;
		char text[] = "era uma vez um cuco que gostava de couves lololo";
		char nl = 6;
		char lett[] = { ' ', 'o', 'e', 'm', 'u', 'y' };
		float freq[nl];

		char res = freqchars(N, text, nl, lett, freq);

		assert_eq<char>(' ', res);

		float expected[] = { 9.0f * 100.0f / 48.0f, 6.0f * 100.0f / 48.0f, 5.0f
				* 100.0f / 48.0f, 2.0f * 100.0f / 48.0f, 5.0f * 100.0f / 48.0f,
				0.0f };

		assert_vector_eq<float>(expected, freq, nl);
	}
};

#endif
