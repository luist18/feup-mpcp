#include "../src/test/tester.h"
#include "arm64/week1/checkrange_test.cpp"
#include "arm64/week2/countcommon_test.cpp"
#include "arm64/stack_exercises/reversestring_test.cpp"

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

		//t.add(reverse_string_test::test1);

		t.run();
	}
};
