/**
 * @file test_cstring.cpp
 *
 * Tests String class c-string constructor
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {

    {
	String s("a");
	assert(s[0] == 'a');
	assert(s[1] == '\0');
	assert(s.length() == 1);
    }

    return 0;
}
