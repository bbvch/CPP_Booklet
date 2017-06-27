
static_assert((sizeof(long) == 8), "64 bit code not supported!");

template <typename T> struct Dummy {
  static_assert(sizeof(int) >= sizeof(T), "Dummy<T>: T is too small!");
};

int main(int, char **) {

  Dummy<int> di; // OK

  // Dummy<short> ds; // Error zur Übersetzungszeit!
}
