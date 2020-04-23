#ifndef POWER_TEST_H_
#define POWER_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" long int power(int base, int exp);

using namespace asserts;

class power_test {
public:
	static void example() {
		assert_eq<long>(1L, power(2, 0));
		assert_eq<long>(1L, power(-3, 0));
		assert_eq<long>(1L, power(99, 0));
		assert_eq<long>(9L, power(3, 2));
		assert_eq<long>(27L, power(3, 3));
		assert_eq<long>(9L, power(-3, 2));
		assert_eq<long>(-27L, power(-3, 3));
		assert_eq<long>(4096L, power(16, 3));
		assert_eq<long>(-32768L, power(-32, 3));
		assert_eq<long>(-32768L, power(-32, 3));
		assert_eq<long>(1953125L, power(5, 9));
		assert_eq<long>(-16807L, power(-7, 5));
	}
};

#endif
