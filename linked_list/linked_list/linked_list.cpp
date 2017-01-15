
#include "..\linked_list.h"

template <class T>
typename linked_list<T>::iterator linked_list<T>::begin() {

}

template <class T>
const typename linked_list<T>::const_iterator linked_list<T>::begin() const{

}

template <class T>
typename linked_list<T>::const_iterator linked_list<T>::cbegin() {

}

template <class T>
typename linked_list<T>::iterator linked_list<T>::end() {

}

template <class T>
const typename linked_list<T>::const_iterator linked_list<T>::end() const {

}

template <class T>
typename linked_list<T>::const_iterator linked_list<T>::cend() {

}

template <class T>
bool linked_list<T>::empty() const {

}

template <class T>
void linked_list<T>::clear() {

}

template <class T>
void linked_list<T>::push_back(const T&) {

}

template <class T>
void linked_list<T>::push_back(T&&) {

}

template <class T>
void linked_list<T>::insert(const T&, const int) {

}

template <class T>
void linked_list<T>::insert(const T& data, const linked_list<T>::iterator& pos) {

}

template <class T>
void linked_list<T>::insert(const T& data, const linked_list<T>::const_iterator& pos) {

}

template <class T>
void linked_list<T>::pop() {

}

template <class T>
void linked_list<T>::erase(const iterator& pos) {

}

template <class T>
void linked_list<T>::erase(const const_iterator& pos) {

}

template <class T>
void linked_list<T>::erase_range(const iterator& lhs, const iterator& rhs) {

}

template <class T>
void linked_list<T>::erase_range(const const_iterator& lhs, const const_iterator& rhs) {

}

template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& rhs) const {

}

template <class T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& rhs) const {

}

template <class T>
linked_list<T>& linked_list<T>::swap(linked_list<T>&) {

}