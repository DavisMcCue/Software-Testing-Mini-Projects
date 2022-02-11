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
      String a("grape");
            
      // VERIFY
      assert(a.find("ape", 0) == 2);
      assert(a.find("ape", 2) == 2);
      assert(a.find("ape", 3) == -1);
      assert(a.find("ape", 11) == -1);
    }

    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("graape");
      
      // VERIFY
      assert(a.find("ape", 0) == 3);
      assert(a.find("ape", 2) == 3);
      assert(a.find("ape", 3) == 3);
      assert(a.find("ape", 50) == -1);
    }

    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("pineconeapple");
      
      // VERIFY
      assert(a.find("cone", 0) == 4);
      assert(a.find("cone", 4) == 4);
      assert(a.find("cone", 5) == -1);
      assert(a.find("cone", 11) == -1);
    }    

    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("pineconepine");
      
      // VERIFY
      assert(a.find("pine", 0) == 0);
      assert(a.find("pine", 2) == 8);
      assert(a.find("pine", 5) == 8);
      assert(a.find("pine", 11) == -1);
    }    
    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String a("pineconepine");
      
      // VERIFY
      assert(a.find("pintglass", 0) == -1);
      assert(a.find("pill", 2) == -1);
      assert(a.find("port", 5) == -1);
      assert(a.find("pino", 11) == -1);
      assert(a.find("elfears", 10) == -1);
    }    

    std::cout << "Done testing find string." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

