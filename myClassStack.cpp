#include <iostream>
//#define NDEBUG
#include <cassert>

class Stack {
  int m_array_numbers[10];
  int m_end_index;

public:
  void reset() {
    for (int i = 0; i != 10; ++i) {
      m_array_numbers[i] = 0;
    }
    m_end_index = 0;
  }

  bool push(int num) {
    if (m_end_index >= 0 && m_end_index < 10) {
      m_array_numbers[m_end_index] = num;
      ++m_end_index;
      return true;
    } else {
      return false;
    }
  }

  int pop() {
    if (m_end_index) {
      return m_array_numbers[--m_end_index]; 
    } else {
      assert(m_end_index != 0 && "The stack is empty");
      return 0;
    }
  }

  void print() {
    std::cout << "( ";
    for (int i = 0; i != m_end_index; ++i) {
      std::cout << m_array_numbers[i] << " ";
    }
    std::cout << ")\n";
  }
  
};

int main(void) {

  Stack stack;
  stack.reset();

  stack.print();

  stack.push(3);
  stack.push(5);
  stack.push(7);
  stack.print();
  
  stack.pop();
  stack.print();

  stack.pop();
  stack.pop();

  stack.print();

  //stack.pop();

  return 0;
}
