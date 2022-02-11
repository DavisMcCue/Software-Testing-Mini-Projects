/**
 * @file driver.cpp
 *
 * Runs complex unit tests.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

int main(int argc, char * argv[]) {

  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry & registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());

  /** run(test path, wait)? */
  return !runner.run( "", false );
}
