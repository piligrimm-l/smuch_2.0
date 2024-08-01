#include <iostream>
#include <string>
#include <cassert>

class MyString {
private:
  std::string m_str;

public:
  MyString(const std::string &str = "") : m_str{str} {
  }

  std::string operator() (const int index, const int lensubstr) {
    std::string retstr;
    int lenstr = m_str.size();
    assert(index >= 0 && index <= lenstr && lensubstr >= 0 &&
           index + lensubstr <= lenstr);
    for (int i = index; i != index + lensubstr; ++i) {
      retstr += m_str[i];
    }  
    return retstr + '\n';
  }
}; 

int main(void) {
  MyString string("Hello, world!");
  std::cout << string(7, 6);
  return 0;
}
