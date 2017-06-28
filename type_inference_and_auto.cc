/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

#include <vector>

// Neue Syntax für Funktionsdeklaration mit
// nachgestelltem Rückgabetyp
auto fac(int n) -> int { return n <= 1 ? 1 : n * fac(n - 1); }

int main(int, char **) {
  auto x = 42; // x wird ein int
               // x = "Hallo"; // Error, da x kein char* ist
  std::vector<int> vec{1000, 1001, 1002, 1003};
  auto it0 = vec.begin();  // auto ist vector<T>::iterator
  auto st0(vec[4]);        // int
  auto &st1 = vec[4];      // int&
  const auto &s1 = vec[4]; // const int&
  auto it1 = vec.cbegin(); // vector<int>::const_iterator
  auto sil{vec[4]};        // std:initializer_list<int>
}
