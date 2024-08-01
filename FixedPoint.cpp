#include <iostream>
#include <iomanip>
#include <cmath>

class FixedPoint {
private:
  int16_t m_integer = 0;
  int8_t m_fracttional = 0;
  int m_sign;

public:
  explicit FixedPoint(int16_t integer = 0, int8_t fracttional = 0) noexcept {
    m_sign = ((integer >= 0) && (fracttional >= 0)) ? 1 : -1;
    m_integer = std::abs(integer);
    m_fracttional = std::abs(fracttional);
  }
  
  explicit FixedPoint(double dnum) noexcept {
    m_sign = dnum < 0 ? -1 : 1;
    dnum = std::fabs(dnum);
    m_integer = static_cast<int16_t>(dnum);
    m_fracttional = static_cast<int8_t>(std::round((dnum - m_integer) * 100)); 
  }

  FixedPoint(const FixedPoint &fp) {
    m_sign = fp.m_sign;
    m_integer = fp.m_integer;
    m_fracttional = fp.m_fracttional;
  }

  operator double();
  bool operator== (const FixedPoint &fp1);
  FixedPoint& operator- ();
  friend FixedPoint operator+ (FixedPoint &fp1, FixedPoint &fp2);
  friend std::istream& operator>> (std::istream& in, FixedPoint &fp);
  friend std::ostream& operator<< (std::ostream& out, const FixedPoint &fp);
};

FixedPoint::operator double() {
  return m_sign * (static_cast<double>(m_integer) +
          static_cast<double>((m_fracttional % 100) / 100.0));
}

bool FixedPoint::operator== (const FixedPoint &fp1) {
  return ((m_integer == fp1.m_integer) && (m_sign == fp1.m_sign) &&
          (m_fracttional == fp1.m_fracttional)); 
}

FixedPoint& FixedPoint::operator- () {
  m_sign *= -1; 
  return *this;
}

FixedPoint operator+ (FixedPoint &fp1, FixedPoint &fp2) {
  return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
}

std::istream& operator>> (std::istream& in, FixedPoint &fp) {
  std::cin >> 
  in >> fp.m_sign;
  in >> fp.m_integer;
  in >> fp.m_fracttional;
  return in;
}

std::ostream& operator<< (std::ostream& out, const FixedPoint &fp) {
  if (fp.m_sign < 0) {
    out << '-';
  }
  out << fp.m_integer << "." << std::setfill('0') <<
      std::setw(2) << static_cast<int16_t>(fp.m_fracttional % 100);
  return out;
}

void SomeTest() {
  std::cout << std::boolalpha;
  std::cout<<(FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98))<<'\n';
  std::cout<<(FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25))<<'\n';
  std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) <<
               '\n';
  std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) <<
               '\n';
  std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) <<
               '\n';
  std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) <<
               '\n';
  std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) <<
               '\n';
  std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) <<
               '\n';
}

int main(void) {
  FixedPoint a(37, 58);
  std::cout << a << '\n';
  FixedPoint b(-3, 9);
  std::cout << b << '\n';
  FixedPoint c(4, -7);
  std::cout << c << '\n';
  FixedPoint d(-5, -7);
  std::cout << d << '\n';
  FixedPoint e(0, -3);
  std::cout << e << '\n';
  std::cout << static_cast<double>(e) << '\n' << '\n';

  FixedPoint f(0.03);
  std::cout << f << '\n';
  FixedPoint g(-0.03);
  std::cout << g << '\n';
  FixedPoint h(4.01);
  std::cout << h << '\n';
  FixedPoint k(-4.01);
  std::cout << k << '\n' << '\n';
  
  SomeTest();
  FixedPoint l(-0.48);
  std::cout << l << '\n';
  std::cout << -l << '\n';
  std::cout << "Enter a number ";
  std::cin >> l;
  std::cout << "You entered: " << l << '\n';

  return 0;
}
