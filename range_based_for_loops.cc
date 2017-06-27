#include <vector>

int main(int, char **) {

  int iArray[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  for (int i : iArray) {
    // do something
  };

  std::vector<int> v{1, 2, 3, 4};

  for (const &i : v) {
    // do something
  }
}
