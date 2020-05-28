#include "tester.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <ctime>
#include "exception/assertexception.h"

using namespace std;

Tester::Tester() {
	name = "/mpcp/armv8-architecture";
}

void Tester::add(void (*function)(), string name) {
	functions.push_back(function);
	functionNames.push_back(name);
}

void Tester::run() {
	cout << "Test project " << name << endl;

	cout << endl << "Running " << functions.size() << " tests..." << endl;
	int counter = 1;
	int passed = 0;

	clock_t begin_tests = clock();

	for (auto it = functions.begin(); it < functions.end(); ++it) {
		clock_t begin = clock();
		try {
			(*(*it))();
			clock_t end = clock();

			double elapsed = double(end - begin) / CLOCKS_PER_SEC;

			cout << setw(20) << left
					<< ("Test #" + to_string(counter) + ": "
							+ functionNames[counter - 1]) << string(28, '.')
					<< setw(12) << left << "   Passed" << fixed
					<< setprecision(2) << elapsed << " sec" << endl;
			passed++;
		} catch (assert_exception &e) {
			clock_t end = clock();

			double elapsed = double(end - begin) / CLOCKS_PER_SEC;
			cout << setw(20) << left
					<< ("Test #" + to_string(counter) + ": "
							+ functionNames[counter - 1]) << string(28, '.')
					<< setw(12) << left << "   Failed" << fixed
					<< setprecision(2) << elapsed << " sec" << endl;
			cout << "\t" << e.getDescription() << endl;
		}

		counter++;
	}

	clock_t end_tests = clock();

	double elapsed_tests = double(end_tests - begin_tests) / CLOCKS_PER_SEC;

	int percentage = passed * 100 / functions.size();

	int failed = functions.size() - passed;

	cout << endl << percentage << "% tests passed, " << failed
			<< " tests failed out of " << functions.size() << endl;
	cout << endl << "Total test time (real) = " << fixed << setprecision(2)
			<< elapsed_tests << " sec" << endl;
}
