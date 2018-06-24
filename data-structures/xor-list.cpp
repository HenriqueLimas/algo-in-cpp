#include <inttypes.h>

template <class T>
struct Node {
  T value;
  Node<T> *xnode;
};

template <class T>
class XorList {
  private:
    int size;
    Node<T> *start;
    Node<T> *XOR(Node<T> *a, Node<T> *b);

  public:
    XorList();
    void add(T value);
    Node<T> *get(int index);
    Node<T> *operator [](int index);
};

template <class T>
XorList<T>::XorList() {
  size = 0;
  start = 0;
}

template <class T>
Node<T> *XorList<T>::XOR(Node<T> *a, Node<T> *b) {
  return (Node<T>*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

template <class T>
void XorList<T>::add(T value) {
  Node<T> *prev = 0;
  Node<T> *curr = start;

  Node<T> *newNode = new Node<T>;
  newNode->value = value;
  newNode->xnode = 0;
  size++;

  if (!curr) {
    start = newNode;
    return;
  }

  while (curr->xnode) {
    Node<T> *tmp = prev;
    prev = curr;
    if (curr->xnode) {
      curr = XOR(curr->xnode, tmp);
    }
  }

  curr->xnode = XOR(prev, newNode);
}

template <class T>
Node<T> *XorList<T>::get(int index) {
  int i = 0;
  if (index >= size || index < 0 ) {
    return 0;
  }

  Node<T> *prev = 0;
  Node<T> *curr = start;

  while (i < index) {
    Node<T> *tmp = prev;
    prev = curr;

    curr = XOR(curr->xnode, tmp);

    i++;
  }

  return curr;
}

template <class T>
Node<T> *XorList<T>::operator [](int index) {
  return get(index);
}
