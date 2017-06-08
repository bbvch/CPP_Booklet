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

  const MutableClass const_obj;
  const auto const_func = [&const_obj](int v) {
    return const_obj.const_a() + v;
  }; // OK,implicitely constexpr
  // line below not yet supported by clang 3.9 but by nightly build from 8. 6.
  // 2017
  // constexpr const auto constexpr_func = [&const_obj](int v) { return
  // const_obj.const_a() + v; }; // OK, same as above

  return 0;
}
