#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include "circular_list.h"
#include "hash_table.h"
#include <functional>
#include <iterator>
#include <utility>

template <class T>
class digraph_list {

	typedef List<T> edges;
	typedef std::string hash;

	hash_table<T> index = new hash_table();

public:

	class iterator: public std::iterator<std::forward_iterator_tag, edges >;
	class const_iterator: public std::iterator<std::forward_iterator_tag, edges >;

	digraph_list();
	digraph_list(const digraph_list&);
	~digraph_list();

	digraph_list<T>& operator=(const digraph_list<T>&);
	digraph_list<T>& operator=(digraph_list<T>&&);

	void emplace(const T&);
	void emplace(T&&);

	iterator emplace(const T&);
	iterator emplace(T&&);

	void erase(const T&);
	void erase(T&&);

	iterator& find(const T&);
	iterator& find(T&&);

	iterator& operator[](const T&);
	iterator& operator[](T&&);
};

template <class T>
class dirgraph_matrix {
public:
};

#endif