#include "../src/test/tester.h"
#include "arm64/example/example_test.cpp"

/*
 * Include your cpp unit test files here and then add the static functions to
 * the tester class with class method add(function).
 */
class UnitTesting {
public:
	static void run() {
		Tester t;

		t.add(example_test::test1);
		t.add(example_test::test2);
		t.add(example_test::test3);

		t.run();
	}
};
