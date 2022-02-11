/**
 *  @file test_int_ctor.cpp
 *
 *  Test set(int) constructor.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <cassert>

#include <set.hpp>

int main(int argc, char * argv[]) {

    {
	set s(0);

	assert(s[0]);

	for(int i = 1; i < MAX; ++i) {
	    assert(!s.operator[](i));
	}

    }


    {
	set s(MAX - 1);

	assert(s[MAX - 1]);

	for(int i = 0; i < MAX - 1; ++i) {
	    assert(!s.operator[](i));
	}

    }

    {
	set s(MAX / 2);

	assert(s[MAX / 2]);

	for(int i = 0; i < MAX; ++i) {
	    if(i != MAX /2)
		assert(!s.operator[](i));
	}

    }

    {
	set s(MAX);

	for(int i = 0; i < MAX; ++i) {
	    assert(!s.operator[](i));
	}

    }


    return 0;
}
