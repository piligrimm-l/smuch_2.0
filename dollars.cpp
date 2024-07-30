#include <iostream>

class Dollars {
private:
  int m_dollars;

public:
  Dollars(int dollars = 0) : m_dollars(dollars) {
  }

  friend bool operator> (const Dollars &d1, const Dollars &d2);
  friend bool operator< (const Dollars &d1, const Dollars &d2);
  friend bool operator>= (const Dollars &d1, const Dollars &d2);
  friend bool operator<= (const Dollars &d1, const Dollars &d2);
  friend bool operator== (const Dollars &d1, const Dollars &d2);
  friend bool operator!= (const Dollars &d1, const Dollars &d2);
};

bool operator> (const Dollars &d1, const Dollars &d2) {
  return d1.m_dollars > d2.m_dollars;
}

bool operator< (const Dollars &d1, const Dollars &d2) {
  return d1.m_dollars < d2.m_dollars;
}

bool operator>= (const Dollars &d1, const Dollars &d2) {
  return !(d1 < d2);
}

bool operator<=(const Dollars &d1, const Dollars &d2) {
  return !(d1 > d2);
}

bool operator== (const Dollars &d1, const Dollars &d2) {
  return d1.m_dollars == d2.m_dollars;
}

bool operator!= (const Dollars &d1, const Dollars &d2) {
  return !(d1 == d2);
}

int main(void) {
  Dollars ten(10);
  Dollars seven(7);

  if (ten > seven)
    std::cout << "Ten dollars are greater than seven dollars.\n";
  if (ten >= seven)
    std::cout << "Ten dollars are greater than or equal to seven dollars.\n";
  if (ten < seven)
    std::cout << "Seven dollars are greater than ten dollars.\n";
  if (ten <= seven)
    std::cout << "Seven dollars are greater than or equal to ten dollars.\n";
  if (ten == seven)
    std::cout << "Ten dollars are equal to seven dollars.\n";
  if (ten != seven)
    std::cout << "Ten dollars are not equal to seven dollars.\n";

  return 0;
}
