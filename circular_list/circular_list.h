#ifndef __CIRCULAR_LIST_H_INCLUDED__
#define __CIRCULAR_LIST_H_INCLUDED__

#include <iterator>

// circular linked list
template <class T>
class List {
	// node structure
	struct Node {
		Node(T x, Node* y = 0): data(x), next(y) {}
		// data of this node
		T data;
		// node in next position
		Node* next;
	};
	// node at tail end of list
	Node* tail;

public:
	// iterator
	class iterator: public std::iterator<std::forward_iterator_tag, T> 
	{
		// node this iterator is referencing
		Node* ref;
	public:
		friend class List;
		friend class const_iterator;

		// type definitions
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
		inline typename List<T>::iterator::reference operator*() const { return this->ref->next->data; }
		inline typename List<T>::iterator::pointer operator->() const { return this->ref->next; }
		inline bool operator==(const iterator& x) const { return this->ref == x.ref; }
		inline bool operator!=(const iterator& x) const { return this->ref != x.ref; }
	};

	// constant iterator
	class const_iterator: public std::iterator<std::forward_iterator_tag, T>
	{
		// node this iterator is referencing
		const Node* ref;
	public:
		friend class List;
		friend class iterator;
		
		// type definitions
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
		inline typename List<T>::const_iterator::reference operator*() const { return this->ref->next->data; }
		inline typename List<T>::const_iterator::pointer operator->() const { return this->ref->next; }
		inline bool operator==(const const_iterator& it) const { return this->ref == it.ref; }
		inline bool operator!=(const const_iterator& it) const { return this->ref != it.ref; }
	};

	// default constructor
	List(): tail(new Node(T())) { tail->next = tail; }

	// construct from linked list
	List(const List& L): tail(new Node(T())) {
		tail->next = tail;
		for(const_iterator it = L.begin(); it != L.end(); ++it) {
			push_front(*it);
		}
		reverse();
	}

	// reverse the linked list (end->beginning; beginning->end)
	void reverse() {
		// if list has no nodes terminate early
		if (empty()) { return; }

		Node* new_tail = tail->next->next; // copy of first node
		Node* i = tail->next; // copy of sentinal node
		Node* p = tail; // copy of last node
		Node* n; // empty node

		// 	avoid out of bounds by doing one cycle before\
			terminal condition check
		do {
			n = i->next;
			i->next = p;
			p = i;
			i = n;
		} while (p != tail);
		tail = new_tail;
	}

	// swap contents with another list (really just exchange tail pointers)
	void swap(List& L) {
		Node* temp = tail;
		this->tail = L.tail;
		L.tail = temp;
	}

	// assign contents
	List& operator=(const List& L) {
		List temp(L);
		swap(temp);
		return *this;
	}

	// deallocate memory
	~List() { clear(); delete tail; }

	// remove all nodes from list
	void clear() { while(!empty()) pop_front(); }

	// insert node at front
	inline void push_front(const T& x) {
		insert(begin(), x);
	}
	// insert node at end
	inline void push_back(const T& x) {
		insert(end(), x);
	}
	// remove the first node
	inline void pop_front() {
		erase(begin());
	}
	// check if list is empty
	inline bool empty() { return tail == tail->next; }

	// get node at front or back
	inline T& front() { return *begin(); }
	inline const T& front() const { return *begin(); }
	inline T& back() { return *end(); }
	inline const T& back() const { return *end(); }

	// move iterator to beginning or end
	inline iterator begin() { return iterator(tail->next); }
	inline iterator end() { return iterator(tail); }
	// move constant iterator to beginning or end
	inline const_iterator begin() const { return const_iterator(tail->next); }
	inline const_iterator end() const { return const_iterator(tail); }

	// erase node at iterator(it)
	void erase(iterator it) {
		if (it==end()) return;
		if (it.ref->next == tail) tail = it.ref;
		Node* temp = it.ref->next;
		it.ref->next = it.ref->next->next;
		delete temp;
	}

	// insert node at iterator(it) with data(d)
	void insert(iterator it, const T& d) {
		Node* temp = new Node(d, it.ref->next);
		if (it.ref == tail) tail = temp;
		it.ref->next = temp;
	}

	// rotate iterator to beginning
	void rotate (iterator it) {
		if (it == end()) return;
		Node* sent = tail->next;
		tail->next = tail->next->next;
		sent->next = it.ref->next;
		it.ref->next = sent;
		tail = it.ref;
	}
};

#endif