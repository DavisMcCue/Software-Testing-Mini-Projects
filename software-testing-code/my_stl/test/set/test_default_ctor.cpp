/**
 *  @file test_default_ctor.cpp
 *
 *  Test set default constructor.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <cassert>

#include <set.hpp>

int main(int argc, char * argv[]) {

    {
	set s;

	for(int i = 0; i < MAX; ++i) {
	    assert(!s.operator[](i));
	}
    }

    return 0;
}
