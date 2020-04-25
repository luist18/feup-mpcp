#include "tester.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "exception/assertexception.h"

using namespace std;

Tester::Tester() = default;

void Tester::add(void (*function)()) {
	functions.push_back(function);
}

void Tester::run() {
	int counter = 1;
	int passed = 0;

	for (auto it = functions.begin(); it < functions.end(); ++it) {
		try {
			(*(*it))();
			cout << "Test " << counter << " has passed." << endl;
			passed++;
		} catch (assert_exception &e) {
			cout << "Test " << counter << " has failed!" << endl;
			cout << e.getDescription() << endl;
		}

		counter++;
	}

	int percentage = passed * 100 / functions.size();

	cout << passed << " tests have passed in a total of " << functions.size() << " tests. [" << percentage << "%]";
}
