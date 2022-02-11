/**
 * @file reverse.cpp
 *
 * Implementation of a string reversal function
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "reverse.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>  
#include <string>

void reverse(std::string oldString)
{
    std::string newString = " ";
    std::string savingOldString;
    
    savingOldString = oldString;

    reverse(oldString.begin(), oldString.end());

    newString = oldString;

}




