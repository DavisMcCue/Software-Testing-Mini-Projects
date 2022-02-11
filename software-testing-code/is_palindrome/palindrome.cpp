/**
 * @file palindrome.cpp
 *
 * Implements palindrome project to illustrate TDD
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "palindrome.hpp"

#if 0
/** first empty */
bool is_palindrome(const std::string & str) {
    return true;    
}

/** second, two diff char */
bool is_palindrome(const std::string & str) {
    return str.empty();    
}


/** single char */
bool is_palindrome(const std::string & str) {
    if(str.empty())     return true;
    if(str.size() == 1) return true;
    return false;    
}

/** single char - refactored */
bool is_palindrome(const std::string & str) {
    if(str.size() == 2) return false;

    return true;    
}

/** works for two char */
bool is_palindrome(const std::string & str) {
    if(str.size() == 2) return str[0] == str[1];

    return true;    
}

/** three char */
bool is_palindrome(const std::string & str) {
    if(str.size() >= 2) return str.front() == str.back();

    return true;    
}

/** long are not palindromes? */
bool is_palindrome(const std::string & str) {
    if(str.size() >= 2 && str.front() != str.back()) return false;
    if(str.size() > 3) return false;

    return true;    
}


/* long is palindrome */
bool is_palindrome(const std::string & str) {
    if(str.size() >= 2 && str.front() != str.back()) return false;
    if(str.size() > 3) return str[1] == str[str.size() - 2];

    return true;    
}


/* 3rd not equal */
bool is_palindrome(const std::string & str) {
    if(str.size() >= 2 && str.front() != str.back())    return false;
    if(str.size() > 3 && str[1] != str[str.size() - 2]) return false;
    if(str.size() > 5 && str[2] != str[str.size() - 3]) return false;

    return true;    
}

/* 
    3rd not equal - refactored 
    generic loop version
*/
bool is_palindrome(const std::string & str) {
    ssize_t begin = 0;
    ssize_t end = str.size() - 1;
    while(begin < end) {
        if(str[begin] != str[end])
            return false;
        ++begin;
        --end;
    }

    return true;    
}
#endif
