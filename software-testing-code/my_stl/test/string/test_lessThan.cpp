//  String class test program
//
//  Tests: operator<
//

#include <string.hpp>
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  s1("ab");
        String  s2("abc");
        String  s3("ad");
        String  s4("d");
        String  s5("ab");
        String  s6("a");
        String  s7("");

        // TEST
        std::cout << "s1 == " << s1 << std::endl;
        std::cout << "s2 == " << s2 << std::endl;
        std::cout << "s3 == " << s3 << std::endl;
        std::cout << "s4 == " << s4 << std::endl;
        std::cout << "s5 == " << s5 << std::endl;
        std::cout << "s6 == " << s6 << std::endl;
        std::cout << "s7 == " << s7 << std::endl;

        // VERIFY
        assert(s1 < s2);
        assert(s1 < s3);
        assert(s1 < s4);
        assert(s6 < s4);
        assert(s6 < s5);
        assert(s7 < s2);
        assert("ab" < s2);
        assert("" < s3);
        assert('c' < s4)
;
        assert(!("foo" < s1));
        assert(!('z' < s4));
        assert(!(s1 < s1));
        assert(!(s6 < s6));
        assert(!(s2 < s1));
        assert(!(s3 < s1));
        assert(!(s4 < s1));
        assert(!(s4 < s7));

	assert(s1 <= s1);
	assert(s2 <= s3);
	assert(s7 <= s7);
	assert(s7 <= s6);
	assert(!(s3 <= s2));
	assert(!(s6 <= s7));
	assert(!(s4 <= s2));
    }

    
    

    std::cout << "Done testing operator<." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

