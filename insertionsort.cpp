#include <iostream>
#include <algorithm>

using namespace std;

void insertionsort(int array[], int N) {
  for (int i = 1; i < N; i++) {
    int current = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > current) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = current;
  }
}

int main() {
  int array[] = {4,3,2,1};
  int N = sizeof(array) / sizeof(*array);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  insertionsort(array, N);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
