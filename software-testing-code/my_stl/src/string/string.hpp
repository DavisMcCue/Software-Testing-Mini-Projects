/**
 * @file string-interface.hpp
 *
 * @version 1.0
 * @date Spring 2017
 * @authors Dr. J. Maletic and Michael John Decker
 *
 * Interface definition of String class for use with test oracle.
 * For use with Project 2, milestone 2, 3, 4.
 *
 * To use the supplied test oracles you will need to use this interface and namings.
 * You must also have all of these methods and functions defined for your string class.
 *
 * You can NOT add any attributes/members.  If you do the test oracles will not work.
 *
 * You need to implement all of the methods and funcitons declared here.
 */

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <vector>
/**
 * @invariant str[length()] == 0
 *         && length()      == capacity()
 *         && capacity()    == stringSize - 1
 */
class String {
private:
    // helper constructors and methods
    String(int);
    String(int, const char *);
    void reset_capacity (int);

    char * str;

    // size includes NULL terminator
    int string_size;

public:

    // constructor: empty string, String('x'), and String("abcd")
    String();
    String(char);
    String(const char *);

    // copy ctor, destructor, constant time swap, and assignment
    String(const String &);
    ~String();
    void     swap          (String &);
    String & operator=     (String);

    // subscript: accessor/modifier and accessor
    char & operator[](int);
    char   operator[](int) const;

    // max chars that can be stored (not including null terminator)
    int capacity()      const;
    // number of char in string
    int length  ()      const;
    
    // substring
    String substr(int start_pos, int count) const;
    
    // split a string with char delimiter
    std::vector<String> split(char) const;

    // find char / string index
    int find(char ch, int start_pos) const;
    int find(const String & s, int start_pos) const;

    // concatenation
    String   operator+ (const String &) const;
    String & operator+=(String);

    // relational methods
    bool operator==(const String &)  const;
    bool operator< (const String &)  const;

    // i/o
    friend std::ostream& operator<<(std::ostream &, const String &);
    friend std::istream& operator>>(std::istream &, String &);

};

// free functios for concatenation and relational
String operator+       (const char *,   const String &);
String operator+       (char,           const String &);
bool   operator==      (const char *,   const String &);
bool   operator==      (char,           const String &);
bool   operator<       (const char *,   const String &);
bool   operator<       (char,           const String &);
bool   operator<=      (const String &, const String &);
bool   operator!=      (const String &, const String &);
bool   operator>=      (const String &, const String &);
bool   operator>       (const String &, const String &);

#endif
