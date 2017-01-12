#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <functional>
#include <iterator>
#include <utility>
#include "circular_list.h"
#include "hash_table.h"

template <class T> 
class digraph_list {

	struct Vertex {
		T data;
		List<Vertex> adj;
	};

	hash_table<Vertex> h_table;

public:

	class iterator;
	class const_iterator;

	digraph_list(std::size_t = 0);
	digraph_list(const digraph_list&);
	~digraph_list();

	bool empty() const;

	void clear();

	std::size_t size() const;
	std::size_t max_size() const;

	digraph_list<T>& operator=(const digraph_list<T>&);
	digraph_list<T>& operator=(digraph_list<T>&&);

	std::pair<iterator, bool> emplace(T&&);

	void erase(const T&);
	void erase(T&&);

	iterator& find(const T&);
	iterator& find(T&&);

	std::size_t count(const T&) const;

	// get range of iterators containing all vertices of a give value
	std::pair<iterator, iterator>
		equal_range(const T&);
	std::pair<const_iterator, const_iterator>
		equal_range(const T&) const;

	iterator& operator[](const T&);
	iterator& operator[](T&&);

	iterator& at(const T&);
	const iterator& at(const T&) const;

	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;

	iterator end();
	const_iterator end() const;
	const_iterator cend() const;

	class iterator: 
		public std::iterator<std::forward_iterator_tag, Vertex> 
	{

	};

	class const_iterator: 
		public std::iterator<std::forward_iterator_tag, Vertex> 
	{

	};


};

template <class T>
class dirgraph_matrix {
public:
};

#endif