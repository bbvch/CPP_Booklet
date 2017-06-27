constexpr double pi{3.1416}; // für floating-point-Typen
constexpr int square(int x) { return x * x; }
float fArray[square(5)]; // für Arraygrössen
struct Dummy {
  constexpr Dummy(int a, int b) : m_a(a), m_b(b) {}
  int m_a, m_b;
};
constexpr Dummy d{3, 4};
int iArray[d.m_a]; // d.m_a wird zu einem konstanten
// Ausdruck 3!

int main(int, char **) {}
