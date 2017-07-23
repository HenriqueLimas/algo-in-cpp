#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void quicksort(int array[], int start, int end) {
  int length = end - start;
  if (length <= 1) return;

  int pivotIndex = start + rand() % length;
  swap(array[start], array[pivotIndex]);

  int pivot = array[start];
  int pivotPosition = start;

  for (int i = start + 1; i < end; i++) {
    if (array[i] < pivot) {
      pivotPosition++;
      swap(array[i], array[pivotPosition]);
    }
  }

  if (pivotPosition != start) {
    swap(array[start], array[pivotPosition]);
  }

  quicksort(array, start, pivotPosition);
  quicksort(array, pivotPosition + 1, end);
}

int main() {
  int N = 10;
  int array[N];

  int y = 0;
  for (int i = N; i > 0; i--, y++) {
    array[y] = i;
  }

  int length = (sizeof(array)/sizeof(*array));

  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  quicksort(array, 0, length);

  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
