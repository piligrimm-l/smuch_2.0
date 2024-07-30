#include <iostream>

class Something {
private:
  double m_a, m_b, m_c;

public:
  Something(double a = 0.0, double b = 0.0, double c = 0.0)
    : m_a(a), m_b(b), m_c(c) {
    m_a = m_a == -0 ? 0 : m_a;
    m_b = m_b == -0 ? 0 : m_b;
    m_c = m_c == -0 ? 0 : m_c;
  }

  Something operator-() const {
    return Something(-m_a, -m_b, -m_c);
  }

  Something operator+() const {
    return Something(m_a, m_b, m_c);
  }

  bool operator!() const {
    return (m_a == 0 && m_b == 0 && m_c == 0);
  }

  double getA() {return m_a;}
  double getB() {return m_b;}
  double getC() {return m_c;}

  friend std::ostream& operator<< (std::ostream &out, const Something &s) {
    out << "Something(" << s.m_a << ", " << s.m_b << ", " << s.m_c << ")";
    return out;
  }
};

int main(void) {
  Something something;
  Something s1(0.34, -32.91, 0.0);
  std::cout << s1 << '\n';
  Something s2 = -s1;
  std::cout << s2 << '\n';
  Something s3 = +s2;
  std::cout << s3 << '\n';

  if (!something)
    std::cout << "Something is null.\n";
  else 
    std::cout << "Something is not null.\n";

  return 0;
}
