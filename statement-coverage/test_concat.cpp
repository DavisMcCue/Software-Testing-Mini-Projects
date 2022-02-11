/**
 * @file test_concat.cpp
 *
 * Tests String class operator+
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

//===========================================================================
int main () {

    // This follows more closely to methdology on deriving tests
    // Would order tests differently for TDD.  Might also have more because incremental build up.

    // Categories: 
    // Input empty, singles, multi
    // Output: empty, single, multi

    // special: cap & truncate

    // typical
    {
        //------------------------------------------------------
        // setup
        String  left("ab");
        String  right("xyz");

        // test
        String result;
        result = left + right;

        // verify
        std::cout << "|abxyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(left   == "ab");
        assert(right  == "xyz");
        assert(result == "abxyz");
        assert(result.length() == 5);

        // less important in this implementation, but would be if dynamic allocated
        // could use same tests. That being said, may never need dynamic allocated, so...
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // multi empty
    {
        //------------------------------------------------------
        // setup
        String  left("abc");
        String  right("");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|abc| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abc");
        assert(left   == "abc");
        assert(right  == "");
        assert(result.length() == 3);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // right single character
    {
        //------------------------------------------------------
        // setup
        String  left("abc");
        String  right("d");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|abcd| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abcd");
        assert(left   == "abc");
        assert(right  == "d");
        assert(result.length() == 4);
        assert(result.capacity() >= STRING_SIZE-1);
    }
    
    // empty multi
    {
        //------------------------------------------------------
        // setup
        String  left("");
        String  right("xyz");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|xyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "xyz");
        assert(left   == "");
        assert(right  == "xyz");
        assert(result.length() == 3);
        assert(result.capacity() >= STRING_SIZE-1);
    }
   
    // left single character
    {
        //------------------------------------------------------
        // setup
        String  left("w");
        String  right("xyz");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|wxyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "wxyz");
        assert(left   == "w");
        assert(right  == "xyz");
        assert(result.length() == 4);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // both empty
    {
        //------------------------------------------------------
        // setup
        String  left("");
        String  right("");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
        assert(result.length() == 0);
        assert(result.capacity() >= STRING_SIZE-1);
    }
    
    // both single character
    {
        //------------------------------------------------------
        // setup
        String  left("a");
        String  right("x");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|ax| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "ax");
        assert(left   == "a");
        assert(right  == "x");
        assert(result.length() == 2);
        assert(result.capacity() >= STRING_SIZE-1);
    }
    
    // empty + single
    {
        //------------------------------------------------------
        // setup
        String  left("");
        String  right("x");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|x| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "x");
        assert(left   == "");
        assert(right  == "x");
        assert(result.length() == 1);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // single + empty
    {
        //------------------------------------------------------
        // setup
        String  left("a");
        String  right("");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|a| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "a");
        assert(left   == "a");
        assert(right  == "");
        assert(result.length() == 1);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // cap
    {
        //------------------------------------------------------
        // setup
        String  left("abc");
        String  right("defg");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|abcdefg| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abcdefg");
        assert(left   == "abc");
        assert(right  == "defg");
        assert(result.length() == 7);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    // truncate
    {
        //------------------------------------------------------
        // setup
        String  left("abc");
        String  right("defgh");
        
        // test
        String result = left + right;
        
        // verify
        std::cout << "|abcdefg| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abcdefg");
        assert(left   == "abc");
        assert(right  == "defgh");
        assert(result.length() == 7);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    std::cout << "Done testing operator+." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

