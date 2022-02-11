#include <cassert>
#include <iostream>
#include <stack.hpp>

//MIGHT NEED TO ADJUST THIS
#include <string.hpp>

int main() {

  {
    stack<int> stk;
    stack<int> stk2;
    stk2.push(10);
    assert(stk2.top() == 10);
    stk2.push(12);
    assert(stk2.top() == 12);

    stk = stk2;
    
    assert(stk2.top() == 12);
    assert(stk.top() == 12);
    stk.pop();
    stk2.pop();
    assert(stk2.top() == 10);
    assert(stk.top() == 10);
    stk.pop();
    stk2.pop();

    assert(stk.empty());
    assert(stk2.empty());
  }

  {
    stack<char> stk;
    stack<char> stk2;
    stk.push('a');
    assert(stk.top() == 'a');
    stk.push('b');
    assert(stk.top() == 'b');

    stk2.push('c');
    assert(stk2.top() == 'c');
    stk2.push('d');    
    assert(stk2.top() == 'd');
    stk2.push('e');
    assert(stk2.top() == 'e');

    stk2 = stk;

    assert(stk2.top() == 'b');
    assert(stk.top() == 'b');
    stk2.pop();
    stk.pop();
    assert(stk2.top() == 'a');
    assert(stk.top() == 'a');
    stk2.pop();
    stk.pop();
    
    assert(stk.empty());
    assert(stk2.empty());
  }

  std::cout << "Done testing assign\n";
}
