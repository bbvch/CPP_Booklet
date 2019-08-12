#ifdef __cpp_lib_format

#include <format>

int main(){
    std::string s0 = std::format("{}", 42);                      // s0 == "42"
    std::string s1 = std::format("{0:b} {0:d} {0:o} {0:x}", 42); // s1 == "101010 42 52 2a"
    std::string s2 = std::format("{0:#x} {0:#X}", 42);           // s2 == "0x2a 0X2A"
    return 0;
}

#endif
