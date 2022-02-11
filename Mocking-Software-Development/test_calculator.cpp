/**
 * @file test_calculator.cpp
 *
 * Exercise to test a calculator class via mocking
 *
 * Based off of: http://turtle.sourceforge.net/turtle/motivation.html
 * 
 * @author Michael J. Decker
 */

#define BOOST_TEST_MODULE test calculator

#include <boost/test/included/unit_test.hpp>
#include <turtle/mock.hpp>

// define an abstract 'view_t' class with a pure virtual function 'display'.
// display will take one int


class view_t
{
public:
     virtual int display(int newDisplay) {};
}



// you will need to make this a subclass of `view_t`
class calculator_view : public view_t {
public:
    void display(int result) { /** GUI magic **/}
};



// calculator class that outputs results to a GUI called calculator_view
class calculator_t {
private:
    calculator_view view;
public:
    calculator_t() : view() {}
    void add(int a, int b) { view.display(a + b); }
};



// declare a 'mock_view' class implementing 'view_t'




// write a test in Boost.Test and verify display is called correctly
BOOST_AUTO_TEST_CASE(/** name this case */) {
    // create mock object


    // create object under test


    // Set expectations
    // expect the 'display' method to be called once (and only once)
    // with a parameter value equal to 0


    // excercise object under test


} // mock object verifies expectations via its destructor
