#include <string>

int main(int, char **) {
  const std::string &other{"Abracadabra"};
  const std::string &name();
  {}
  decltype(name()) n1(other); // n1 erhält den Typ
  // const std::string& (initialisierung mit referenz)
  std::string s1;
  decltype(s1) s2; // s2 erhält den Typ std::string
  struct Foo {
    int i;
  };
  Foo foo;
  decltype(foo.i) j;      // j erhält den Typ int
  decltype((foo.i)) k(j); // k erhält den Typ int&, weil
                          // (foo.i) ein Ausdruck ist und  eine Adresse hat
}
