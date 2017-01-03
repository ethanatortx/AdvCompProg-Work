#ifndef __LINKEDLIST_H_INCLUDED__
#define __LINKEDLIST_H_INCLUDED__

#include <cstdlib>
#include <iterator>
#include <utility>

// node struct for use in linked list
template <class T>
struct Node {
	Node(const T& d, Node* n):data(d),next(n) {} // constructor with both data and next node ptr
	// data of this node
	T data;
	// pointer to next node in linked list
	Node* next;
};

// forward-declare linkedlist class for use in iterator class definition
template <class T>
class LinkedList;

// forward access iterator for linked list
template <class T>
class LinkedListIterator: public std::iterator<std::forward_iterator_tag,T> {
	friend class LinkedList<T>; // friends with linked list class
	Node<T>* n; // node iterator is pointing to
public:

	//STL compatibility
	typedef t& reference;
	

	// constructor of iterator from node entry
	LinkedListIterator(Node<T>* n): n(n) {} // iter( node ref )

	LinkedListIterator(const LinkedListIterator<T>& it): n(it.n) {}
	
	// assignment
	LinkedListIterator& operator=(LinkedListIterator list) { std::swap(n, list.n); return *this; } // iter = new iter
	
	// incrementers
	LinkedListIterator& operator++() { n = n->next; return *this; } // ++iter
	LinkedListIterator operator++(int) { LinkedListIterator it(*this); n = n->next; return it; } // iter++
	
	// comparators
	bool operator==(const LinkedListIterator& it) { return n == it.n; } // iter == new iter
	bool operator!=(const LinkedListIterator& it) { return n != it.n; } // iter != new iter
	
	// dereference iterator to return node by value
	Node<T> operator*() const { return *n; }
	
	// get pointer to node
	Node<T>* operator->() const { return n; }
};

// main class definition for linked list
template <class T>
class LinkedList {
	// define pointer to a node as new node type
	typedef Node<T>* node;
	// count of nodes in list
	std::size_t size;
	// head node of list
	typename LinkedList<T>::node head;

public:

	typedef LinkedListIterator<typename LinkedList<T>::node> iterator; // dynamic iterator
	typedef LinkedListIterator<typename LinkedList<T>::node> const_iterator; // constant iterator

	// default, empty, constructor
	LinkedList() {
		this->size = 0;
		this->head(new Node<T>);
	}

	// construct from constant list
	LinkedList(const LinkedList<T>& other) {
		this->size = other->size;
		this->head(other.head->data, other.head->next);
	}

	// construct from rvalue list
	LinkedList(LinkedList<T>&& other) {
		this->size(other.size);
		this->head(other.head->data, other.head->next);
	}

	LinkedList<T>& operator=(LinkedList<T>&& other) {
		assert(this != &other);
		while (head->next) {
			this->remove(this->begin());
		}
		this->size(other.size);
		this->head(other.head->data, other.head->next);
		return *this;
	}

	virtual ~LinkedList() {
		while (head->next) {
			this->remove(this->begin());
		}
	}

	friend void swap(LinkedList<T>& first, LinkedList<T>& second) {
		std::swap(first.size, second.size);
		std::swap(first.head, second.head);
	}

	void push_front(const T& value) {
		typename LinkedList<T>::node n(value, head);
		this->head = n;
	}

	void pop_front() {
		typename LinkedList<T>::node temp = this->head;
		this->head = this->head->next;
		delete temp;
	}

	void insert_after(T&& value, typename LinkedList<T>::iterator it) {
		typename LinkedList<T>::node n(value, it->next);
		it->next = n;
	}

	void erase_after(typename LinkedList<T>::iterator it) {
		typename LinkedList<T>::node temp = it->next;
		it->next = temp->next;
		delete temp;
	}

	// return iterator at beginning of list
	typename LinkedList<T>::iterator begin() {
		return LinkedList<T>::iterator(this->head);
	}

	// return const iterator at beginning of list
	typename LinkedList<T>::const_iterator cbegin() const {
		return LinkedList<T>::const_iterator(this->head);
	}

	// return iterator at end of list
	typename LinkedList<T>::iterator end() {
		typename LinkedList<T>::iterator n(this->head);
		while (n->next) {
			n++;
		}
		return n;
	}

	// return const iterator at end of list
	typename LinkedList<T>::const_iterator cend() const {
		typename LinkedList<T>::const_iterator n(this->head);
		while (n->next) {
			n++;
		}
		return n;
	}
};

#endif