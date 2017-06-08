namespace A::B::C {
void doMagic() { /* Magic happens here */
}
}

namespace A::B {
void callMagician() { C::doMagic(); }
}

int main(int argc, char **argv) {
  A::B::C::doMagic();

  A::B::callMagician();

  return 0;
}
