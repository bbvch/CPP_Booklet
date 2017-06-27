// this is how NULL used to be defined, in modern C++ NULL is often defined as
// nullptr
#define NULL 0

void foo(const char *dummy) {

  if (dummy == nullptr) {
    // do something
  }
}
void foo(int i) {}

int main(int, char **) {

  const char *dummy = nullptr; // OK
  // bool valid = nullptr;        // error, except if direct initialisation
  // enabled during compilation
  // int value = nullptr;         // Error!
  int anInt{42};
  int *ptrTo_anInt = &anInt;
  ptrTo_anInt = nullptr; // OK

  foo(NULL);    // ruft foo(int) auf
  foo(nullptr); // ruft die bestmögliche Entsprechung für
                // foo(T*) auf, hier foo(const char*)
}
