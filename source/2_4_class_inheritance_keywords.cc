/**
* Example for section 2.4 
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the use of the keywords final and override
* as well as inheting and delegating constructors
*
* SPDX-License-Identifier: GPL-3.0
*
**/
//@11
struct NonDeriveable final {};

#ifdef EXPECT_FAILED_COMPILATION
// Error cannot derive from Base because of final
struct Derived : NonDeriveable {};
#endif

struct BaseWithFinalMembers {
  virtual void foo(int) final;
  virtual void bar();
  void nonVirtual();
};
struct Derived2 : public BaseWithFinalMembers {

#ifdef EXPECT_FAILED_COMPILATION
  void foo(int) override; // error because of foo() being 'final' in base class
#endif
}

//@11
//@12
struct Derived3 : public BaseWithFinalMembers {}

  // error does not override any function of base class
  void nonexistant() override;

  // error nonVirtual is not marked virtual in the base class
  void nonVirtual() override;
#endif
  void bar() override; // explicitely override bar
  
};
//@12
//@13
class DelegatingCtor {
  int m_number;

public:
  DelegatingCtor(int new_number) : m_number(new_number) {}
  DelegatingCtor()
      : DelegatingCtor(42) {} // constructor delegates to DelegatingCtor(int)
};
//@13

//@14
struct Base {

  Base() = default;
  // explicit to avoid implicit conversion from ptr-types
  explicit Base(int z){};
};
struct InheritingCtor : public Base {
  using Base::Base;               // Inherit all ctors from Base
  InheritingCtor(int x, int y){}; // Additional Ctor
};
//@14

int main(int, char **) {
//@14
  InheritingCtor d1(5, 10); // uses additional ctor
  InheritingCtor d2(42);    // Uses inherited ctor
//@14
}
