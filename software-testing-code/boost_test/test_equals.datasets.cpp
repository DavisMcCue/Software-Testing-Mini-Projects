/**
 * @file test_equals.datasets.cpp
 *
 * Illustrate boost test - BOOST_DATA_TEST_CASE
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

// defines file as test driver with name "test equals"
#define BOOST_TEST_MODULE test equals

// include Boost.Test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

// include object-under-test
#include "complex.hpp"

// shorten namespace
namespace bdata = boost::unit_test::data;


// dataset of test input for equals simple
const complex complex_data[] = { complex(0, 0), complex(10, 1) };

/*
 * BOOST_DATA_TEST_CASE(name, dataset, variables)
 *     @param name - name of test case
 *     @param dataset - dataset with input for tests
 *         make - use to turn data into dataset
 *         xrange(n) - generate numeric sequence dataset from 0 to n - 1
 *         combining datasets:
 *             + (join) - concatenate datasets
 *             ^ (zip) - pair together datasets by position
 *             * (grid) - cartesian product *
 *     @param variables - list of variables to hold test input items (one at a time)
 *         xrange ^ make(complex_data) - pairs each of the n elements.
 *             each pair consists of num from xrange and complex object from make(complex_data)
 *             there is a variable for each item in pair
 *             note: pair can be a tuple, there are as many variables as there is merged datasets
 * runs test body once for each test item in dataset. Each is a separately ran and logged test
 *     
 *
 */
BOOST_DATA_TEST_CASE(equal_simple, bdata::xrange(2) ^ bdata::make(complex_data), num, value) {
    std::cerr << num << ": " << value << '\n';
    BOOST_TEST(value == value);
}

/*
 * Another example.  Here, input data is left-hand-side and right-hand-side pair
 */
const complex complex_data_lhs[] = { complex(11, 1), complex(11, 1), complex(11, 1) };
const complex complex_data_rhs[] = { complex(11, 2), complex(12, 1), complex(12, 2) };
BOOST_DATA_TEST_CASE(equal_not, bdata::make(complex_data_lhs) ^ bdata::make(complex_data_rhs), lhs, rhs) {
    // inserts log message, use --log_level=message to see
    BOOST_TEST_MESSAGE(lhs << " == " << rhs);

    BOOST_TEST(!(lhs == rhs));
}
