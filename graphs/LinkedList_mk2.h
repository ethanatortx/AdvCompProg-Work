#ifndef __LINKEDLIST_MK2_H_INCLUDED__
#define __LINKEDLIST_MK2_H_INCLUDED__

#include <iterator>

template <class T>
class LinkedList {
	struct Node {
		Node(const T& x, Node* y = 0):data(x), next(y) {}
		T data;
		Node* next;
	};

	Node* head;

public:

	class iterator: public std::iterator<std::forward_iterator_tag,T> {

		Node* pos;

	public:
		friend class const_iterator;
		friend class LinkedList;

		inline iterator(Node* n = 0):pos(n) {}
		inline iterator(const iterator& it):pos(it.pos) {}
		inline iterator& operator=(const iterator& it) { pos(it.pos); return *this; }
		inline iterator& operator++() { pos = pos->next; return *this; }
		inline iterator& operator++(int) { iterator temp(*this); pos = pos->next; return temp; }
		inline typename std::iterator<std::forward_iterator_tag, T>::reference operator*() const { return pos->data; }
		inline typename std::iterator<std::forward_iterator_tag, T>::pointer operator->() const { return pos; }
		inline bool operator==(const iterator& it) const { return pos == it.pos; }
		inline bool operator!=(const iterator& it) const { return pos != it.pos; }
	};

	class const_iterator: public std::iterator<std::forward_iterator_tag, const T> {

		const Node* pos;
	public:
		friend class iterator;
		friend class LinkedList;

		inline const_iterator(const Node* n = 0):pos(n) {}
		inline const_iterator(const iterator& it):pos(it.pos) {}
		inline const_iterator& operator=(const iterator& it) { pos(it.pos); return *this; }
		inline const_iterator& operator++() { pos = pos->next; return *this; }
		inline const_iterator& operator++(int) { iterator temp(*this); pos = pos->next; return temp; }
		inline typename std::iterator<std::forward_iterator_tag, T>::reference operator*() const { return pos->data; }
		inline typename std::iterator<std::forward_iterator_tag, T>::pointer operator->() const { return pos; }
		inline bool operator==(const iterator& it) const { return pos == it.pos; }
		inline bool operator!=(const iterator& it) const { return pos != it.pos; }		
	};

public:
	LinkedList():head(0) {}
	LinkedList(const LinkedList& list):head(0) {
		for (const_iterator i = list.begin(); i != list.end(); ++i) {
			this->push_front(*i);
		}
		reverse();
	}
	
	void reverse() {
		Node* p = 0; Node* i = head; Node* n;
		while (i)
		{
			n = i->next;
			i->next = p;
			p = i; i = n;
		}
		head = p;
	}

	void swap(List& x) {
		Node* tmp = head; head = x.head; x.head = tmp;
	}

	List& operator=(const List& x) {
		List tmp(x);
		swap(tmp);
		return *this;
	}

	~List() { clear(); }

	void clear() { while (!empty()) pop_front(); }

	inline void push_front(const T&x) {
		Node* tmp = new Node(x);
		tmp->next = head;
		head = tmp;
	}

	inline void pop_front() {
		if (head)
		{
			Node* newhead = head->next;
			delete head;
			head = newhead;
		}
	}
	inline bool empty() { return head; }

	inline T& front() { return *begin(); }
	inline const T& front() const { return *begin(); }

	inline iterator begin() { return iterator(head); }
	inline iterator end() { return iterator(); }
	inline const_iterator begin() const { return head; }
	inline const_iterator end() const { return const_iterator(); }

	void erase_after (iterator& x)
	{
		Node* tmp = x.pos->next;
		if (x.pos->next) 
			x.pos->next = x.pos->next->next;
		delete tmp;
	}

	void insert_after (iterator& x, const T& y)
	{
		Node* tmp = new Node(y,x.pos->next);
		x.pos->next = tmp;
	}
};

#endif