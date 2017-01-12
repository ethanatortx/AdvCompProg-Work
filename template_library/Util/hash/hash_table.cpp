#include "..\hash_table.h"

template <class T>
bool hash_table<T>::empty() const {

}

template <class T>
std::size_t hash_table<T>::size() const {

}

template <class T>
std::size_t hash_table<T>::max_size() const {

}

template <class T>
void hash_table<T>::resize(const std::size_t& new_size) {

}

template <class T>
void hash_table<T>::resize(std::size_t&& new_size) {

}

template <class T>
void hash_table<T>::add(const T& node) {

}

template <class T>
void hash_table<T>::add(T&& node) {

}

template <class T>
void hash_table<T>::clear() {
	resize(0);
}