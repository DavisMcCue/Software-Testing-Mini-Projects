//  String class test program
//
//  Tests: copy ctor && destructor 
//

#include <string.hpp>
#include <cassert>
#include <iostream>

//===========================================================================

void testCopy(String x, const char* c_str, int len) {
    // VERIFY
    assert(x == c_str);
    assert(x.length() == len);
    assert(x.capacity() == len);
}


int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("");
        
        // TEST
        
        testCopy(str, "", 0);
        
        // VERIFY
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0);
        
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        
        // TEST
        
        testCopy(str, "abc", 3);
        
        // VERIFY
        assert(str == "abc");
        assert(str.length() == 3);
        assert(str.capacity() == 3);
        
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("a987 s8djgk \n c");
        
        // TEST
        
        testCopy(str, "a987 s8djgk \n c", 15);
        
        // VERIFY
        assert(str == "a987 s8djgk \n c");
        assert(str.length() == 15);
        assert(str.capacity() == 15);
        
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop");
        
        // TEST
        
        testCopy(str, "qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwerty\
uiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwe\
rtyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop", 400);
        
        // VERIFY
        assert(str == "qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwerty\
uiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwe\
rtyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop");
        assert(str.length() == 400);
        assert(str.capacity() == 400);
        
    }
        
    std::cout << "Done testing copy ctor." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

