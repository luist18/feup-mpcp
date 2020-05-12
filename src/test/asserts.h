#ifndef ASSERTS_H_
#define ASSERTS_H_

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>
#include "exception/assertexception.h"

#define EPSILON 0.00000519250

namespace asserts {

	/*!
	 * Compares the both results. If the results are different then throws an an assert exception.
	 *
	 * @param expected	the expected value
	 * @param value		the obtained value
	 */
	template<typename T>
	void assert_eq(T expected, T value) {
		stringstream c;

		if (std::is_floating_point<T>::value){
			double a = (double) expected;
			double b = (double) value;

			double eps = abs(a - b);

			if (eps > EPSILON){
				c << "Expected " << std::fixed << std::setprecision(11) << a << " and got " << std::fixed << std::setprecision(11) << b;
				throw assert_exception(c.str());
			}
		} else if (expected != value) {
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

			if (std::is_floating_point<T>::value)
				c << "Expected " << std::fixed << std::setprecision(3) << expected << " and got " << std::fixed << std::setprecision(3) << value;
			else
				c << "Expected " << expected << " and got " << value;

			throw assert_exception(c.str());
		}
	}

	template<typename T>
	void assert_vector_eq(T expected[], T value[], unsigned long size){
		stringstream expected_stream, value_stream, c;

		for (unsigned long i = 0; i < size; i++){
			expected_stream << expected[i] << ", ";
			value_stream << value[i] << ", ";
		}

		if (expected_stream.str().compare(value_stream.str()) != 0){
			c << "Expected " << expected_stream.str().substr(0, expected_stream.str().size() - 2) << " and got " << value_stream.str().substr(0, value_stream.str().size() - 2);

			throw assert_exception(c.str());
		} else {
			cout << "Expected " << expected_stream.str().substr(0, expected_stream.str().size() - 2) << " and got " << value_stream.str().substr(0, value_stream.str().size() - 2) << endl;
		}
	}
}

#endif /* ASSERTS_H_ */
