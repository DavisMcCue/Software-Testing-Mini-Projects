/**
 * @file test_complex.cpp
 *
 * Illustrate boost test - Dr. Decker test class with each method 
 * a separate include and using BOOST_DATA_TEST_CASE
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

// defines file as test driver with name "complex"
#define BOOST_TEST_MODULE complex

// include Boost.Test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

// include object-under-test
#include "complex.hpp"

// shorten namespace
namespace bdata = boost::unit_test::data;

/** on module for complex, but separate files for each method
 *  A style Dr. Decker came up with
 */
#include "test_equals.datasets.hpp"
#include "test_add.datasets.hpp"
