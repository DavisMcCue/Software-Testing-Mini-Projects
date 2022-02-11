/**
 * @file test_add.datasets.cpp
 *
 * Illustrate boost test - BOOST_DATA_TEST_CASE
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

// defines file as test driver with name "test add"
#define BOOST_TEST_MODULE test add

// include Boost.Test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

// include object-under-test
#include "complex.hpp"

// shorten namespace
namespace bdata = boost::unit_test::data;


/*
 * Another use of datasets.  We are zipping 3 sets: lhs, rhs, and expected
 * As such, this forms a tuple (still by position, vertically aligned in code to help visualize)
 * and we now have 3 variables 
 */
const complex complex_data_lhs[] =    { complex(0, 0), complex(1, 0), complex(0, 1), complex(120, 140) };
const complex complex_data_rhs[] =    { complex(0, 0), complex(2, 0), complex(0, 2), complex(15, 10)   };
const complex complex_data_result[] = { complex(0, 0), complex(3, 0), complex(0, 3), complex(135, 150) };
BOOST_DATA_TEST_CASE(add, 
		     bdata::make(complex_data_lhs) ^ bdata::make(complex_data_rhs) ^ bdata::make(complex_data_result),
		     lhs, rhs, expected_result) {

  // test
  complex actual_result = lhs + rhs;

  BOOST_TEST_MESSAGE(lhs << " + " << rhs << " = " << actual_result);

  // verify
  BOOST_TEST(actual_result == expected_result);
}
