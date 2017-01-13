#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iterator>
#include <functional>
#include "..\circular_list\circular_list.h"



template <class T,
		  class Hash = std::hash<T>>
class hash_table {
protected:
	class hash_node;

	typedef std::size_t bucket_constant;
	typedef typename std::vector<typename hash_table<T, Hash>::bucket> h_tbl;
	typedef List<hash_node*> bucket;

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

public:

};

#endif