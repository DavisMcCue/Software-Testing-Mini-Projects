/**
 * @file test_palindrome.cpp
 *
 * Header for palindrome project.
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */
#include "palindrome.hpp"
#define BOOST_TEST_MODULE ExamTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(examTestSuite)

//Test Case 1
BOOST_AUTO_TEST_CASE(MyTestCase)
  {
  //setup
  std::string str1;
  //test
  str1 = "";
  //verify
  BOOST_CHECK(is_palindrome(str1)); 
  }

//Test Case 2
BOOST_AUTO_TEST_CASE(MyTestCase2)
  {
  //setup
  std::string str1;
  //test
  str1 = "a";
  //verify
  BOOST_CHECK(is_palindrome(str1)); 
  }

//Test Case 3
BOOST_AUTO_TEST_CASE(MyTestCase3)
  {
  //setup
  std::string str1;
  //test
  str1 = "radder";
  //verify
  //BOOST_CHECK(is_palindrome(str1)); 
  }

//Test Case 4
BOOST_AUTO_TEST_CASE(MyTestCase4)
  {
  //setup
  std::string str1;
  //test
  str1 = "step on no pets";
  //verify
  //BOOST_CHECK(is_palindrome(str1)); 
  }
BOOST_AUTO_TEST_SUITE_END();
