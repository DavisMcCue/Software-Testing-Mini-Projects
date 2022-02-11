/**
 * @file complex_number_test.hpp
 *
 * Illustrates test case.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_COMPLEX_NUMBER_TEST_HPP
#define INCLUDED_COMPLEX_NUMBER_TEST_HPP

#include "complex.hpp"
#include <cppunit/TestCase.h>

class complex_number_test : public CppUnit::TestCase {
public:
  complex_number_test(std::string name) : CppUnit::TestCase(name) {}

  void runTest() {
    CPPUNIT_ASSERT(complex(10, 1) == complex(10, 1));
    CPPUNIT_ASSERT(!(complex(1, 1) == complex(2, 2)));    
  }

};


#endif
