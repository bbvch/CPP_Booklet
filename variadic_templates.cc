
#include <iostream>


struct Dummy
{
    int x;
    char c;
};

template<typename ...Args>
void aFunction(Args...args)
{
//f(args...);
}

template<typename ...Args>
class aClass
{
// Klasseninhalt
};


int sum() { return 0; } // Rekursionsende
template<typename T, typename ...US>
int sum(T t, US...us)
{
return t + sum(us...); // Rekursion
}
template<typename ...US>
int sumSquares(US...us)
{
return sum(us*us...); // ein komplexer Ausdruck
// von Unpack "..."
}

int main(int, char**)
{
    aFunction(42, 1.14159, "Hello", Dummy());
    aFunction(1, 2, 3, 4, 5);

    aClass<std::string, int> ac1;
    aClass<char, char, double, std::string> ac2;
    aClass<> ac3;

    std::cout << sumSquares(1) << std::endl;
    std::cout << sumSquares(1, 2) << std::endl;
    std::cout << sumSquares(1, 2, 3) << std::endl;


}
