/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

struct NonDeriveable final {};

// Error cannot derive from Base because of final
// struct Derived : NonDeriveable {};

struct BaseWithFinalMembers {
  virtual void foo(int) final;
  virtual void bar();
};
struct Derived2 : public BaseWithFinalMembers {

  // Error
  // void foo(int);
  void bar() override; // OK
};

class DelegatingCtor {
  int m_number;

public:
  DelegatingCtor(int new_number) : m_number(new_number) {}
  DelegatingCtor() : DelegatingCtor(42) {} // delegated
};

struct Base {
  explicit Base(int z){};
  Base() = default;
};
struct InheritingCtor : public Base {
  using Base::Base; // alle vererbten Konstruktoren
  // aufnehmen
  InheritingCtor(int x, int y){}; // neue Überladung
};

int main(int, char **) {
  InheritingCtor d1(5, 10); // neuen Konstruktor verwenden
  InheritingCtor d2(42);    // mit using eingeführten Konstruktor
}
