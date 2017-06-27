#include <algorithm>
#include <vector>

int main(int, char **) {
  const auto square = [](int x) { return x * x; };
  const auto r = square(4);

  int x, y, z;

  const auto no_capture = []() {};             // keine Zugriffsdeklaration
  const auto capture_by_value = [x, y]() {};   // Variablen by value
  const auto capture_by_ref = [&x, &y]() {};   // Variablen by reference
  const auto mixed_capture = [x, &y, &z]() {}; // gemischter Zugriff
  const auto capture_all_by_value = [=]() {
  }; // captures all variables in scope by value (square, r, x,y,z)
  const auto capture_all_by_ref = [&]() {}; // alle Variablen by reference
  const auto capture_all_by_value_except = [=, &x]() {
  }; // alle by value ausser x by ref
  const auto captire_all_by_ref_except = [&, x]() {
  }; // Capture all by reference except x

  // using lambda with stransform
  std::vector<int> a1{1, 2, 3, 4, 5};
  std::vector<int> a2(a1.size());
  // Fülle einen Vektor mit den Quadraten eines anderen
  // Vektors
  std::transform(a1.begin(), a1.end(), a2.begin(), square);

  std::vector<int> v{1, 2, 3, 4, 5};
  int sum{0};
  // Summe der Elemente von v
  std::for_each(v.begin(), v.end(), [&sum](int i) { sum += i; });

  std::transform(a1.begin(), a1.end(), a2.begin(), [](int x) -> int {
    int y = x % 5;
    return x * y;
  });

  // initialized lambda captures
  auto init_function = [&r = x, x = x + 1 ]()->int {
    r += 2;
    return x + 2;
  };

  const auto auto_param_function = [](const auto &a, const auto &b) {
    return a * b;
  };
}
