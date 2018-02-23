#include "vector.cpp"

int main()
{
  Vector<int> v_int;

  v_int.push(42);
  v_int.push(1);
  v_int.push(4);
  v_int.push(42);
  v_int.insert(2, 8);

  cout << v_int[2] << " " << v_int.size() << " " << v_int.capacity() << "\n";

  v_int.prepend(55);
  cout << v_int[0] << " " << v_int.size() << " " << v_int.capacity() << "\n";
}
