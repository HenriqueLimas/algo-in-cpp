#include <iostream>

using namespace std;

int left(int i) {
  return i * 2 + 1;
}

int right(int i) {
  return i * 2 + 2;
}

int parent(int i) {
  int p = i / 2;
  if (i % 2 == 0) {
    return p - 1;
  }

  return p;
}

void swap(int arr[], int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void sift_down(int arr[], int n, int i) {
  while (i < n) {
    int pos = i;
    int l = left(i);
    if (l < n && arr[l] > arr[pos]) {
      pos = l;
    }

    int r = right(i);
    if (r < n && arr[r] > arr[pos]) {
      pos = r;
    }

    if (pos != i) {
      swap(arr, i, pos);
      i = pos;
    } else {
      return;
    }
  }
}

void heapify(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    sift_down(arr, n, i);
  }
}

void heapsort(int arr[], int n) {
  heapify(arr, n);
  for (int i = n - 1; i >= 0; i--) {
    swap(arr, 0, i);
    sift_down(arr, i, 0);
  }
}

int main() {
  int array[] = {42,29,18,14,7,18,12,11,13};
  int N = sizeof(array) / sizeof(*array);


  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  heapsort(array, N);

  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }

  cout << endl;
}
