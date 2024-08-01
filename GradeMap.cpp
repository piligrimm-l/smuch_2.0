#include <iostream>
#include <string>
#include <vector>

class GradeMap {
private:
  struct StudentGrade {
    std::string name;
    char grade;
  };

  std::vector<StudentGrade> m_map;

public:
  GradeMap() {}
  char& operator[] (const std::string &name) {
    for (auto &student : m_map) {
      if (student.name == name) {
        return student.grade;
      } 
    } 
    StudentGrade temp {name, ' '};
    m_map.push_back(temp);
    return m_map.back().grade;
  }
};

int main(void) {
  GradeMap grades;
  grades["John"] = 'A';
  grades["Martin"] = 'B';
  std::cout << "John has a grade of " << grades["John"] << '\n';
  std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

  return 0;
}
