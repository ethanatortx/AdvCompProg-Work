#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <iterator>
#include <utility>

template <class T>
class linked_list {

	struct Node {

		Node(const T& x, const Node* y): data(x), next(y) {}

		T data;
		Node* next;
	};

	Node* head;

public:

	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::ptrdiff_t difference_type;
	typedef std::forward_iterator_tag, iterator_category;

	linked_list();
	linked_list(const linked_list<T>&);

	class iterator:
		virtual public std::iterator<std::forward_iterator_tag, T> {

		Node* n_ref;

	public:


	};
	
	class const_iterator:
		virtual public std::iterator<std::forward_iterator_tag, T> {


	public:


	};

	std::size_t size();

	linked_list<T>& operator=(const linked_list<T>&);

	bool operator==(const linked_list<T>&) const;
	bool operator!=(const linked_list<T>&) const;

	linked_list<T>& swap(linked_list<T>&);

	iterator& find(const T&);
	const const_iterator& find(const T&) const;

	bool empty() const;

	void clear();

	void push_back(const T&);
	void push_back(T&&);

	void pop();

	void insert(const T&, int);
	void insert(const T&, iterator&);

	void erase(int);
	void erase(iterator&);

	void erase_range(int, int);
	void erase_range(iterator&, iterator&);

	void erase_with(const T&);
	void erase_with(T&&);

	iterator& begin();
	const const_iterator& begin() const;
	const const_iterator& cbegin() const;

	iterator& end();
	const const_iterator& end() const;
	const const_iterator& cend() const;
};

#endif