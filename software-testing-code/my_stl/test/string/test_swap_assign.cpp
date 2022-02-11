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
        String  str("abc");
	String  s;

	// TEST
	s = str;

        // VERIFY
        assert(str == "abc");
	assert(str.length() == 3);
        assert(str.capacity() == 3);
        assert(s == "abc");
	assert(s.length() == 3);
        assert(s.capacity() == 3);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("");
	String  s;
	   
        // TEST
     	s = str;

        // VERIFY
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0);
        assert(s == "");
        assert(s.length() == 0);
        assert(s.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x");
	String  s("10");
        
        // TEST
	s = str;
        
        // VERIFY
        assert(str == "x");
        assert(str.length() == 1);
        assert(str.capacity() == 1);
	assert(s == "x");
        assert(s.length() == 1);
        assert(s.capacity() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x3231321654987654321");
	String  s("10");
        
        // TEST
	s = str;
        
        // VERIFY
        assert(str == "x3231321654987654321");
        assert(str.length() == 20);
        assert(str.capacity() == 20);
        assert(s == "x3231321654987654321");
        assert(s.length() == 20);
        assert(s.capacity() == 20);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x2");
	String  s("105649873216827");
        
        // TEST
	s = str;
        
        // VERIFY
        assert(str == "x2");
        assert(str.length() == 2);
        assert(str.capacity() == 2);
	assert(s == "x2");
        assert(s.length() == 2);
        assert(s.capacity() == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("");
	String  s;
        
        // TEST
	s.swap(str);
        
        // VERIFY
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0);
	assert(s == "");
        assert(s.length() == 0);
        assert(s.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
	String  s;
        
        // TEST
	s.swap(str);
        
        // VERIFY
        assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0);
	assert(s == "abc");
        assert(s.length() == 3);
        assert(s.capacity() == 3);
    }
        {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x");
	String  s("10");
        
        // TEST
	s.swap(str);
        
        // VERIFY
        assert(str == "10");
        assert(str.length() == 2);
        assert(str.capacity() == 2);
	assert(s == "x");
        assert(s.length() == 1);
        assert(s.capacity() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x3231321654987654321");
	String  s("10");
        
        // TEST
	s.swap(str);
        
        // VERIFY
        assert(s == "x3231321654987654321");
        assert(s.length() == 20);
        assert(s.capacity() == 20);
        assert(str == "10");
        assert(str.length() == 2);
        assert(str.capacity() == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("x2");
	String  s("105649873216827");
        
        // TEST
	s.swap(str);
        
        // VERIFY
        assert(str == "105649873216827");
        assert(str.length() == 15);
        assert(str.capacity() == 15);
        assert(s == "x2");
        assert(s.length() == 2);
        assert(s.capacity() == 2);
    }
    std::cout << "Done testing ctor String(char[])." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

