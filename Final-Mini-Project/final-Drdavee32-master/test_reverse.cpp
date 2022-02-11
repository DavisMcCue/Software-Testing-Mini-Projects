/**
 * @file test_reverse.cpp
 *
 * Develop reverse function using TDD.  Write tests in Boost.Test
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "reverse.hpp"
#define BOOST_TEST_MODULE FinalTest
#include <boost/test/included/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(MyFinalExamSuite)

//Test case1
BOOST_AUTO_TEST_CASE(MyFinalTest)
  {
   //setup
   std::string str;
   //test 
   str = "foobar";
   //verify
   BOOST_CHECK(reverse(str == "raboof")); 
  }
BOOST_AUTO_TEST_SUITE_END();
