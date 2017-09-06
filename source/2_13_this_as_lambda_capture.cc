/**
* Example for section 2.13
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates how 'this' can be passed to a lambda function. 
* This example is no longer available in the print version of the booklet 
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <iostream>

class LambdaContainer {

public:
  void doMagic() { _magic += 1000; }
  int magic() const { return _magic; }

  void pass_this_by_reference() {
    // possible since C++14
    const auto func = [this]() { this->doMagic(); };
    func();
    // this->_magic is now 2000
  }

  void pass_this_by_value() {
    // possible since C++17
    auto func = [*this]() mutable {
      this->doMagic();
    }; // needs mutable to acces non-const functions, also 'func' cannot be
       // const in this case
    func();

    const auto const_func = [*this] {
      return this->magic();
    }; // OK, creates a copy of 'this'
    const_func();

    // this->_a is still the same values as before the call, as the lamdda
    // creates a copy in the caputure
    // deleting the copy ctor will break compilation
  }

  // before C++17 the following workaround was used to pass 'this'
  void pre14_workararound_for_passing_this() {
    const auto &tmp = *this; // creating a reference to this
    const auto func = [tmp]() {
      return tmp.magic();
    }; // capturing the reference by value in the lamda
  }

private:
  int _magic{1000};
};

int main(int argc, char **argv) {
  LambdaContainer c;
  c.pass_this_by_value();
  c.pass_this_by_reference();
  c.pre14_workararound_for_passing_this();
  return 0;
}
