#include <iostream>
#include <cassert>

class Fraction {
private:
  int m_numerator;
  int m_denominator;

public:
  Fraction(int numerator = 0, int denominator = 1)
    : m_numerator(numerator), m_denominator(denominator) {
      assert(m_denominator != 0 && "division by 0 is not possible");
      reduce();
    }

  static int nod(int a, int b) {
    int res = 0;
    if (b == 0) {
      res = a > 0 ? a : -a;
    } else {
      res = nod(b, a % b);
    }
    return res;
  }

  void reduce() {
    int nod = Fraction::nod(m_numerator, m_denominator);
    m_numerator /= nod;
    m_denominator /= nod;
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(int num, const Fraction &f);
  friend Fraction operator*(const Fraction &f, int num);
  friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
  friend std::istream& operator>>(std::istream &in, Fraction &f);

  void print() {
    std::cout << m_numerator << "/" << m_denominator << "\n";
  }

};

Fraction operator*(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(int num, const Fraction &f) {
  return Fraction(num * f.m_numerator, f.m_denominator);
}

Fraction operator*(const Fraction &f, int num) {
  return operator*(num, f);
}

std::ostream& operator<<(std::ostream &out, const Fraction &f) {
  out << f.m_numerator << "/" << f.m_denominator;
  return out;
}

std::istream& operator>>(std::istream &in, Fraction &f) {
  char div;
  in >> f.m_numerator;
  in >> div;
  in >> f.m_denominator;
  return in;
}

int main(void) {
  Fraction f1(3, 4);
  f1.print();

  Fraction f2(2, 7);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 3;
  f4.print();

  Fraction f5 = 3 * f2;
  f5.print();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();

  Fraction f7;
  std::cout << "Enter fraction 7: ";
  std::cin >> f7;

  Fraction f8;
  std::cout << "Enter fraction 8: ";
  std::cin >> f8;
  
  std::cout << f7 << " * " << f8 << " is " << f7 * f8 << '\n';

  return 0;
}
