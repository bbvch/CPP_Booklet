#include <atomic>
#include <iostream>

[[noreturn]] void alwaysThrow() { throw 123; };

void opaque_func(int *p){/* do something with p */};

[[carries_dependency]] void transparend_func(int *p) {
  /* do something with p */
}

[[deprecated("Don't use black_magic; use white_magic instead")]] void black_magic() {}

void white_magic();

void illustrate_carries_dependency() {
  std::atomic<int *> p;
  int *atomic = p.load(std::memory_order_consume);

  if (atomic)
    std::cout << *atomic << std::endl; // transparent for the the compiler

  if (atomic)
    opaque_func(atomic); // if from another compile unit and not inline the
                         // compiler might construct a memory fence here

  if (atomic)
    transparend_func(atomic); // marked as to work in the same memory-dependency
                              // tree, compiler can omit the memory fence
}

int main(int argc, char **argv) {
    black_magic();
}
