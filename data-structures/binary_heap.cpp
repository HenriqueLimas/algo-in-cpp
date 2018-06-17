#include <iostream>

template <class T>
class binary_heap {
  private:
    T *array;
    int size;
    int max_size;

  public:
    binary_heap();
    T get_max();
    T extract_max();
    void insert(T elm);
    void sift_down(int i);
    void sift_up(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    void swap(int a, int b);
};

template <class T>
binary_heap<T>::binary_heap() {
  size = 0;
  max_size = 10;
  array = new T[max_size]();
}

template <class T>
int binary_heap<T>::parent(int i) {
  int p = i / 2;

  if (i % 2 == 0) {
    return p - 1;
  }

  return p;
}

template <class T>
int binary_heap<T>::left(int i) {
  return i * 2 + 1;
}

template <class T>
int binary_heap<T>::right(int i) {
  return i * 2 + 2;
}

template <class T>
void binary_heap<T>::swap(int a, int b) {
  T tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
}

template <class T>
void binary_heap<T>::sift_up(int i) {
  while (i > 0) {
    int p = parent(i);
    if (array[i] > array[p]) {
      swap(i, p);
      i = p;
    } else {
      return;
    }
  }
}

template <class T>
void binary_heap<T>::sift_down(int i) {
  while (i < size) {
    int pos = i;
    int l, r;
    l = left(i);
    if (l < size && array[l] > array[i]) {
      pos = l;
    }

    r = right(i);
    if(r < size && array[r] > array[pos]) {
      pos = r;
    }

    if (pos != i) {
      swap(i, pos);
      i = pos;
    } else {
      return;
    }
  }
}

template <class T>
void binary_heap<T>::insert(T v) {
  if (size == max_size) return;

  array[size++] = v;
  sift_up(size - 1);
}

template <class T>
T binary_heap<T>::extract_max() {
  T m = array[0];

  swap(0, size - 1);
  size--;
  sift_down(0);
  return m;
}

template <class T>
T binary_heap<T>::get_max() {
  return array[0];
}
