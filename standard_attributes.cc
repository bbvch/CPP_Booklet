#include <atomic>
#include <iostream>
// emtpy dummy functions for use below
namespace {

void foo() {}
void bar() {}
}

[[noreturn]] void always_throw() { throw 123; };

void opaque_func(int *p){/* do something with p */};

[[carries_dependency]] void transparent_func(int *p){
    /* do something with p */
}

    [[deprecated("black magic is no longer used")]] void black_magic(){}[
        [deprecated]] void ancient_magic() {}

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
    transparent_func(atomic); // marked as to work in the same memory-dependency
                              // tree, compiler can omit the memory fence
}

void fall_through(int i) {
  switch (i) {
  case 0:
  case 1:
  case 2: // until here implicit [[fallthrough]]
    foo();
    [[fallthrough]]; // don't forget the semicolon
  case 3:
    bar();
  default: // compiler might issue a warning, depending on the flags set
    break;
  }
}

int main(int argc, char **argv) {}
