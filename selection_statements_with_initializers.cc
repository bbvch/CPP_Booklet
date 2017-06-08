#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char **argv) {
  std::srand(std::time(0));
  if (int i = std::rand(); i % 2 == 0) {
    std::cout << "i is even" << std::endl;
  } else {
    std::cout << "i is odd" << std::endl;
  }

  switch (int i = std::rand(); i % 3) {
  case 0:
    std::cout << "i is a multiple of 3" << std::endl;
    break;
  case 1:
    std::cout << "i is not a multipe of 3" << std::endl;
    break;
  case 2:
    std::cout << "i is almost a multipe of 3" << std::endl;
    break;
  }
  return 0;
}
