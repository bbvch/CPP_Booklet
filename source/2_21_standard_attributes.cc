/**
* Example for section 2.21
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the usage of standard-attributes
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <atomic>
#include <cassert>
#include <iostream>
#include <unordered_map>
// emtpy dummy functions for use below
namespace {

void foo() {}
void bar() {}
}

//@42
// indicates that this function never returns
[[noreturn]] void always_throw() { throw 123; };
//@42

//@43
// generates a compiler warning if called
[[deprecated("black magic is no longer used")]] void black_magic(){};

// generates a compiler warning if called
[[deprecated]] void ancient_magic() {}
//@43

//@44
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
//@44

//@45
struct[[nodiscard]] demon{}; // Demons need to be kept and named
struct ghost {};             // Ghosts can be free

demon summon_demon() { return demon(); }

// summoned ghosts need to be kept
[[nodiscard]] ghost summon_ghost() { return ghost(); }

void summon() {
  auto d = summon_demon(); // OK
  auto g = summon_ghost(); // OK

  // Compiler Warning, because returned demon is not kept
  summon_demon();

  // Compiler Warning, because the function of summoning is nodiscard
  summon_ghost();
}
//@45

//@46
// omit compiler warning if thing1 on thing2 is not used
[[maybe_unused]] void f([[maybe_unused]] bool thing1,
                        [[maybe_unused]] bool thing2) {
  [[maybe_unused]] bool b = thing1 && thing2;

  assert(b); // in release mode, assert is compiled out, and b is unused
             // no warning because it is declared [[maybe_unused]]
  assert(thing1 &&
         thing2); // parameters thing1 and thing2 are not used, no warning
}
//@46

//
// Example for carrying memory dependence
//
//@47
void opaque_func(int *p){/* do something with p */};

[[carries_dependency]] void transparent_func(int *p) {
  /* do something with p */
}

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
//@47
int main(int argc, char **argv) {}
