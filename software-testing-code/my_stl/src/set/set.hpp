#ifndef CS2_SET_HPP
#define CS2_SET_HPP

#include <iostream>

const int MAX = 64;

class set {

private:
    bool in_set[MAX];

public:
    set();
    set(int);
    set(int, int);
    set(int, int, int);

    set(std::initializer_list<int> init_list);

    bool operator[](int i) const;

    set operator+(const set & rhs) const;
    
    friend std::ostream & operator<<(std::ostream & out, const set & that);

//    friend std::istream & operator>>(std::istream & in, bigint & that);

};

set operator+(int, const set & rhs);

#endif
