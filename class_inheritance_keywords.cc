/**
* Example for section 2.5 (Tentative)
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
* This example illustrates the use of the keywords final and override
* as well as inheting and delegating constructors
**/

struct NonDeriveable final {};

#ifdef DOES_NOT_COMPILE
// Error cannot derive from Base because of final
struct Derived : NonDeriveable {};
#endif

struct BaseWithFinalMembers {
  virtual void foo(int) final;
  virtual void bar();
};
struct Derived2 : public BaseWithFinalMembers {

#ifdef DOES_NOT_COMPILE
  void foo(int) override; // Error because of foo() being 'final' in base class
#endif
  void bar() override;
};

class DelegatingCtor {
  int m_number;

public:
  DelegatingCtor(int new_number) : m_number(new_number) {}
  DelegatingCtor()
      : DelegatingCtor(42) {} // constructor delegates to DelegatingCtor(int)
};

struct Base {

  Base() = default;
  // explicit to avoid implicit conversion from ptr-types
  // this cannot be marked default, because of the argument
  explicit Base(int z){};

  virtual ~Base() = default; // destructor can be defaulted too

protected:
  Base(Base&& other) = default; // protect move, but use default implementation
  Base(const Base& other) = default; // protect copy, but use default implementation

};
struct InheritingCtor : public Base {
  using Base::Base;               // Inherit all ctors from Base
  InheritingCtor(int x, int y){}; // Additional Ctor
};

int main(int, char **) {
  InheritingCtor d1(5, 10); // uses additional ctor
  InheritingCtor d2(42);    // Uses inherited ctor
}
