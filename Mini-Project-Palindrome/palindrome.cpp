/**
 * @file palindrome.cpp
 *
 * Implementation for palindrome project.
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */
#include "palindrome.hpp"

bool is_palindrome(const std::string & str) {
    size_t length = str.size();
    size_t num_checks = length / 2;
    for(int offset = 0; offset < num_checks; ++offset) {
        if(str[offset] != str[length - offset - 1])
            return false;
    }

    return true;    
}
