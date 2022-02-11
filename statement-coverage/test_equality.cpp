/**
 * @file test_equality.cpp
 *
 * Tests String class operator==
 *
 * @author Michael J. Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{

    // input: empty single typical max (equals)
    // output: equal and not equal (not equal on 0, mid, and end, off-by-one-subset in both orderings)

    // empty equals
    {
        // setup
        String lhs;
        String rhs("");

        // test/verify
        assert(lhs == rhs);

    }

    // single equals
    {
        // setup
        String lhs('a');
        String rhs("a");

        // test/verify
        assert(lhs == rhs);

    }

    // typical equals
    {
        // setup
        String lhs("abc");
        String rhs("abc");

        // test/verify
        assert(lhs == rhs);

    }

    // max equals
    {
        // setup
        String lhs("abcdefg");
        String rhs("abcdefg");

        // test/verify
        assert(lhs == rhs);

    }

    // 0 not-equals
    {
        // setup
        String lhs("a");
        String rhs("b");

        // test/verify
        assert(!(lhs == rhs));

    }

    // mid not-equals
    {
        // setup
        String lhs("abc");
        String rhs("abd");

        // test/verify
        assert(!(lhs == rhs));

    }

    // end not-equals
    {
        // setup
        String lhs("abcdefg");
        String rhs("abcdefh");

        // test/verify
        assert(!(lhs == rhs));

    }

    // off-by-one-subset not-equals
    {
        // setup
        String lhs("abcdef");
        String rhs("abcdefg");

        // test/verify
        assert(!(lhs == rhs));

    }

    // off-by-one-subset not-equals flipped order
    {
        // setup
        String lhs("abcdefg");
        String rhs("abcdef");

        // test/verify
        assert(!(lhs == rhs));

    }

    std::cout << "Done testing operator==." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

