/**
 * @file driver.cpp
 *
 * Runs complex unit tests.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include "complex_number_test.hpp"

int main(int argc, char * argv[]) {

  complex_number_test test("operator==");
  test.runTest();

  return 0;
}
