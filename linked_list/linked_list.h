#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <exception>
#include <iterator>
#include <iostream>

template <class T>
class linked_list {

	struct Node {

		Node(const T& x, const Node *y = NULL): data(x), next(y) {}

		T data;
		Node *next;

	};

	Node *head;

public:
	linked_list(): head(0) {}
	linked_list(const linked_list<T>&): head(0) {}

	class iterator;
	class const_iterator;

	T at(int) const;
	T operator[](int) const;

	inline iterator begin() { linked_list<T>::iterator* I = new linked_list<T>::iterator(head); return *I; }
	inline const_iterator begin() const { linked_list<T>::iterator* I = new linked_list<T>::const_iterator(head); return *I; }
	inline const_iterator cbegin() const { linked_list<T>::const_iterator* I = new linked_list<T>::const_iterator(head); return *I; }

	iterator end();
	const_iterator end() const;
	const_iterator cend() const;

	inline bool empty() const { return (head == NULL); }

	void push_back(const T&);
	void push_back(T&&);

	void pop();

	void clear();

	void insert(const T&, int);
	void insert(const T&, const iterator&);

	void erase(int);
	void erase(const iterator&);

	void erase_range(iterator, const iterator);
	void erase_range(iterator, const_iterator);

	linked_list<T>& operator=(const linked_list<T>&) const;
	linked_list<T>& operator=(linked_list<T>&&) const;

	inline bool operator==(const linked_list<T>& List) const { return this->head == List.head; }
	inline bool operator!=(const linked_list<T>& List) const { return this->head != List.head; }

	linked_list<T>& swap(linked_list<T>&);

	void print();

	~linked_list();

};



template <class T>
class linked_list<T>::iterator:
	public std::iterator<std::forward_iterator_tag, T>
{
	Node* n_ref;

public:

	friend class linked_list;
	friend class const_iterator;

	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef int difference_type;
	typedef std::forward_iterator_tag iterator_category;

	iterator(Node* x = 0): n_ref(x) {}
	iterator(const iterator& x): n_ref(x.n_ref) {}

	inline iterator& operator=(const iterator& I) { this->n_ref = I.n_ref; return *this; }

	inline iterator& operator++() { this->n_ref = this->n_ref->next; return *this; }
	inline iterator operator++(int) { iterator tmp(*this); this->n_ref = this->n_ref->next; return tmp; }

	inline linked_list<T>::iterator::reference operator*() const { return this->n_ref->data; }
	inline linked_list<T>::iterator::pointer operator->() const { return this->n_ref; }

	inline bool operator==(const iterator& I) const { return this->n_ref == I.n_ref; }
	inline bool operator!=(const iterator& I) const { return this->n_ref != I.n_ref; }

	inline iterator& swap(iterator& it) { iterator old(it); it.n_ref = this->n_ref; this->n_ref = old->n_ref; }

	~iterator() { delete n_ref; }

};

template <class T>
class linked_list<T>::const_iterator:
	public std::iterator<std::forward_iterator_tag, T>
{

	const Node* n_ref;

public:

	friend class linked_list;
	friend class iterator;

	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef int difference_type;
	typedef std::forward_iterator_tag iterator_category;

	const_iterator(const Node* x = 0): n_ref(x.n_ref) {}
	const_iterator(const iterator& x): n_ref(x.n_ref) {}
	const_iterator(const const_iterator& x): n_ref(x.n_ref) {}

	inline const_iterator& operator=(const iterator& I) { this->n_ref = I.n_ref; return *this; }
	inline const_iterator& operator=(const const_iterator& I) { this->n_ref = I.n_ref; return *this; }

	inline const_iterator& operator++() { this->n_ref = this->n_ref->next; return *this; }
	inline const_iterator operator++(int) { const_iterator tmp(*this); this->n_ref = this->n_ref->next; return tmp; }

	inline linked_list<T>::const_iterator::reference operator*() const { return this->n_ref->data; }
	inline linked_list<T>::const_iterator::pointer operator->() const { return this->n_ref; }

	inline bool operator==(const const_iterator& I) const { return this->n_ref == I.n_ref; }
	inline bool operator!=(const const_iterator& I) const { return this->n_ref != I.n_ref; }

	inline const_iterator& swap(const_iterator& it) { iterator old(it); it.n_ref = this->n_ref; this->n_ref = old->n_ref; }
};

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
void linked_list<T>::push_back(const T& D) {
	linked_list<T>::Node* n = new linked_list<T>::Node(D);
	n->next = head;
	head = n;
}


template <class T>
void linked_list<T>::push_back(T&& D) {
	linked_list<T>::Node* n = new linked_list<T>::Node(D, head);
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

#endif