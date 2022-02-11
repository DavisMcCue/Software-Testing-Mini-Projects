//  String class test program
//
//  Tests: String() - subscript
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

        // VERIFY
	assert(str == "");
	//assert(str[0] == '\0');
        assert(str.length() == 0);
        assert(str.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
	assert(str == 'a');
	assert(str[0] == 'a');
	//assert(str[1] == '\0');
        assert(str.length() == 1);
        assert(str.capacity() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("abc");

        // VERIFY
	assert(str == "abc");
	assert(str[0] == 'a');
	assert(str[1] == 'b');
	assert(str[2] == 'c');
	//assert(str[3] == '\0');
        assert(str.length() == 3);
        assert(str.capacity() == 3);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        const String  str("12");

        // VERIFY
	assert(str == "12");
	assert(str[0] == '1');
	assert(str[1] == '2');
	//assert(str[2] == '\0');
        assert(str.length() == 2);
        assert(str.capacity() == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
      String  str("dfudfdfsiffslji\nidsaihasdf;isd\t lsdkljasdljsd lkdssfoisdf65+ 2 +5 6+6 65 \r\t\n 5643179dskjasds  ()*^&*(^&^#) &^&*)JHKkkljbhkjBH KGkljGkljgh. JHGJ\
H8769345klndfbgsfds dfglkdffjdfs  0 09foihdfn8pojidfsg0d  0jmdf 0 lkd0785PSEDR8d j09 , 934kidfkfdgs    978TYER0g");

        // VERIFY
      assert(str == "dfudfdfsiffslji\nidsaihasdf;isd\t lsdkljasdljsd lkdssfoisdf65+ 2 +5 6+6 65 \r\t\n 5643179dskjasds  ()*^&*(^&^#) &^&*)JHKkkljbhkjBH KGkljGkljgh. JHGJ\
\
H8769345klndfbgsfds dfglkdffjdfs  0 09foihdfn8pojidfsg0d  0jmdf 0 lkd0785PSEDR8d j09 , 934kidfkfdgs    978TYER0g");
	assert(str[0] == 'd');
	assert(str[26] == ';');
	assert(str[101] == '^');
	assert(str[254] == 'g');
	//assert(str[255] == '\0');
        assert(str.length() == 255);
        assert(str.capacity() == 255);
    }

    std::cout << "Done testing subscript." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

