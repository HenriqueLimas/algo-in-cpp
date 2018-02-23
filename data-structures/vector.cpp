#include <iostream>

using namespace std;

template <class T>
class Vector {
  private:
    int _size;
    int _capacity;
    T *_buffer;
    void resize(int new_capacity);
  public:
    Vector();
    int size(); // O(1)
    int capacity(); // O(1)
    bool is_empty(); // O(1)
    T at(int i); // O(1)
    T operator [](int i); // O(1)
    void push(T value); // O(1) or O(n) for more space
    void insert(int i, T value); // O(n)
    void prepend(T value); // O(n)
    T pop(); // O(1)
    void erase(int index); // O(n)
    void remove(T item); // O(n^2)
    int find(T item); // O(n)
};

template <class T>
Vector<T>::Vector()
{
  _size = 0;
  _capacity = 2;
  _buffer = new T[_capacity]();
}

template <class T>
int Vector<T>::size()
{
  return _size;
}

template <class T>
int Vector<T>::capacity()
{
  return _capacity;
}

template <class T>
bool Vector<T>::is_empty()
{
  return size() == 0;
}

template <class T>
void Vector<T>::resize(int new_capacity)
{
  int end_size = _size < new_capacity ? _size : new_capacity;
  T *new_buffer = new T[new_capacity]();

  for (int i = 0; i < end_size; i++)
  {
    new_buffer[i] = _buffer[i];
  }

  _size = end_size;
  _capacity = new_capacity;

  _buffer = new_buffer;
}

template <class T>
void Vector<T>::push(T value)
{
  if (_size >= _capacity)
  {
    resize(_capacity * 2);
  }

  _buffer[_size] = value;
  _size++;
}

template <class T>
T Vector<T>::at(int index)
{
  return _buffer[index];
}

template <class T>
T Vector<T>::operator [](int index)
{
  return this->at(index);
}

template <class T>
int Vector<T>::find(T item)
{
  for (int i = 0; i < _size; i++)
  {
    if (_buffer[i] == item)
    {
      return i;
    }
  }
  return -1;
}

template <class T>
T Vector<T>::pop()
{
  if (_size) {
    return _buffer[--_size];
  }

  return NULL;
}

template <class T>
void Vector<T>::erase(int index)
{
  _size--;

  for (int i = index; i < _size; i++)
  {
    _buffer[index] = _buffer[index + 1];
  }
}

template <class T>
void Vector<T>::remove(T item)
{
  for (int i = _size - 1; i >= 0; i--)
  {
    if (_buffer[i] == item)
    {
      erase(i);
    }
  }
}

template <class T>
void Vector<T>::insert(int index, T item)
{
  if (_size >= _capacity)
  {
    resize(_capacity * 2);
  }

  if (index >= _size)
  {
    _buffer[_size] = item;
    return;
  }


  for (int i = _size; i > index; i--)
  {
    _buffer[i] = _buffer[i - 1];
  }

  _size++;
  _buffer[index] = item;
}

template <class T>
void Vector<T>::prepend(T item)
{
  insert(0, item);
}
