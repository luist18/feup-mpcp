# Microprocessors and Personal Computers
![asm](https://img.shields.io/badge/asm-AARCH64-brightgreen)

Resolution proposal of the exercises made within the course unit Microprocessors and Personal Computers (1st year, 2nd semester).

## Testing
In order to make the testing more easy, I've developed a bunch of classes to help running unit tests for the exercises. The process is simple and explained below.

1. Create the test class and include the asserts namespace located in /src/test/asserts.h, after that consider adding ``` using namespace asserts;``` to make the procedure easier.
2. Declare your assembly function following this example: ```extern "C" <TYPE> <FUNCTION_NAME>(<FUNCTION_ARGS>);```. Where the type is the return value of the assembly function, the FUNCTION_NAME is the name of the function declared in the **.s** file and the FUNCTION_ARGS are the arguments of the assembly function.
3. Declare each of the unit tests as a public static void function with no arguments in the created class. Example:
```cpp
using namespace asserts;

class example_test {
public:
	static void example() {
	    ...
	    assert_eq<type>(expected, value);
	}
}
```
4. Include the unit tests class in the **unit_testing.cpp** file located in the /test directory and add all the unit test functions to the Test class. Example: ```t.add(example_test::example);```

### Disclaimer
This repository contains the **assembly** exercises solved during the course unit. Note that some of them might contain errors and should not be used as a solution.

### License

[MIT](https://opensource.org/licenses/MIT)
