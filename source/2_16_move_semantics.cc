/**
* Example for section 2.16
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the use of the move semantics introduced in C++11
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>

//@33
// swaps two variables using move semantics
template <typename T> void swap(T &a, T &b) {
  T tmp(std::move(a));
  a = std::move(b);
  b = std::move(tmp);
}
//@33

//@32
struct Dummy {

  Dummy() : data(nullptr) {}
  Dummy(int myInt) : data(new int) { *data = myInt; };

  ~Dummy() { delete data; }

  // Move constructor, Object can be moved without new allocation of data
  Dummy(Dummy &&other) : data(other.data) { other.data = nullptr; }
  // move-assignement. Note that internal deletion of data first
  Dummy &operator=(Dummy &&other) {
    if (data)
      delete data;
    data = other.data;
    other.data = nullptr;
    return *this;
  }

  // prevent copying, because of the internal allocation of 'data'
  Dummy(const Dummy &) = delete;
  Dummy &operator=(const Dummy &) = delete;

  int *data;
};

int main(int, char **) {

  // Examples of moveable objects used in standard containers

  std::vector<Dummy> vd1;

  // move a temporary object into the vector
  // Since C++17 this guaranteed to be a move, see 'guaranteed copy elision'
  vd1.push_back(Dummy(100));

  vd1.emplace_back(200); // emplace without the temporary object

  Dummy di1(300);
  // Move di1 into the vector. that 'di1' is no longer accessible after the call
  vd1.push_back(std::move(di1));

  std::vector<Dummy> vd2[3]; // three empty vectors in an array
  vd2[0].push_back(Dummy(500));
  vd2[1] = std::move(vd2[0]); // move the whole vector
  std::swap(vd2[1], vd2[2]);  // swap two vectors

  // retrieve an element. the vector does not change its size
  std::vector<Dummy> result = std::move(vd2[2]);
}
//@32
