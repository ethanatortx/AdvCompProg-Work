#include "LinkedList.h"

// construct from node
template <typename T>
LinkedListIterator<T>::LinkedListIterator(T* p) : p(p) {}
// construct from iterator
template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListIterator&& other) : p(other.p) {}
