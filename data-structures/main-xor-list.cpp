#include <iostream>
#include "xor-list.cpp"

using namespace std;

int main()
{
  XorList<int> list;

  list.add(42);
  list.add(1);
  list.add(4);
  list.add(5);

  for (int i = 0; i < 4; i++) {
    cout << list[i]->value << ", ";
  }

  cout << endl;
}
