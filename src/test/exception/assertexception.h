#ifndef TEST_EXCEPTION_ASSERTEXCEPTION_H_
#define TEST_EXCEPTION_ASSERTEXCEPTION_H_

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class assert_exception: public exception {
	string description;

public:
	assert_exception(string description);

	string &getDescription();
};

#endif /* TEST_EXCEPTION_ASSERTEXCEPTION_H_ */
