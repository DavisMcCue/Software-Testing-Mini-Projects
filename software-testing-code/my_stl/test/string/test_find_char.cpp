//  String class test program
//
//  Tests: find char
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
      String a;
      
      // VERIFY
      assert(a.find('a', 0) == -1);
      assert(a.find('a', 3) == -1);
      assert(a.find('z', 0) == -1);
      assert(a.find('g', 11) == -1);
      //assert(a.find('\0', 0) == -1);
    }

    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("graape");
      
      // VERIFY
      assert(a.find('a', 0) == 2);
      assert(a.find('a', 3) == 3);
      assert(a.find('z', 0) == -1);
      assert(a.find('g', 11) == -1);
    }

    std::cout << "Done testing find char." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

