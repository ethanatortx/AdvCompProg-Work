#ifndef __LINKEDLIST_H_INCLUDED__
#define __LINKEDLIST_H_INCLUDED__

#include <iterator>

template <class T>
class LinkedList {
	struct Node {
		Node(T x, Node* y): data(d), next(y) {}
		T data;
		Node* next;
	}
	Node* tail;
	int size;

public:
	LinkedList(): tail(0), size(0) {}
	LinkedList(const LinkedList& x): tail(x.tail), size(x.size) {}

	class iterator: public std::iterator<std::forward_iterator_tag, T> 
	{
		friend class LinkedList;
		friend class const_iterator;
		Node* ref;
	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;

		inline iterator(Node* x = 0): ref(x) {}
		inline iterator(const iterator& x): ref(x.ref) {}
		inline iterator& operator=(const iterator& it) { this->ref = it.ref; return *this; }
		inline iterator& operator++() { this->ref = this->ref->next; return *this; }
		inline iterator operator++(int) { iterator it(*this); this->ref = this->ref->next; return it; }
		inline typename reference operator*() const { return this->ref->next->data; }
		inline typename pointer operator->() const { return this->ref->next; }
		inline bool operator==(const LinkedList& x) const { return this->ref == x.ref; }
		inline bool operator!=(const LinkedList& x) const { return this->ref != x.ref; }
	}

	class const_iterator: public std::iterator<std::forward_iterator_tag, T>
	{
		friend class LinkedList;
		friend class iterator;
		const Node* ref;
	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;

		inline const_iterator(Node* x = 0): ref(x) {}
		inline const_iterator(const iterator& x): ref(x.ref) {}
		inline const_iterator(const const_iterator& x): ref(x.ref) {}
		inline const_iterator& operator=(const iterator& it) { this->ref = it.ref; return *this; }
		inline const_iterator& operator=(const const_iterator& it) { this->ref = it.ref; return *this; }
		inline const_iterator& operator++() { this->ref = this->ref->next; return *this; }
		inline const_iterator operator++(int) { const_iterator it(*this); this->ref = this->ref->next; return it; }
		inline typename reference operator*() const { return this->ref->next->data; }
		inline typename pointer operator->() const { return this->ref->next; }
		inline bool operator==(const const_iterator& it) const { return this->ref == it.ref; }
		inline bool operator!=(const const_iterator& it) const { return this->ref != it.ref; }
	}

	LinkedList()
}

#endif