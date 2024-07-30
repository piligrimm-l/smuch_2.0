#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car {
private:
  std::string m_company;
  std::string m_model;

public:
  Car(std::string company, std::string model)
    : m_company(company), m_model(model) {
  }

  friend bool operator== (const Car &c1, const Car &c2);
  friend bool operator!= (const Car &c1, const Car &c2);
  friend std::ostream& operator<< (std::ostream &out, const Car &c) {
    out << "(" << c.m_company << ", " << c.m_model << ")";
    return out;
  }

  friend bool operator< (const Car &c1, const Car &c2) {
    if (c1.m_company < c2.m_company)
      return true;
    if (c1.m_company > c2.m_company)
      return false;
    if (c1.m_model < c2.m_model)
      return true;
    if (c1.m_model > c2.m_model)
      return false;

    return false;
  }

};

bool operator== (const Car &c1, const Car &c2) {
  return (c1.m_company == c2.m_company && c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2) {
  return !(c1 == c2);
}

int main(void) {
  std::vector<Car> vc;
  vc.push_back(Car("Ford", "Mustang"));
  vc.push_back(Car("Renault", "Logan"));
  vc.push_back(Car("Ford", "Ranger"));
  vc.push_back(Car("Renault", "Duster"));

  std::sort(vc.begin(), vc.end());

  for (auto &car : vc)
    std::cout << car << '\n';

  return 0;
}
