/**
* This example does not have corresponding section in the booklet
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example shows how names declared somehwere else can be used in a declarative region
*
* SPDX-License-Identifier: GPL-3.0
*
**/

void f(){
    // Do something
}

namespace X
{
    void x() {};
    void y() {};
    void z() {};
}

namespace A::B::C
{
    using ::f; // f() is available in A::B::C now
    using X::x; // x() is available in A::B::C (dropped namespace X) 
    using X::y, X::z;
}

int main(int, char**)
{
    A::B::C::f();
    A::B::C::x();
}