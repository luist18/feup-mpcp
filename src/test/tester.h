#ifndef TEST_TESTER_H_
#define TEST_TESTER_H_

#include <vector>

using namespace std;

/*!
 * Reperesents the class responsible for storing and running the test functions.
 */
class Tester {
	/*!
	 * The vector of functions.
	 */
	vector<void (*)()> functions;

public:
	/*!
	 * The default constructor.
	 */
	Tester();

	/*!
	 * This method adds a test function to the vector.
	 *
	 * @param function	the test function
	 */
	void add(void (*function)());

	/*!
	 * Runs all of the test functions in the vector.
	 */
	void run();
};

#endif /* TEST_TESTER_H_ */
