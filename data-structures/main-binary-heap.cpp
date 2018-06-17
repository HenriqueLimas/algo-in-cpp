#include <iostream>
#include "binary_heap.cpp"

int main() {
  binary_heap<int> bh;

  bh.insert(13);
  bh.insert(42);
  bh.insert(29);
  bh.insert(12);
  bh.insert(7);
  bh.insert(18);
  bh.insert(18);
  bh.insert(11);
  bh.insert(14);

  for (int i = 0; i < 9; i++) {
    std::cout << bh.extract_max() << ", ";
  }

  std::cout << std::endl;
}
