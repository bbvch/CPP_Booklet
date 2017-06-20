class MutableClass {
public:
  int &non_const_a() { return _a; }
  const int &const_a() const { return _a; }

private:
  int _a{1000};
};

int main(int argc, char **argv) {
  MutableClass obj;
  auto non_const_func = [obj](int v) mutable {
    obj.non_const_a() += v;
  }; // Needs mutable keyword to access non_const_a()
  auto non_const_func_with_ref = [&obj](int v) {
    obj.non_const_a() += v;
  }; // OK, passing by ref

  constexpr int c{1000};

  // explicitely constexpr lambda
  const auto constexpr_func = [&c](int v) constexpr { return c + v; };

  // implicitely constexpr, no warning if no longer constexpr
  const auto const_func = [&c](int v) { return c + v; };

  return 0;
}
