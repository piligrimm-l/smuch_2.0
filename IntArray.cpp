#include <iostream>
#include <cassert>

class IntArray {
private:
  int m_sizeArray = 0;
  int* m_array = nullptr;

public:
  IntArray(const int sizeArray = 0)
    : m_sizeArray{sizeArray}, m_array{nullptr} {
      assert(m_sizeArray > 0);
      if (m_sizeArray) {
        m_array = new int[m_sizeArray] {0};
      }
  }

  IntArray(const IntArray &ia) {
    m_array = new int[ia.m_sizeArray] {0};

    for (int i = 0; i != m_sizeArray; ++i) {
      m_array[i] = ia.m_array[i];
    }
  }

  ~IntArray() {
    if (m_array) {
      delete[] m_array;
    }
  }

  int& operator[] (const int index) {
    assert(index >= 0 && index < m_sizeArray);
    return m_array[index];
  }

  IntArray& operator= (const IntArray &ia) {
    if (this == &ia) 
      return *this;

    if (m_sizeArray != ia.m_sizeArray) {
      m_sizeArray = ia.m_sizeArray;
      delete[] m_array;
      m_array = new int[m_sizeArray];
    } 
    for (int i = 0; i != m_sizeArray; ++i) {
      m_array[i] = ia.m_array[i];
    }
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& out, const IntArray &ia) {
    for (int i = 0; i != ia.m_sizeArray; ++i) {
      out << ia.m_array[i] << ' ';
    }
    return out;
  }
};

IntArray fillArray() {
  IntArray a(6);
  a[0] = 6;
  a[1] = 7;
  a[2] = 3;
  a[3] = 4;
  a[4] = 5;
  a[5] = 8;

  return a;
}

int main(void) {
  IntArray a = fillArray();
  std::cout << a << '\n';

  IntArray b(1);
  a = a;
  b = a;

  std::cout << b << '\n';

  return 0;
}
