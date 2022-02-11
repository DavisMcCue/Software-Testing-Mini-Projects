/**
 * @file complex.hpp
 *
 * Header (incomplete) for a complex class
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_COMPLEX_HPP
#define INCLUDED_COMPLEX_HPP

#include <exception>
#include <stdexcept>

class complex {
private:
  double real;
  double imaginary;

public:
  complex(double real = 0, double imaginary = 0)
    : real(real), imaginary(imaginary) {}

  bool operator==(const complex & that) const {
    return real == that.real && imaginary == that.imaginary;
  }

  friend complex operator+(complex lhs, const complex & rhs) {
    return complex(lhs.real + rhs.real, lhs.imaginary + rhs.imaginary);
  }

  friend complex operator/(complex lhs, const complex & rhs) throw(std::invalid_argument) {
    /** not going to waste time with real division 
      errors on no exception or wrong exception
      */
    if(rhs == complex()) throw std::invalid_argument("rhs is zero");
    return complex(lhs.real / rhs.real);
  }

};

#endif
