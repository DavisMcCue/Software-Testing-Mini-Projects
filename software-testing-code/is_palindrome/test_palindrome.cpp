/**
 * @file test_palindrome.cpp
 *
 * Illustrates TDD on a palindrome checking function
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

#define BOOST_TEST_MODULE palindrome
#include <boost/test/included/unit_test.hpp>
#include "palindrome.hpp"


/**
 * Steps:
 *   1. Add a test
 *   2. Make sure fails - test harness works, not a bad test (red phase)
 *   3. Make it work
 *   4. Run tests - all should pass (green phase)
 *   5. Refactor - Code from previous step for may be inelegant
 *   6. Repeat - small steps each time.
 *
 *   Important test is adding one new something.
 *   In debugging, you may find holes in the testing pattern, and insert more fine-grained tests
 */

/**
 * All steps to test and develop is_palindrome are present
 * To simulate process:
 *   * Uncomment one test at a time
 *   * Compile and run - verify it fails
 *   * Uncomment next implemented function in palindrome.cpp and comment out others
 *   * Compile and run - verify it passe
 *   * Refactor - For some there is then a refactored version, uncomment, comment out others, and compile/run/verify
 *   * Repeat
 */


#if 0
/** write first then start palindrome */
BOOST_AUTO_TEST_CASE(empty) {

    BOOST_TEST(is_palindrome(""));

}

/** 
 * Incremently build up test.  Each test should test one thing.
   Each new test should test something new (not be a repeat).
 * Because of this the test should fail
 */

BOOST_AUTO_TEST_CASE(two_char_different) {

    BOOST_TEST(!is_palindrome("ab"));

}


BOOST_AUTO_TEST_CASE(single_char) {

    BOOST_TEST(is_palindrome("a"));

}

BOOST_AUTO_TEST_CASE(two_char_same) {

    BOOST_TEST(is_palindrome("aa"));

}

BOOST_AUTO_TEST_CASE(three_char_not) {

    BOOST_TEST(!is_palindrome("abb"));

}

BOOST_AUTO_TEST_CASE(second_char_not_equal) {

    BOOST_TEST(!is_palindrome("radder"));

}

BOOST_AUTO_TEST_CASE(longer_is_palindrome) {

    BOOST_TEST(is_palindrome("detartrated"));

}

BOOST_AUTO_TEST_CASE(third_char_not_equal) {

    BOOST_TEST(!is_palindrome("abcdedfba"));

}

/** At this point nothing really we can't specify anymore that the tests would fail */
/* 
    Personally, there might be more test cases I would write to both
    ensure and encode the correct behavior such as if spaces or case count

*/

/** Do spaces count, could also do caseing... but will stop here. */
BOOST_AUTO_TEST_CASE(sentence_is) {

    BOOST_TEST(is_palindrome("step on no pets"));

}

BOOST_AUTO_TEST_CASE(sentence_not) {

    BOOST_TEST(!is_palindrome("was it a car or a cat I saw"));

}

#endif 
