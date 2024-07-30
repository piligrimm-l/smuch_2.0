#include <iostream>

class Welcome {
  private:
    char* m_data;

  public:
    Welcome(){
      m_data = new char[14];
      const char* init = "Hello, World!";
      for (int i = 0; i != 14; ++i) {
        m_data[i] = init[i];
      }
    }
    ~Welcome() {
      if (m_data) {
        delete[](m_data);
        m_data = nullptr;
      }
    }
    void print() {
      std::cout << m_data << '\n';
    }
};

int main(void) {
  Welcome hello;
  hello.print();
  return 0;
}
