#ifndef TEST_TESTER_H_
#define TEST_TESTER_H_

#include <string>
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

	/**
	 * The name of the functions.
	 */
	vector<string> functionNames;

	/**
	 * The name of the project.
	 */
	string name;

public:
	/*!
	 * The default constructor.
	 */
	Tester();

	/*!
	 * This method adds a test function to the vector.
	 *
	 * @param function	the test function
	 * @param name		the name of the test
	 */
	void add(void (*function)(), string name);

	/*!
	 * Runs all of the test functions in the vector.
	 */
	void run();
};

#endif /* TEST_TESTER_H_ */
