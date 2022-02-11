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
    stk.push(123);
    assert(stk.top() == 123);

    stack<int> stk2(stk);
    stk2.push(8);
    assert(stk2.top() == 8);

    stk2.pop();
    assert(stk2.top() == 123);
    stk2.pop();
    assert(stk2.top() == 10);
    stk2.pop();
    assert(stk2.empty());
    assert(!stk.empty());

    assert(stk.top() == 123);
    stk.pop();
    assert(stk.top() == 10);
    stk.pop();
    assert(stk.empty());
  }

  {
    stack<char> stk;
    assert(stk.empty());

    stack<char> stk2(stk);
    assert(stk2.empty() && stk.empty());

  }

  {
    stack<String> stk;
    assert(stk.empty());

    stk.push("Winner!");
    assert(stk.top() == "Winner!");
    stk.push("Chicken");
    assert(stk.top() == "Chicken");
    stk.push("Dinner");
    assert(stk.top() == "Dinner");
    stk.push("Time");
    assert(stk.top() == "Time");

    const stack<String> stk2(stk);

    assert(stk2.top() == "Time");
    assert(stk.top() == "Time");

    stk.pop();
    assert(stk.top() == "Dinner");
    stk.pop();
    assert(stk.top() == "Chicken");
    stk.pop();
    assert(stk.top() == "Winner!");
    stk.pop();
    
    assert(stk.empty());
  }

  std::cout << "Done testing ctor copy\n";
}
