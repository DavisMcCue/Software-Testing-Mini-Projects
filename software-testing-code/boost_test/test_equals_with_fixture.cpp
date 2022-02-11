/**
 * @file test_equals_with_fixutre.cpp
 *
 * Illustrate boost test - fixtures.  Only struct option of fixtures is shown.
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

// defines file as test driver with name "test equals"
#define BOOST_TEST_MODULE test equals

// include Boost.Test
#include <boost/test/included/unit_test.hpp>

// include object-under-test
#include "complex.hpp"

/* fixture struct - name is your choice
 * declared data members are accessible in test cases
 *
 * Used for non-trivial setup and cleanup
 * 
 * constructor followed by setup (optional) is called before execution of test case
 * teardown (optional) followed by destructor is called after each test case is executed
 */
struct fixture {
    std::string s;

    fixture(std::string s = "fixture") : s(s) { 
        BOOST_TEST_MESSAGE("ctor " << s);
    }

    void setup() {
        BOOST_TEST_MESSAGE("optional setup " << s);
    }

    void teardown()	{
        BOOST_TEST_MESSAGE("optional teardown " << s);
    }

    ~fixture() {
        BOOST_TEST_MESSAGE("dtor " << s);
    }
};

void setup() { BOOST_TEST_MESSAGE("free setup"); }
void teardown() { BOOST_TEST_MESSAGE("free teardown"); }

/** start with original auto test and show various ways of adding fixtures 
    Show output by running: ./fixture --log_level=message

    - auto free function
    - auto test object - no access to members
    - fixture test object
    - auto/fixture suite object 
        - auto only once construct/destruct, fixture each case construct/destruct.
	- fixture does not call setup/teardown UNLESS compiled with >= C++11
*/

/*
 * can attach a fixture to a suite
 * Before each test, constructor/setup will be called
 * After each test, teardown/destructor will be called
 */
BOOST_FIXTURE_TEST_SUITE(equals_suite, fixture)


BOOST_AUTO_TEST_CASE(equals_simple_1) {

    // can access fixture class's data members in test
    BOOST_TEST_MESSAGE("test 1 " + s);
    complex zero_one(0, 0);
    complex zero_two(0, 0);
   
    BOOST_TEST(zero_one == zero_two);
}

BOOST_AUTO_TEST_CASE(equals_simple_2) {

// can attach fixture only to specific test cases
//BOOST_FIXTURE_TEST_CASE(equals_simple_2, fixture) {

    // can access fixture class data members when BOOST_FIXTURE_TEST_CASE as well
    BOOST_TEST_MESSAGE("test 2 " + s);
    complex num_one(10, 1);
    complex num_two(10, 1);
   
    BOOST_TEST(num_one == num_two);
}

BOOST_AUTO_TEST_CASE(equals_not) {

    BOOST_TEST_MESSAGE("test 3");
    complex num_one(11, 1);
    complex num_two(11, 2);
   
    BOOST_TEST(!(num_one == num_two));
}

BOOST_AUTO_TEST_SUITE_END()
