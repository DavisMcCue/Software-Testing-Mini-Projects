//  String class test program
//
//  Tests: String() - default ctor
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
        String  str;
        std::cout << "|| == |" << str << "| && length == " << str.length() << " && Capacity == " << str.capacity() << std::endl;

        // VERIFY
        assert(str == "");
	//assert(str[0] == '\0');
        assert(str.length() == 0);
        assert(str.capacity() == 0);
    }

    
    std::cout << "Done testing default ctor." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

