/**
 *  @file testoracle_assign_resize.cpp
 *
 *  Tests operator= method when greater than capacity for String.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <cassert>
#include <string.hpp>
#include <vector>
#include <string.hpp>

#define print_assert(LEFT, RIGHT) if(!(LEFT == RIGHT)) std::cerr << '\'' << LEFT << "' == '" << RIGHT << "'\n"; assert(LEFT == RIGHT);


#define print_assert_op(LEFT, RIGHT, OP) if(!(LEFT OP RIGHT)) std::cerr << '\'' << LEFT << "' " << #OP << " '" << RIGHT << "'\n"; assert(LEFT OP RIGHT);

int main() {
   {
     String str("a--b");
    print_assert(str, "a--b");
    print_assert(str.length(), 4);
    print_assert(str.capacity(), 4);

    std::vector<String> words = str.split('-');
    std::vector<std::string> oracle { "a", "", "b" };

    print_assert(words.size(), oracle.size());
  }
  {
    String str("-a--b");
    print_assert(str, "-a--b");
    print_assert(str.length(), 5);
    print_assert(str.capacity(), 5);

    std::vector<String> words = str.split('-');
    std::vector<std::string> oracle { "", "a", "", "b" };

    print_assert(words.size(), oracle.size());
  }
  {
    String str("$a$$b$");
    print_assert(str, "$a$$b$");
    print_assert(str.length(), 6);
    print_assert(str.capacity(), 6);

    std::vector<String> words = str.split('$');
    std::vector<std::string> oracle { "", "a", "", "b", "" };

    print_assert(words.size(), oracle.size());
  }
  {
    String str("time will tell...");
    print_assert(str, "time will tell...");
    print_assert(str.length(), 17);
    print_assert(str.capacity(), 17);

    std::vector<String> words = str.split('&');
    std::vector<std::string> oracle { "time will tell..." };

    print_assert(words.size(), oracle.size());
  }
  {
    String str;
    print_assert(str, "");
    print_assert(str.length(), 0);
    print_assert(str.capacity(), 0);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "" };

    print_assert(words.size(), oracle.size());
  }

  {
    String str("O");
    print_assert(str, "O");
    print_assert(str.length(), 1);
    print_assert(str.capacity(), 1);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "O" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("Come,");
    print_assert(str, "Come,");
    print_assert(str.length(), 5);
    print_assert(str.capacity(), 5);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "Come," };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("Come,");
    print_assert(str, "Come,");
    print_assert(str.length(), 5);
    print_assert(str.capacity(), 5);

    std::vector<String> words = str.split(',');
    std::vector<std::string> oracle { "Come", "" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("O Come, O Come Emannuel");
    print_assert(str, "O Come, O Come Emannuel");
    print_assert(str.length(), 23);
    print_assert(str.capacity(), 23);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "O", "Come,", "O", "Come", "Emannuel" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("O Come, O Come Emannuel");
    print_assert(str, "O Come, O Come Emannuel");
    print_assert(str.length(), 23);
    print_assert(str.capacity(), 23);

    std::vector<String> words = str.split(',');
    std::vector<std::string> oracle { "O Come", " O Come Emannuel" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("abc ef gh");
    print_assert(str, "abc ef gh");
    print_assert(str.length(), 9);
    print_assert(str.capacity(), 9);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "abc", "ef", "gh" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("131.123.32.16 - - [18/Sep/2002:12:06:12 -0400] \"GET /~collard/class/oop/master.css HTTP/1.1\" 200 791");
    print_assert(str, "131.123.32.16 - - [18/Sep/2002:12:06:12 -0400] \"GET /~collard/class/oop/master.css HTTP/1.1\" 200 791");
    print_assert(str.length(), 100);
    print_assert(str.capacity(), 100);

    std::vector<String> words = str.split(' ');
    std::vector<std::string> oracle { "131.123.32.16", "-", "-", "[18/Sep/2002:12:06:12", "-0400]",
					"\"GET", "/~collard/class/oop/master.css", "HTTP/1.1\"",
					"200", "791"};

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  {
    String str("a\nb\nc\nd");

    print_assert(str, "a\nb\nc\nd");

    print_assert(str.length(), 7);
    print_assert(str.capacity(), 7);

    std::vector<String> words = str.split('\n');
    std::vector<std::string> oracle { "a", "b", "c", "d" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  std::cerr << "Passed all except part2 + part3\n";

  {
    String str(
   "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625\n"
   "198.143.205.166 - - [18/Sep/2002:12:06:06 -0400] \"GET /~reichel/b.jpg HTTP/1.1\" 200 16514\n"
   "24.203.197.200 - - [18/Sep/2002:12:06:46 -0400] \"GET /~jkuleck/bannerbar.gif HTTP/1.1\" 304 -\n"
   "4.19.70.66 - - [18/Sep/2002:12:07:34 -0400] \"GET /~ydrabu/ HTTP/1.0\" 200 483");

    print_assert(str,
   "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625\n"
   "198.143.205.166 - - [18/Sep/2002:12:06:06 -0400] \"GET /~reichel/b.jpg HTTP/1.1\" 200 16514\n"
   "24.203.197.200 - - [18/Sep/2002:12:06:46 -0400] \"GET /~jkuleck/bannerbar.gif HTTP/1.1\" 304 -\n"
   "4.19.70.66 - - [18/Sep/2002:12:07:34 -0400] \"GET /~ydrabu/ HTTP/1.0\" 200 483");

    print_assert(str.length(), 340);
    print_assert(str.capacity(), 340);

    std::vector<String> words = str.split('\n');
    std::vector<std::string> oracle { 
    "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625",
    "198.143.205.166 - - [18/Sep/2002:12:06:06 -0400] \"GET /~reichel/b.jpg HTTP/1.1\" 200 16514",
    "24.203.197.200 - - [18/Sep/2002:12:06:46 -0400] \"GET /~jkuleck/bannerbar.gif HTTP/1.1\" 304 -",
    "4.19.70.66 - - [18/Sep/2002:12:07:34 -0400] \"GET /~ydrabu/ HTTP/1.0\" 200 483" };

    print_assert(words.size(), oracle.size());
    for(size_t pos = 0; pos < words.size(); ++pos) {

      print_assert(words[pos], oracle[pos].c_str());
      print_assert((size_t)words[pos].length(), oracle[pos].size());

    }

  }

  std::cerr << "Passed all split tests\n";

  return 0;
}
