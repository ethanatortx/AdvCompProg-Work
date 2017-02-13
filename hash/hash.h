#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iterator>
#include <functional>
#include "..\linked_list\linked_list.h"



template <class T,
		  class Hash = std::hash<T>>
class hash_table {
protected:
	class hash_node;

	typedef std::size_t bucket_constant;
	typedef typename std::vector<typename hash_table<T, Hash>::bucket> h_tbl;
	typedef linked_list<hash_node*>::circular_list<hash_node*> bucket;

	typedef T value_type;
	typedef T& reference;

private:

	
	hash_table<T, Hash>::bucket_constant b_const; // limit on bucket size
	hash_table<T, Hash>::h_tbl array; // vector containing hash table elements

public:

	explicit hash_table(): array(new hash_table<T, Hash>::h_tbl()) {}
	hash_table(const hash_table<T, Hash>& H): array(H.array) {}

	virtual hash_table& operator=(const hash_table&);
	virtual hash_table& operator=(hash_table&&);

	class iterator;
	class const_iterator;

	virtual inline typename hash_table<T, Hash>::h_tbl operator*() { return array; }
	virtual inline typename hash_table<T, Hash>::h_tbl operator->() { return &array; }

	std::size_t size() const;
	std::size_t max_size() const;

	void resize(const std::size_t&);
	void resize(std::size_t&&);

	bool empty() const;
	void clear();

	virtual ~hash_table();
};

template <class T,
		  class Hash>
class hash_table<T, Hash>::hash_node {

	const T data;
	const std::string hash;

public:

	T get_data() const;
	std::string get_hash() const;
};

template <class T,
		  class Hash>
class hash_table<T, Hash>::iterator: 
	virtual public std::iterator
	<	std::random_access_iterator_tag,
		typename hash_table<T, Hash>::bucket	>
{

	friend class hash_table;
	friend class const_iterator;

	typename hash_table<T, Hash>::bucket b_ref;

public:
	typedef typename hash_table<T, Hash>::bucket value_type;
	typedef typename hash_table<T, Hash>::iterator::value_type& reference;
	typedef typename hash_table<T, Hash>::iterator::value_type* pointer;
	typedef std::ptrdiff_t difference_type;
	typedef std::random_access_iterator_tag iterator_category;

	iterator(typename hash_table<T, Hash>::iterator::reference B): b_ref(B) {}
	iterator(const iterator& I): b_ref(I.b_ref) {}

	inline iterator& operator=(const iterator& it) { this->b_ref = it->b_ref; return *this; }

	virtual ~iterator();
};

template <class T,
		  class Hash>
class hash_table<T, Hash>::const_iterator: 
	virtual public std::iterator
	<	std::random_access_iterator_tag,				// iterator_category
		const typename hash_table<T, Hash>::bucket 	>	// value_type
{

public:

};

#endif