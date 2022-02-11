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
        assert(str.length() == 0);
        assert(str.capacity() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('\0');

        // VERIFY
	assert(str == "");
        assert(str.length() == 0);
        assert(str.capacity() == 0 || str.capacity() == 1);
    }    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
	assert(str == 'a');
        assert(str.length() == 1);
        assert(str.capacity() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        const String  str(" 1\n2 ");

        // VERIFY
	assert(str == " 1\n2 ");
        assert(str.length() == 5);
        assert(str.capacity() == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("abc98#%$% ");

        // VERIFY
	assert(str == "abc98#%$% ");
        assert(str.length() == 10);
        assert(str.capacity() == 10);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("\t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n @");

        // VERIFY
	assert(str == "\t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n \t_oe^ H0\n @");
        assert(str.length() == 101);
        assert(str.capacity() == 101);
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
        assert(str.length() == 255);
        assert(str.capacity() == 255);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
      String  str("hygtfdfudfdfsiffslji\nidsaihasdf;isd\t lsdkljasdljsd lkdssfoisdf65+ 2 +5 6+6 65 \r\t\n 5643179dskjasds  ()*^&*(^&^#) &^&*)JHKkkljbhkjBH KGkljGkljgh.JHGJH8769345klndfbgsfds dfglkdffjdfs  0 09foihdfn8pojidfsg0d  0jmdf 0 lkd0785PSEDR8d j09 , 934kidfkfdgs    5978TYER0g");

        // VERIFY
      assert(str == "hygtfdfudfdfsiffslji\nidsaihasdf;isd\t lsdkljasdljsd lkdssfoisdf65+ 2 +5 6+6 65 \r\t\n 5643179dskjasds  ()*^&*(^&^#) &^&*)JHKkkljbhkjBH KGkljGkljgh.\
JHGJH8769345klndfbgsfds dfglkdffjdfs  0 09foihdfn8pojidfsg0d  0jmdf 0 lkd0785PSEDR8d j09 , 934kidfkfdgs    5978TYER0g");
        assert(str.length() == 260);
        assert(str.capacity() == 260);
    }
    
    std::cout << "Done testing subscript." << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    return 0;
}

