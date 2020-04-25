#include "../src/test/tester.h"
#include "arm64/week1/checkrange_test.cpp"
#include "arm64/week2/countcommon_test.cpp"
#include "arm64/stack_exercises/reversestring_test.cpp"
#include "arm64/week3/calculator_test.cpp"
#include "arm64/floating_point/floatingpoint_test.cpp"

/*
 * Include your cpp unit test files here and then add the static functions to
 * the tester class with class method add(function).
 */
class UnitTesting {
public:
	static void run() {
		Tester t;

		/*t.add(count_common_test::example);
		t.add(count_common_test::test1);
		t.add(count_common_test::test2);
		t.add(count_common_test::test3);
		t.add(count_common_test::test4);
		t.add(count_common_test::test5);*/

		t.add(calculator_test::example);
		t.add(calculator_test::test1);
		t.add(calculator_test::test2);
		t.add(calculator_test::test3);
		t.add(calculator_test::test4);
		t.add(calculator_test::test5);
		t.add(calculator_test::test6);
		t.add(calculator_test::test7);
		t.add(calculator_test::test8);
		t.add(calculator_test::test9);
		t.add(calculator_test::test10);

		t.run();
	}
};
