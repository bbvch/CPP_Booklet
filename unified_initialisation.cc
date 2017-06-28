/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
* This example illustrates the unified syntax for initializing stuff in
*C++11/14/17
**/

#include <string>
#include <vector>

class Klass {
public:
  Klass(int x, const std::string &s) : _x(x), _s(s) {}

private:
  // initialisation can be specified at the time of declaration

  int _x{999};   // Value assignement through construction
  int _y = 1000; // values assignment
  std::string _s;
};

int main(int, char **) {

  // simple initializing usion {}
  Klass k{123, "b"};
  int x{42};

#ifdef EXPECT_FAILED_COMPILATION
  int fail{7.5f}; // fails because of narrowing down from floata to int
#endif
  std::vector<int> v{1, 2, 3, 4}; // list initialisation
  std::vector<int> y = {0, 1, 2, 3, 4};

  // initializing of aggregates
  struct Data {
    int a;
    double b;
    std::string c;
  };
  Data data{7, 3.14, "Seven Pies!"};
#ifdef EXPECT_FAILED_COMPILATION
  // Error narrowing from double to int
  Data data2{7.0, 3.14, "Seven Pies!"};
#endif

  struct MyType {
    // the constructor makes a non-aggregate out of this struct
    MyType(const std::string &msg, int x) : m_a(x), m_c(msg) {}
    int m_a;
    double m_b;
    std::string m_c;
  };
  MyType myType{"Fortytwo!", 42};

  // Example for a container-type with explicit list initialisation
  struct Bar {
    explicit Bar(std::initializer_list<std::string> in) {
      for (auto &s : in)
        m_data.push_back("Bar " + s);
    }
    std::vector<std::string> m_data;
  };
  Bar bar{"A", "B", "C", "D"};
}
