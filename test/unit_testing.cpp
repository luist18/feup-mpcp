#include "../src/test/tester.h"

#include "arm64/week4/estep_test.cpp"
#include "arm64/simd/simd_test.cpp"

/*
 * Include your cpp unit test files here and then add the static functions to
 * the tester class with class method add(function).
 */
class UnitTesting {
public:
	static void run() {
		Tester t;

		t.add(estep_test::example);
		t.add(estep_test::test1);
		t.add(estep_test::test2);
		t.add(estep_test::test3);
		t.add(estep_test::test4);
		t.add(estep_test::test5);
		t.add(estep_test::test6);
		t.add(estep_test::test7);
		t.add(estep_test::test8);
		t.add(estep_test::test9);
		t.add(estep_test::test10);
		t.add(estep_test::test11);

		t.run();
	}
};
