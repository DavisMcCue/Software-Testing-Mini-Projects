// include boost
#include <boost/test/included/unit_test.hpp>

// include object-under-test
#include "complex.hpp"

// each function is a test case
void equals_simple() {
    complex zero_one(0, 0);
    complex zero_two(0, 0);
   
    BOOST_TEST(zero_one == zero_two);
}

void equals_not() {
    
    complex ten_one(10, 1);
    complex eleven_two(11, 2);
   
    BOOST_TEST(!(ten_one == eleven_two));
}

// acts as main and registers tests
boost::unit_test::test_suite * init_unit_test_suite( int argc, char* argv[] )
{
    // register each test case
    boost::unit_test::framework::master_test_suite()
        .add( BOOST_TEST_CASE(&equals_simple));

    boost::unit_test::framework::master_test_suite()
        .add( BOOST_TEST_CASE(&equals_not));

    return 0;
}
