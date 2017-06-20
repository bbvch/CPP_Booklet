class A
{
    public:
        A() = default;
        A(const A& rhs) = delete; 
        A(const A&& rhs) = delete;
        ~A() = default;

private:

};

// Without elision this is illegal, as it performs a copy/move of A which has deleted copy/move ctors
A f() { return A{}; } 

int main()
{
    // OK, because of copy elision. Copy/Move constructing an anonymous A is not neccessary
    A a = f();
}
