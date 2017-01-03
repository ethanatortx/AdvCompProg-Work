#ifndef __LINKEDLIST_MK3_H_INCLUDED__
#define __LINKEDLIST_MK3_H_INCLUDED__


// circular bidirectional linked list
template <class T>
class LinkedList {

	struct Node {
		T data;
		Node<T>* prev;
		Node<T>* next;
	}

	Node* tail;

public:

	// bi directional iterator for doubly linked list
	class iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
		Node* current; // node referenced by the iterator
	public:
		
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;

		friend class const_iterator;
		friend class LinkedList;
		// construct
		inline iterator(Node* n = 0): current(n) {}
		inline iterator(const iterator& it): current(it.head) {}
		// assign
		inline iterator& operator=(const iterator& it) { this->current = it.current; return *this; }
		// increment
		inline iterator& operator++() { this->current = this->current->next; return *this; }
		inline iterator operator++(int) { iterator temp(*this); this->current = this->current->next; return temp; }
		// decrement
		inline iterator& operator--() { this->current = this->current->prev; return *this; }
		inline iterator operator--(int) { iterator temp(*this); this->current = this->current->prev; return temp; }
		// dereference
		inline reference operator*() const {}
		inline pointer operator->() const {}
		// compare
		inline bool operator==(const iterator& it) const {}
		inline bool operator!=(const iterator& it) const {}
	};

	class const_iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
		const Node* current;
	public:
		friend class iterator;
		friend class LinkedList;

		// constructor
		inline const_iterator(const Node* n = 0): current(n) {}
		inline const_iterator(const const_iterator& it): current(it.current) {}
		inline const_iterator(const iterator& it): current(it.current) {}
		// assign
		inline const_iterator& operator=(const const_iterator& it) {}
		inline const_iterator& operator=(const iterator& it) {}
		// increment
		inline const_iterator& operator++() {}
		inline const_iterator operator++(int) {}
		// decrement
		inline const_iterator& operator--() {}
		inline const_iterator operator--(int) {}
		// dereference
		inline reference operator*() const {}
		inline pointer operator->() const {}
		// compare
		inline bool operator==(const const_iterator& it) {}
		inline bool operator!=(const const_iterator& it) {}
	}

public:
};

#endif