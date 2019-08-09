#include <vector>
#include <span>
#include <iostream>

int main() {
    std::vector<std::string> greeting = {"hello", "world"};
    std::span<std::string> span (greeting);
    for(auto && s : span) {
        s[0] = std::toupper(s[0]);
    }
    // another name for span could be array_view
    for (const auto& word: greeting) {
        std::cout << word << ' ';
    }
}
