#include <iostream>

class Average {
private:
  int32_t m_sum = 0;
  int8_t m_count = 0; 

public:
  Average() : m_sum(0), m_count(0) {
  }

  Average& operator+= (const int num) {
    m_sum += num;
    ++m_count;
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& out, const Average &a1) {
    out << static_cast<double>(a1.m_sum) / a1.m_count;
    return out;
  }
};

int main(void) {
  Average avg;

  avg += 5;
  std::cout << avg << '\n';

  avg += 9;
  std::cout << avg << '\n';

  avg += 20;
  std::cout << avg << '\n';
  
  avg += -9;
  std::cout << avg << '\n';

  (avg += 7) += 11;
  std::cout << avg << '\n';
  
  Average copy = avg;
  std::cout << copy << '\n';

  return 0;
}
