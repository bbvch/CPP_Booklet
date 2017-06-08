#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T> class NameByType {
public:
  std::string to_string() {
    if
      constexpr(std::is_pointer<T>::value) { return "Pointer"; }
    else if
      constexpr(std::is_integral<T>::value) { return "Integral"; }
    else if
      constexpr(std::is_same<T, float>::value) { return "Float"; }
    else {
      return "Unknown";
    }
  }
};

class MixedStorage {
public:
  template <std::size_t N> auto access() {
    if
      constexpr(N == 0) { return a; }
    if
      constexpr(N == 1) { return b; }
    if
      constexpr(N == 2) { return c; }
    if
      constexpr(N == 3) { return d; }
    else if
      constexpr(N > 3) { // Condition needs explicit specification or else
                         // return type cannot be deducted correctly
        std::array<int, N> r;
        int seed = 0;
        for (auto &i : r) {
          i = seed++;
        }
        return std::move(r);
      }
  }

private:
  int a = 1000;
  char b = 64;
  std::string c{"Hello world"};
  std::vector<char> d{'a', 'b', 'c', 'd'};
};

int main(int argc, char **argv) {

  std::cout << NameByType<int>().to_string() << std::endl;         // Integral
  std::cout << NameByType<char *>().to_string() << std::endl;      // Pointer
  std::cout << NameByType<float>().to_string() << std::endl;       // Float
  std::cout << NameByType<std::string>().to_string() << std::endl; // Unknown

  std::cout << std::endl;
  MixedStorage store;
  std::cout << store.access<0>() << std::endl; // 1000
  std::cout << store.access<1>() << std::endl; // 64
  std::cout << store.access<2>() << std::endl; // "Hello World"
  for (const auto &v : store.access<3>()) { // vector returned
    std::cout << v << ", ";
  }
  std::cout << std::endl;

  for (const auto &v : store.access<16>()) { // fixed size array returned
    std::cout << v << ", ";
  }
  std::cout << std::endl;

  return 0;
}
