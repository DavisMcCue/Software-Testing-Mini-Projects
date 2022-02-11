//  String class test program
//
//  Tests: substring
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
      String a("grape");
            
      // VERIFY
      assert(a.substr(0, 0) == "");
      assert(a.substr(0, 4) == "grap");
      assert(a.substr(3, 1) == "p");
      assert(a.substr(0, 11) == "grape");
    }
    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("beta testing the alpha code");
            
      // VERIFY
      assert(a.substr(2, 0) == "");
      assert(a.substr(2, 6) == "ta tes");
      assert(a.substr(17, 2) == "al");
      assert(a.substr(0, 27) == "beta testing the alpha code");
    }

    std::cout << "Done testing find substring." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

