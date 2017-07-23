#include <iostream>
#include <algorithm>

using namespace std;

void bubblesort(int array[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

void bubblesort_improved(int array[], int N) {
  bool swapped = false;
  while(true) {
    swapped = false;
    for (int j = 0; j < N - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) break;
  }
}

int main () {
  int array[] = {4,3,2,1};
  int N = sizeof(array) / sizeof(*array);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  bubblesort_improved(array, N);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
