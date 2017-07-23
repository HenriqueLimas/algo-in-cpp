#include <iostream>

using namespace std;

void mergesort(int array[], int start, int end);
void merge(int array[], int start, int middle, int end);

void mergesort(int array[], int start, int end) {
  int lenght = end - start;
  if (lenght <= 0) return;

  int middle = start + (lenght) / 2;

  mergesort(array, start, middle);
  mergesort(array, middle + 1, end);

  merge(array, start, middle, end);
}

void merge(int array[], int start, int middle, int end) {
  int left_n = middle - start + 1;
  int right_n = end - middle;

  int left[left_n], right[right_n];

  for (int i = 0; i < left_n; i++) {
    left[i] = array[start + i];
  }

  for (int i = 0; i < right_n; i++) {
    right[i] = array[middle + 1 + i];
  }

  int left_i, right_i, i;

  left_i = right_i = 0;
  i = start;

  while (left_i + right_i < left_n + right_n) {
    if (left_i >= left_n) {
      array[i] = right[right_i];
      right_i++;
    } else if (right_i >= right_n || left[left_i] < right[right_i]) {
      array[i] = left[left_i];
      left_i++;
    } else {
      array[i] = right[right_i];
      right_i++;
    }

    i++;
  }
}

int main() {
  int array[] = {4,3,2,1};
  int N = sizeof(array) / sizeof(*array);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  mergesort(array, 0, N - 1);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
