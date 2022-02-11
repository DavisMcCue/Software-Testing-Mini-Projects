//  String class test program
//
//  Tests: operator==
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
        String  s2("ab");
        String  s3("abc");
        String  s4("a");
        String  s5;
        String  s6("");
        String  s7('a');
	String  s8("0123456789ABCDEFGHIJ!@#$%^&*()0123456789ABCDEFGHIJ!@#$%^&*()");
	String  s9("0123456789ABCDEFGHIJ!@#$%^&*()0123456789ABCDEFGHIJ!@#$%^&*()");
	String  s10("     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t     \t\n \t00255");
        // TEST
        std::cout << "s1 == " << s1 << std::endl;
        std::cout << "s2 == " << s2 << std::endl;
        std::cout << "s3 == " << s3 << std::endl;
        std::cout << "s4 == " << s4 << std::endl;
        std::cout << "s5 == " << s5 << std::endl;
        std::cout << "s6 == " << s6 << std::endl;
        std::cout << "s7 == " << s7 << std::endl;
        std::cout << "s8 == " << s8 << std::endl;
        std::cout << "s9 == " << s9 << std::endl;
	std::cout << "s10 == " << s10 << std::endl;
        
        // VERIFY
        assert(s1 == s2);
        assert(s5 == s6);
        assert(s4 == s7);
	assert(s8 == s9);
	assert(s9 == s8);

	assert("ab" == s2);
        assert("" == s6);
        assert('a' == s7);

	assert(s10 != s6);
        assert(s1 != s3);
        assert(s1 != s4);
        assert(s6 != s1);

        assert("ab" != s3);
	assert("" != s7);
        assert('g' != s1);
    }

    
    

    std::cout << "Done testing operator==." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

