/**
 * @file fizzbuzz.cpp
 *
 * Implements fizzbuzz project to practice TDD
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "fizzbuzz.hpp"
#include <string>

std::string fizzbuzz(int newInput)
{
  if(newInput%5 == 0 && newInput%3 == 0 )
  {
    return "fizzbuzz";
  }
  else if (newInput%3 == 0)
  {
    return "fizz";
  }
  else if (newInput%5 == 0)
  {
    return "buzz";
  }
  else
  {
    return std::to_string(newInput);
  } 
}
