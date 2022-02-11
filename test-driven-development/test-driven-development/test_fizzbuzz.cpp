/**
 * @file test_fizzbuzz.cpp
 *
 * Test a fizzbuzz function usingn TDD
 *
 * Specification:
 *    * Function takes a number and returns a string
 *    * Input - is any valid positive number
 *    * Output:
 *        * case input is divisible by 3 and 5, then return "fizzbuzz"
 *        * case input is divisible by 3, then return "fizz"
 *        * case input is divisible by 5, then return "buzz"
 *        * Otherwise, return input number as a string (you may use std::to_string)
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 */

#define BOOST_TEST_MODULE fizzbuzz
#include <boost/test/included/unit_test.hpp>
#include "fizzbuzz.hpp"

BOOST_AUTO_TEST_SUITE(Tests)

//Test Case 1
BOOST_AUTO_TEST_CASE(Tests1)
  {
    //setup
    int p;
    //test 
    p = 15; 
    //verify 
    BOOST_CHECK(fizzbuzz(p) == "fizzbuzz");
  }
//Test Case 2
BOOST_AUTO_TEST_CASE(Tests2)
  {
    //setup
    int p;
    //test 
    p = 9; 
    //verify     
    BOOST_CHECK(fizzbuzz(p) == "fizz");
  }
//Test Case 3
BOOST_AUTO_TEST_CASE(Tests3)
  {
    //setup
    int p;
    //test 
    p = 25; 
    //verify     
    BOOST_CHECK(fizzbuzz(p) == "buzz");
  }
//Test Case 4
BOOST_AUTO_TEST_CASE(Tests4)
  {
    //setup
    int p;
    //test 
    p = 502; 
    //verify     
    BOOST_CHECK(fizzbuzz(p) == "502");
  }


BOOST_AUTO_TEST_SUITE_END();