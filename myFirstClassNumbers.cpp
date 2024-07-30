#include <iostream>

class Numbers {
public:
  int m_num1;
  int m_num2;

  void set(int num1, int num2) {
    m_num1 = num1;
    m_num2 = num2;
  }

  void print() {
    std::cout << "Numbers (" << m_num1 << ", " << m_num2 << ")" << std::endl;
    //std::cout << "num1 = " << m_num1 << std::endl;
    //std::cout << "num2 = " << m_num2 << std::endl;
  }
};

int main(void) {

  Numbers n1;
  n1.set(3, 11);

  Numbers n2{ 98, 23 };

  n1.print();
  n2.print();

  return 0;
}
