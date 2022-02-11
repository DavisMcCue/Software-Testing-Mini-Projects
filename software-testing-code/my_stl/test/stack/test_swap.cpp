#include <cassert>
#include <iostream>
#include <stack.hpp>

//MIGHT NEED TO ADJUST THIS
#include <string.hpp>

int main() {

  {
    stack<int> stk;
    assert(stk.empty());

    stack<int> stk2;
    stk2.push(67);
    assert(stk2.top() == 67);
    stk2.push(7);
    assert(stk2.top() == 7);

    stk.swap(stk2);
    
    assert(stk2.empty());
    
    assert(stk.top() == 7);
    stk.pop();
    assert(stk.top() == 67);
    stk.pop();
    
    assert(stk.empty());
  }

  {
    stack<char> stk;
    assert(stk.empty());

    stack<char> stk2;
    stk.swap(stk2);

    assert(stk.empty() && stk2.empty());
  }

  {
    stack<String> stk;
    assert(stk.empty());
    
    stk.push("Food");
    assert(stk.top() == "Food");
    stk.push("Dinner");
    assert(stk.top() == "Dinner");
    stk.push("Lunch");
    assert(stk.top() == "Lunch");

    stack<String> stk2;

    stk2.push("Run");
    assert(stk2.top() == "Run");
    stk2.push("Jump");
    assert(stk2.top() == "Jump");

    stk.swap(stk2);

    assert(stk.top() == "Jump");
    assert(stk2.top() == "Lunch");
    stk.pop();
    stk2.pop();
    assert(stk.top() == "Run");
    assert(stk2.top() == "Dinner");
    stk.pop();
    stk2.pop();
    assert(stk.empty());
    assert(stk2.top() == "Food");
    stk2.pop();
    assert(stk2.empty());
  }

  std::cout << "Done testing swap\n";
}
