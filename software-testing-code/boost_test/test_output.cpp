/**
 * @file test_output.cpp
 *
 * Illustrate boost test - output testing
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

// defines file as test driver with name "test output"
#define BOOST_TEST_MODULE test output

// include Boost.Test
#include <boost/test/included/unit_test.hpp>

// include object-under-test
#include "complex.hpp"

// include for output test stream
#include <boost/test/tools/output_test_stream.hpp>

// shortening of namespace
namespace btt = boost::test_tools;

BOOST_AUTO_TEST_CASE(output_zero) {

    // setup
    btt::output_test_stream output;
    complex zero(0, 0);

    // test
    output << zero;

    // verify
    // falses indicates do not flush output's buffer
    BOOST_TEST(!output.is_empty(false));
    BOOST_TEST(output.check_length(6, false));
    BOOST_TEST(output.is_equal("0 + 0i"));
}
