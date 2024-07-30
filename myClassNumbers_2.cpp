#include <iostream>

class Numbers {
  double m_a;
  double m_b; 
  double m_c;

public:
  void setValues(double a, double b, double c) {
    m_a = a;
    m_b = b;
    m_c = c;

    return;
  }

  void print() {
    std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << std::endl;

    return;
  }
  
  bool isEqual(const Numbers& N) {
    if (m_a == N.m_a && m_b == N.m_b && m_c == N.m_c) {
      return true;
    } else {
      return false;
    }
  }

};

int main(void) {

  Numbers point;

  point.setValues(3.0, 4.0, 5.0);
  point.print();

  Numbers point1;
  point1.setValues(3.0, 4.0, 5.0);

  Numbers point2;
  point2.setValues(3.0, 4.0, 5.0);

  if (point1.isEqual(point2)) {
    std::cout << "point1 and point2 are equal\n";
  } else {
    std::cout << "point1 and point2 are not equal\n";
  }

  Numbers point3;
  point3.setValues(7.0, 8.0, 9.0);

  if (point1.isEqual(point3)) {
    std::cout << "point1 and point3 are equal\n";
  } else {
    std::cout << "point1 and point3 are not equal\n";
  }

  return 0;
}
