#ifndef __LINKEDLIST_MK4_H_INCLUDED__
#define __LINKEDLIST_MK4_H_INCLUDED__

#include <iterator>

template <class T>
class LinkedList {
	struct Node {
		Node(T&& val, Node* n = 0): data(val), next(n) {}
		T data;
		Node* next;
	};

	Node* l_node;

public:

	class iterator: public std::iterator<std::forward_iterator_tag, T> {
		Node* ref;
	public:
		friend class LinkedList;
		friend class const_iterator;

		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;

		inline iterator(Node* n = 0): ref(n) {}
		inline iterator(const iterator& iter): ref(iter.ref) {}
		inline iterator& operator=(const iterator& iter) { return this->ref == iter.ref; }
		inline iterator& operator++() { this->ref = this->ref->next; return *this; }
		inline iterator operator++(int) { iterator temp(*this); this->ref = this->ref->next; return *this; }
		inline reference operator*() const { return this->next->data; }
		inline pointer operator->() const { return this->next; }
		inline bool operator==(const iterator& iter) const { return this->ref == iter.ref; }
		inline bool operator!=(const iterator& iter) const { return this->ref != iter.ref; }
	};

	class const_iterator: public std::iterator<std::forward_iterator_tag, const T> {
		const Node* ref;
	public:
		friend class LinkedList;
		friend class iterator;

		inline const_iterator(const Node* n = 0): ref(n) {}
		inline const_iterator(const iterator& iter): ref(iter.ref) {}
		inline const_iterator(const const_iterator& iter): ref(iter.ref) {}
		inline const_iterator& operator=(const iterator& iter) { this->ref = iter.ref; return *this; }
		inline const_iterator& operator=(const const_iterator& iter) { this->ref = iter.ref; return *this; }
		inline const_iterator& operator++() { this->ref = this->ref->next; return *this; }
		inline const_iterator operator++(int) { iterator temp(*this); this->ref = this->ref->next; return *this; }
		inline typename iterator::reference operator*() const { return this->ref->next->data; }
		inline typename iterator::pointer operator->() const { return this->ref->next; }
		inline bool operator==(const const_iterator& iter) const { return this->ref == iter.ref; }
		inline bool operator!=(const const_iterator& iter) const { return this->ref != iter.ref; }
	};


	LinkedList(): l_node(new Node(T())) { l_node->next = l_node; }
	LinkedList(const LinkedList& list): l_node(new Node(T())) {
		l_node->next = l_node;
		for (const_iterator it = list.begin(); it != list.end(); ++it) {
			push_front(*it);
		}
		reverse();
	}

	void reverse() {
		if (empty()) { return; }
		Node* new_l_node = l_node->next->next; // ref at first position
		Node* n; // blank node
		Node* p = l_node; // ref at last position
		Node* i = l_node->next; // sentinel node

		do {
			n = i->next;
			i->next = p;
			p = i;
			i = n;
		} while (p != l_node)

		l_node = new_l_node;
	}
};

#endif