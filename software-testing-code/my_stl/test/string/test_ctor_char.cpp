//  String class test program
//
//  Tests: String(char) ctor
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
        String  str('\0');
        
        // VERIFY
        std::cout << "|| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity() << std::endl;
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0 || str.capacity() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String  str('a');
        
        // VERIFY
        std::cout << "|a| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity() << std::endl;
        assert(str == "a");
        assert(str.length() == 1);
        assert(str.capacity() == 1);
    }
    std::cout << "Done testing ctor String(char)." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

