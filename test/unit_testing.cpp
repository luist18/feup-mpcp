#include "../src/test/tester.h"

#include "arm64/week5/freqchars_test.cpp"

/*
 * Include your cpp unit test files here and then add the static functions to
 * the tester class with class method add(function).
 */
class UnitTesting {
public:
	static void run() {
		Tester t;

		t.add(freqchars_test::example, "example");
		t.add(freqchars_test::test1, "test1");
		t.add(freqchars_test::test2, "test2");
		t.add(freqchars_test::test3, "test3");
		t.add(freqchars_test::test4, "test4");
		t.add(freqchars_test::test5, "test5");
		t.add(freqchars_test::test6, "test6");

		t.run();
	}
};
