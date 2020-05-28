#include "assertexception.h"
#include <stdio.h>

assert_exception::assert_exception(string description) :
		description(description) {
}

string &assert_exception::getDescription() {
	return description;
}

