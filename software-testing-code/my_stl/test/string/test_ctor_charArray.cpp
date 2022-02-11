//  String class test program
//
//  Tests: String(char[]) ctor
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
        
        // TEST
        String  str("abc");
        
        // VERIFY
        std::cout << "|abc| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity() << std::endl;
        assert(str == "abc");
        assert(str.length() == 3);
        assert(str.capacity() == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String  str("");
        
        // VERIFY
        std::cout << "|| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity()  << std::endl;
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String  str("x");
        
        // VERIFY
        std::cout << "|x| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity()  << std::endl;
        assert(str == "x");
        assert(str.length() == 1);
        assert(str.capacity() == 1);
    }
    
    std::cout << "Done testing ctor String(char[])." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

