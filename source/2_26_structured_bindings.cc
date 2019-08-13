/**
* Example for section 2.26
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
* This example illustrates the use of structured bindings
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <array>
#include <map>
#include <tuple>
#include <vector>
//@39
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

//@39

// this illustrates how to make a class support structured bindings
class Bindable
{
  public:
    template<std::size_t N>
    decltype(auto) get() const {

      // note the changing of the type from std::string to const char* for the 2nd parameter
      // of returning a reference to the vector
      if constexpr (N == 0) return x;
      else if constexpr (N == 1) return msg.c_str();
      else if constexpr (N == 2) return (v);

    }
  private:
    int x{123};
    std::string msg{"ABC"};
    std::vector<int> v{1,2,3};
};
/// template specialisation for class Bindable
namespace std{
  template<>
  struct tuple_size<Bindable> : std::integral_constant<std::size_t, 3> {};

  template<std::size_t N>
  struct tuple_element<N, Bindable> {
    using type = decltype(std::declval<Bindable>().get<N>());
  };

}

int main() {
//@39
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
//@39

  Bindable b;
  const auto [ii, jj, kk] = b;
  return 0;
}
