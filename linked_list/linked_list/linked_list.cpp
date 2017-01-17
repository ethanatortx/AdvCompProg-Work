
#include "..\linked_list.h"

template <class T>
T linked_list<T>::at(int pos) const {
	linked_list<T>::const_iterator p = this->begin();

	while(pos) {
		pos--;
		p++;
	}

	return *p;
}

template <class T>
T linked_list<T>::operator[](int pos) const {
	linked_list<T>::const_iterator p = this->begin();
	int count(pos);

	while(count) {
		count--;
		p++;
	}

	return *p;
}

template <class T>
typename linked_list<T>::iterator linked_list<T>::end() {
	linked_list<T>::iterator i = this->begin();
	for (; i->next != NULL; i++) {}
	return i;
}

template <class T>
typename linked_list<T>::const_iterator linked_list<T>::end() const {
	linked_list<T>::const_iterator i = this->begin();
	for (; i->next != NULL; i++) {}
	return i;
}

template <class T>
typename linked_list<T>::const_iterator linked_list<T>::cend() const {
	linked_list<T>::const_iterator i = this->cbegin();
	for (; i->next != NULL; i++) {}
	return i;
}

template <class T>
void linked_list<T>::push_back(const T& data) {
	linked_list<T>::Node* n = new linked_list<T>::Node(data, this->head);
	head = n;
}

template <class T>
void linked_list<T>::push_back(T&& data) {
	linked_list<T>::Node* n = new linked_list<T>::Node(data, this->head);
	head = n;
}

template <class T>
void linked_list<T>::pop() {
	linked_list<T>::Node* old = this->head;
	this->head = this->head->next;
	delete old;
}

template <class T>
void linked_list<T>::clear() {
	while (!this->empty()) {
		this->pop();
	}
}

template <class T>
void linked_list<T>::insert(const T& data, int pos) {
	
	linked_list<T>::iterator p = this->begin();
	linked_list<T>::Node* n = new linked_list<T>::Node(data);

	while(pos-1) {
		pos--;
		p++;
	}
	
	n->next = p->next;
	p->next = n;
}

template <class T>
void linked_list<T>::insert(const T& data, const linked_list<T>::iterator& pos) {
	
	linked_list<T>::iterator p = this->begin();
	linked_list<T>::Node* n = new linked_list<T>::Node(data);

	while(pos-1) {
		pos--;
		p++;
	}
	
	n->next = p->next;
	p->next = n;
}

template <class T>
void linked_list<T>::erase(int pos) {

	linked_list<T>::iterator p = this->begin();
	linked_list<T>::Node* n;

	while(pos-1) {
		pos--;
		p++;
	}
	
	n->next = p->next;
	p->next = n;
}

template <class T>
void linked_list<T>::erase(const typename linked_list<T>::iterator& pos) {

	linked_list<T>::iterator p = this->begin();
	linked_list<T>::Node* n;

	while (p->next != pos) {
		p++;
	}

	n = p->next;
	p->next = p->next->next;
	delete n;
}

// erase from [lhs, rhs)
template <class T>
void linked_list<T>::erase_range(linked_list<T>::iterator lhs, const linked_list<T>::iterator rhs) {

	while(lhs->next != rhs) {
		linked_list<T>::Node* n = lhs->next;
		lhs = lhs->next;
		delete n;
	}
}

template <class T>
void linked_list<T>::erase_range(linked_list<T>::iterator lhs, linked_list<T>::const_iterator rhs) {

	while(lhs->next != rhs.n_ref) {

		linked_list<T>::Node* n = lhs;
		lhs = lhs->next;
		delete n;
	}

	delete lhs;
}

// assign from already initialized CONST list (this is really slow btw; O(n)^2)
template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& rhs) const {
	
	linked_list<T>::iterator it = rhs.begin();

	while(it != 0) {
		this->insert(*it, this->cend());
	}

	return *this;
}

// same as above but uses Rvalue (also really slow)
template <class T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& rhs) const {

	linked_list<T>::iterator it = rhs.begin();

	while(it != 0) {
		this->insert(*it, this->cend());
	}

	return *this;
}

// swap contents with another list
template <class T>
linked_list<T>& linked_list<T>::swap(linked_list<T>& other) {
	
	linked_list<T>::Node* n = this->head;
	
	this->head = other.head;
	other.head = n;
}

// print the list to console
template <class T>
void linked_list<T>::print() {
	linked_list<T>::iterator it = this->begin();

	while(it != 0) {
		std::cout << *it << std::endl;
		it++;
	}
}

template <class T>
linked_list<T>::~linked_list() {

	this->clear();
}