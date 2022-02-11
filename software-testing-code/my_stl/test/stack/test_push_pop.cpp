#include <cassert>
#include <iostream>
#include <stack.hpp>

//MIGHT NEED TO ADJUST THIS
#include <string.hpp>

int main() {

  {
    stack<int> stk;
    assert(stk.empty());
    
    stk.push(10);
    assert(stk.top() == 10);
    stk.push(2);
    assert(stk.top() == 2);
    stk.push(0);
    assert(stk.top() == 0);
    stk.push(15);
    assert(stk.top() == 15);
    
    stk.pop();
    assert(stk.top() == 0);
    stk.pop();
    assert(stk.top() == 2);
    stk.pop();
    assert(stk.top() == 10);
    stk.pop();

    assert(stk.empty());
  }

  {
    stack<char> stk;
    assert(stk.empty());

    stk.push('p');
    assert(stk.top() == 'p');
    stk.push('u');
    assert(stk.top() == 'u');
    stk.push('s');
    assert(stk.top() == 's');

    stk.pop();
    assert(stk.top() == 'u');
    stk.push('h');
    assert(stk.top() == 'h');
    stk.push('o');
    assert(stk.top() == 'o');

    stk.pop();
    assert(stk.top() == 'h');
    stk.pop();
    assert(stk.top() == 'u');
    stk.pop();
    assert(stk.top() == 'p');
    stk.pop();

    assert(stk.empty());
  }

  {
    stack<String> stk;
    assert(stk.empty());

    stk.push("one");
    assert(stk.top() == "one");
    stk.push("two");
    assert(stk.top() == "two");
    stk.push("abcdefghijklmnopqrs");
    assert(stk.top() == "abcdefghijklmnopqrs");

    stk.pop();
    assert(stk.top() == "two");
    stk.pop();
    assert(stk.top() == "one");
    stk.pop();

    stk.push("alligator");
    assert(stk.top() == "alligator");
    stk.push("!@#$%^&*()");
    assert(stk.top() == "!@#$%^&*()");
    
    stk.pop();
    assert(stk.top() == "alligator");
    stk.pop();
    
    assert(stk.empty());
  }

  std::cout << "Done testing push/pop \n";
}
