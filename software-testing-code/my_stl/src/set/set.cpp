/**
 * @file set.cpp
 *
 * Implementation for set ADT.
 * @author Michael John Decker 
 */
#include "set.hpp"

bool in_universe(int number) {

    if(number < 0) return false;
    if(number >= MAX) return false;
    
    return true;

}


set::set() {

    for(int i = 0; i < MAX; ++i) {
	in_set[i] = false;
    }

}

set::set(int num) : set() {

    if(!in_universe(num)) return;

    in_set[num] = true;

}

set::set(int num, int num2) : set(num) {
    if(!in_universe(num2)) return;

    in_set[num2] = true;

}

set::set(int num, int num2, int num3) : set(num, num2) {
    if(!in_universe(num3)) return;

    in_set[num3] = true;

}

set::set(std::initializer_list<int> init_list) : set() {

    for(int i : init_list) {
	if(in_universe(i)) {
	    in_set[i] = true;
	}
    }

}

bool set::operator[](int i) const {

    if(!in_universe(i)) return false;

    return in_set[i];
}


std::ostream & operator<<(std::ostream & out, const set & that) {

    bool comma = false;

    out << '{';

    for(int i = 0; i < MAX; ++i) {
	if(that[i]) {
	    if(comma) out << ", ";
	    out << i;
	    comma = true;
	}
    }

    out << '}';

    return out;

}

set set::operator+(const set & rhs) const {

    set result;

    for(int i = 0; i < MAX; ++i) {
	result.in_set[i] = (in_set[i] || rhs.in_set[i]);
    }
    return result;

}

set operator+(int num, const set & rhs) {

    set lhs(num);
    return lhs + rhs;
}
