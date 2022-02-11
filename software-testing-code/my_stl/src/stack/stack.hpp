#ifndef STACK_HPP
#define STACK_HPP

#include <cassert>
#include <new>

template<typename T>
class node {

public:
  node<T>* next;
  T data;

  node(): next(nullptr) {}
  node(T value): next(nullptr), data(value) {}
  node(node<T>* n, T value): next(n), data(value) {}
};

template<typename T>
class stack {

private:
  node<T>* tos;

public:

  stack() : tos(nullptr) {}

  stack(const stack<T> & copy) {
    tos = nullptr;
    node<T>* tos_next = nullptr;

    node<T>* tmp = copy.tos;

    if (tmp != nullptr) {
      tos = new node<T>(nullptr, tmp->data);
      tos_next = tos;
      tmp = tmp->next;
    }

    while (tmp != nullptr) {
      tos_next->next = new node<T>(nullptr, tmp->data);
      tos_next = tos_next->next;
      tmp = tmp->next;
    }
  }

  ~stack() {
    while (tos != nullptr) {
      pop();
    }
  }

  void swap(stack<T> & s) {
    node<T>* tmp = s.tos;
    s.tos = tos;
    tos = tmp;
  }

  stack<T> & operator=(stack<T> rhs) {
    swap(rhs);
    return *this;
  }

  /** @pre non-full stack */
  void push(const T& object) {
    assert(!full());
    
    node<T>* tmp = new node<T>(tos, object);
    tos = tmp;
  }

  /** @pre non-empty stack */
  void pop() {
    node<T>* tmp = tos;
    tos = tos->next;
    delete tmp;
  }

  /** @pre non-empty stack */
  T top() const {
    assert(tos != nullptr);
    return tos->data;
  }
  
  /** @pre non-empty stack */
  T & top() {
    assert(tos != nullptr);
    return tos->data;
  }

  bool empty() const {
    return tos == nullptr;
  }

  bool full() const {
    node<T>* n = new(std::nothrow) node<T>;
    if(n == nullptr) { return true; }

    delete n;
    return false;
  }
};

#endif
