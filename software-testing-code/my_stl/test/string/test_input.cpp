//  String class test program
//
//  Tests: String() - operator >>
//

#include <string.hpp>
#include <cassert>
#include <fstream>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;
	
	std::ifstream input("log_1_tiny.txt");
	assert(input.is_open());
	
        // VERIFY
	input >> str;
        assert( str == "131.123.47.176" );
	input >> str;
	assert( str == "-" );
	input >> str;
	assert( str == "-" );
	input >> str;
	assert( str == "[18/Sep/2002:12:05:25" );
	input >> str;
	assert( str == "-0400]" );
	input >> str;
	assert( str == "\"GET");
	input >> str;
	assert( str == "/~darci/" );
	input >> str;
	assert( str == "HTTP/1.0\"" );
	input >> str;
	assert( str == "200" );
	input >> str;
	assert( str == "5625" );

	input.close();
    }
    
    std::cout << "Done operator>>." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

