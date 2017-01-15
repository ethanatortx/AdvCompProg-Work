#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <exception>
#include <iterator>

template <class T>
class linked_list {

	struct Node;

	Node *head;

public:
	linked_list(): head(0);
	linked_list(const linked_list<T>&): head(0);

	class iterator;
	class const_iterator;

	iterator begin();
	const_iterator begin();
	const_iterator cbegin();

	iterator end();
	const_iterator end();
	const_iterator cend();

	bool empty() const;

	void clear();

	void push_back(const T&);
	void push_back(T&&);

	void insert(const T&, const int);
	void insert(const T&, const iterator&);
	void insert(const T&, const const_iterator&);

	void pop();

	void erase(const iterator&);
	void erase(const const_iterator&);

	void erase_range(const iterator&, const iterator&);
	void erase_range(const const_iterator&, const const_iterator&);

	linked_list<T>& operator=(const linked_list<T>&) const;
	linked_list<T>& operator=(linked_list<T>&&) const;

	inline bool operator==(const linked_list<T>& List) const { return this->head == List.head; }
	inline bool operator!=(const linked_list<T>& List) const { return this->head != List.head; }

	linked_list<T>& swap(linked_list<T>&);

};

template <class T>
struct linked_list<T>::Node {

	Node(const T& x, const Node* y = 0): data(x), next(y) {}

	T data;
	Node* next;
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

	iterator(const Node* x = 0): n_ref(x.n_ref) {}
	iterator(const iterator& x): n_ref(x.n_ref) {}

	inline iterator& operator=(const iterator& I) { this->n_ref = I.n_ref; return *this; }

	inline iterator& operator++() { this->n_ref = this->n_ref->next; return *this; }
	inline iterator operator++(int) { iterator tmp(*this); this->n_ref = this->n_ref->next; return tmp; }

	inline linked_list<T>::iterator::reference operator*() const { return this->n_ref->data; }
	inline linked_list<T>::iterator::pointer operator->() const { return this->n_ref; }

	inline bool operator==(const iterator& I) const { return this->n_ref == I.n_ref; }
	inline bool operator!=(const iterator& I) const { return this->n_ref != I.n_ref; }

	~iterator();

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

	~const_iterator();
};

#endif