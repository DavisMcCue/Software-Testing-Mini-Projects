#include <cassert>
#include <iostream>
#include <stack.hpp>

//MIGHT NEED TO ADJUST THIS
#include <string.hpp>

int main() {

  {
    stack<int> stk;
    assert(stk.empty());
  }

  {
    stack<char> stk;
    stk.push('a');
    assert(!stk.empty());
  }

  std::cout << "Done testing empty\n";
}
