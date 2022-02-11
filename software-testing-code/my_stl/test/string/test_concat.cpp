//  String class test program
//
//  Tests: operator+
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
        String  left("ab");
        String  right("xyz");

        // TEST
        String result;
        result = left + right;

        // VERIFY
        std::cout << "|abxyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(left   == "ab");
        assert(right  == "xyz");
        assert(result == "abxyz");
        assert(result.length() == 5);
        assert(result.capacity() == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("xyz");

        // TEST
        String result;
        result = "ab" + right;

        // VERIFY
        std::cout << "|abxyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(right  == "xyz");
        assert(result == "abxyz");
        assert(result.length() == 5);
        assert(result.capacity() == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|abc| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abc");
        assert(left   == "abc");
        assert(right  == "");
        assert(result.length() == 3);
        assert(result.capacity() == 3);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("abc");
        
        // TEST
        String result = "" + right;
        
        // VERIFY
        std::cout << "|abc| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abc");
        assert(right   == "abc");
        assert(result.length() == 3);
        assert(result.capacity() == 3);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("xyz");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|xyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "xyz");
        assert(left   == "");
        assert(right  == "xyz");
        assert(result.length() == 3);
        assert(result.capacity() == 3);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right;
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
        assert(result.length() == 0);
        assert(result.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right('\0');
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
        assert(result.length() == 0);
        assert(result.capacity() == 0);
    }    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right('x');
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|ax| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "ax");
        assert(left   == "a");
        assert(right  == "x");
        assert(result.length() == 2);
        assert(result.capacity() == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("x");
        
        // TEST
        String result = 'a' + right;
        
        // VERIFY
        std::cout << "|ax| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "ax");
        assert(right  == "x");
        assert(result.length() == 2);
        assert(result.capacity() == 2);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ab");
        String  right("xyz");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|abxyz| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abxyz");
        assert(left   == "ab");
        assert(right  == "xyz");
        assert(result.length() == 5);
        assert(result.capacity() == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("xy");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|abcxy| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        assert(result == "abcxy");
        assert(left   == "abc");
        assert(right  == "xy");
        assert(result.length() == 5);
        assert(result.capacity() == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1234567890/n!#$%^6YHd");
        String  right("1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "|1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        
	assert(result == "1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(left   == "1234567890/n!#$%^6YHd");
        assert(right  == "1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(result.length() == 255);
        assert(result.capacity() == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1548*1234567890/n!#$%^6YHd");
        String  right("1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        std::cout << "1548*|1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255| == |" << result << "| && length == " << result.length() << " && Capacity == " << result.capacity() << std::endl;
        
	assert(result == "1548*1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(left   == "1548*1234567890/n!#$%^6YHd");
        assert(right  == "1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(result.length() == 260);
        assert(result.capacity() == 260);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ab");
        String  right("xyz");

        // TEST
        left += right;

        // VERIFY
        std::cout << "|abxyz| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(right  == "xyz");
        assert(left == "abxyz");
        assert(left.length() == 5);
        assert(left.capacity() == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("");
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|abc| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left == "abc");
        assert(right  == "");
        assert(left.length() == 3);
        assert(left.capacity() == 3);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("xyz");
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|xyz| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left == "xyz");
        assert(right  == "xyz");
        assert(left.length() == 3);
        assert(left.capacity() == 3);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right;
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left   == "");
        assert(right  == "");
        assert(left.length() == 0);
        assert(left.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right('\0');
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left   == "");
        assert(right  == "");
        assert(left.length() == 0);
        assert(left.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right('x');
        
        // TEST
       left += right;
        
        // VERIFY
        std::cout << "|ax| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left == "ax");
        assert(right  == "x");
        assert(left.length() == 2);
        assert(left.capacity() == 2);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ab");
        String  right("xyz");
        
        // TEST
	left += right;
        
        // VERIFY
        std::cout << "|abxyz| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left == "abxyz");
        assert(right  == "xyz");
        assert(left.length() == 5);
        assert(left.capacity() == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("xy");
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|abcxy| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        assert(left == "abcxy");
        assert(right  == "xy");
        assert(left.length() == 5);
        assert(left.capacity() == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1234567890/n!#$%^6YHd");
        String  right("1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        
	assert(left == "1234567890/n!#$%^6YHd1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(right  == "1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(left.length() == 255);
        assert(left.capacity() == 255);
    }    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1234567890/n!#$%^6YHd");
        String  right("poju!1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        
        // TEST
        left += right;
        
        // VERIFY
        std::cout << "|1234567890/n!#$%^6YHpoju!d1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255| == |" << left << "| && length == " << left.length() << " && Capacity == " << left.capacity() << std::endl;
        
	assert(left == "1234567890/n!#$%^6YHdpoju!1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(right  == "poju!1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#\
$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567\
890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd 1234567890/n!#$%^6YHd \
123456789 0255");
        assert(left.length() == 260);
        assert(left.capacity() == 260);
    }
    
    std::cout << "Done testing operator+." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

