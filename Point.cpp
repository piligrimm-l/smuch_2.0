#include <iostream>
#include <cmath>

class Point {
private:
  double m_a = 0.0;
  double m_b = 0.0;

public:
  Point(double a = 0.0, double b = 0.0) : m_a(a), m_b(b) {
  }
  void print() {
    std::cout << "Point(" << m_a << ", " << m_b << ")\n";
  }
  double distanceTo(const Point &point) {
    return sqrt(pow(m_a - point.m_a, 2) + pow(m_b - point.m_b, 2));
  }
  friend double distanceFrom(const Point &p1, const Point &p2);
};

double distanceFrom(const Point &p1, const Point &p2) {
  return sqrt(pow(p1.m_a - p2.m_a, 2) + pow(p1.m_b - p2.m_b, 2));
}

int main(void) {
  Point first;
  Point second(2.0, 5.0);
  first.print();
  second.print();
  std::cout << "Distance between two points (distanceTo()): " <<
               first.distanceTo(second) << '\n';
  std::cout << "Distance between two points (distanceFrom()): " <<
                distanceFrom(first, second) << '\n';
  return 0;
}
