struct Dummy {
  Dummy() = default;

  // Error compiler does not know how to default this
  // Dummy(int x) = default;

  Dummy(const Dummy &) = default;
  Dummy &operator=(const Dummy &rhs) = default;
};

struct DummyNonCopyable {
  DummyNonCopyable() = default;
  // verhindert das Kopieren
  DummyNonCopyable(const Dummy &) = delete;
  // verhindert Zuweisungen
  DummyNonCopyable &operator=(const Dummy &rhs) = delete;
};

struct NonDefaultConstructible {
  NonDefaultConstructible() = delete;
};

struct NonContrstructableByValue {
  void f(int){};
  void f(double) = delete; // verhindert f.foo(3.14)
};

int main(int, char **) {}
