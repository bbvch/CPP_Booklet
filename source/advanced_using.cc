

void f(){
    // Do something
}

namespace X
{
    void x() {};
}

namespace A::B::C
{
    using ::f; // f() is available in A::B::C now
    using X::x; // x() is available in A::B::C (dropped namespace X) 
}

int main(int, char**)
{
    A::B::C::f();
    A::B::C::x();
}