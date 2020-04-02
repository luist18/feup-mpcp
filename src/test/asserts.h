#ifndef ASSERTS_H_
#define ASSERTS_H_

#include <sstream>
#include <iostream>
#include "exception/assertexception.h"

namespace asserts {

	/*!
	 * Compares the both results. If the results are different then throws an an assert exception.
	 *
	 * @param expected	the expected value
	 * @param value		the obtained value
	 */
	template<typename T>
	void assert_eq(T expected, T value) {
		if (expected != value){
			stringstream c;
			c << "Expected " << expected << " and got " << value;
			throw assert_exception(c.str());
		}
	}

	/*!
	 * Compares the both results. If the results are equal then throws an an assert exception.
	 *
	 * @param expected	the expected value
	 * @param value		the obtained value
	 */
	template<typename T>
	void assert_neq(T expected, T value) {
		if (expected == value){
			stringstream c;
			c << "Expected " << expected << " and got " << value;
			throw assert_exception(c.str());
		}
	}
}

#endif /* ASSERTS_H_ */
