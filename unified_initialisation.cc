/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

#include <string>
#include <vector>

class Klass {
public:
  Klass(int x, const std::string &s) : _x(x), _s(s) {}

private:
  int _x{999};
  int _y = 1000;
  std::string _s;
};

int main(int, char **) {

  // simple initializing
  Klass k{123, "b"};
  int x{42};
  std::vector<int> v{1, 2, 3, 4};
  std::vector<int> y = {0, 1, 2, 3, 4};

  // initializing of aggregates
  struct Data {
    int a;
    double b;
    std::string c;
  };
  Data data{7, 3.14, "Seven Pies!"};
  // Data data2 {7.0, 3.14, "Seven Pies!"}; // Error narrowing from double to
  // int

  struct MyType {
    // der Konstruktor macht aus der Klasse
    // ein non-aggregate
    MyType(const std::string &msg, int x) : m_a(x), m_c(msg) {}
    int m_a;
    double m_b;
    std::string m_c;
  };
  MyType myType{"Hello World!", 42};

  return 0;

  // Example for a container-type
  struct Bar {
    explicit Bar(std::initializer_list<std::string> in) {
      for (auto &s : in)
        m_data.push_back("Bar " + s);
    }
    std::vector<std::string> m_data;
  };
  Bar bar{"A", "B", "C", "D"};
}
