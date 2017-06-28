/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

struct A {
  struct B {
    struct C {
      struct D {};
      // gibt eine Instanz von A::B::C::D zurück
      D foo(const C &);
      D bar(const C &);
    };
  };
};
// Standard, der Scope von D muss spezifiziert werden
A::B::C::D A::B::C::foo(const C &){};

// Trailing return type, D ist im Scope
auto A::B::C::bar(const C &) -> D{};

template <typename A, typename B>
auto add(A a, B b) -> decltype(a + b) // der Rückgabetyp des
// Ausdrucks wird
// berechnet
{
  return a + b;
}

int main(int, char **) {}
