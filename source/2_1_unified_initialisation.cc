/**
* Example for section 2.1  
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the unified syntax for initializing stuff in
* C++11/14/17
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <string>
#include <vector>

//@bsp 5
struct Klass {
public:
  Klass(int x, const std::string &s) : _x(x), _s(s) {}

private:
  // initialisation can be specified at the time of declaration

  int _x{999};   // Value assignement through construction
  int _y = 1000; // value assignment
  std::string _s;
};
//@bsp 5

int main(int, char **) {


//@bsp 1
  // simple initializing using {}
  Klass k{123, "b"};
  int x{42};

  std::vector<int> v{1, 2, 3, 4}; // list initialisation
  std::vector<int> y = {0, 1, 2, 3, 4};

#ifdef EXPECT_FAILED_COMPILATION
  int fail{7.5f}; // fails because of narrowing down from float to int
#endif

//@bsp 1


//@bsp 2
// initializing of aggregates
  struct Data {
    int a{0};
    double b{0};
    std::string c;
  };
  Data data{7, 3.14, "Seven Pies!"};
#ifdef EXPECT_FAILED_COMPILATION
  // Error narrowing from double to int
  Data data2{7.0, 3.14, "Seven Pies!"};
#endif

//@bsp 2

//@bsp 3
  struct MyType {
    // the constructor makes a non-aggregate out of this struct
    MyType(const std::string &msg, int x) : m_a(x), m_c(msg) {}
    int m_a;
    double m_b;
    std::string m_c;
  };
  MyType myType{"Fortytwo!", 42};

//@bsp 3

//@bsp 4
  // Example for a container-type with explicit list initialisation
  struct Bar {
    explicit Bar(std::initializer_list<std::string> in) {
      for (auto &s : in)
        m_data.push_back("Bar " + s);
    }
    std::vector<std::string> m_data;
  };
  Bar bar{"A", "B", "C", "D"};
//@bsp 4
}
