/**
* Example for section 2.19
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the use of structured bindings
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <array>
#include <map>
#include <tuple>
//@40
struct Packed {
  int x;
  char y;
  float z;
};

class cls {
public:
  int m;
  float n;
};
//@40
int main() {
//@40
  auto tuple = std::make_tuple(1, 'a', 2.3);
  std::array<int, 3> a{1, 2, 3};
  Packed p;
  cls cl;

  // unpack the tuple into individual variables declared above
  const auto[i, c, d] = tuple;
  // also works with references
  auto & [ ref_i, ref_c, ref_d ] = tuple;

  // fixed size array also works
  auto[j, k, l] = a;

  // structs and classes can also be bound
  auto & [ x, y, z ] = p;
  auto[m, n] = cl;

  // extracting key & value at the same time from a map
  std::map<int, float> map;
  for (auto && [ k, v ] : map) {
    // do something
  }
//@40
  return 0;
}
