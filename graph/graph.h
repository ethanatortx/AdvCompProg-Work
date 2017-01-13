#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <exception>
#include <functional>
#include "..\hash\hash.h"

template <class T,
		  class Hash = std::hash<T>>
class graph {

	class Node;

public:

	class iterator;
	class const_iterator;

};

template <class T,
		  class Hash = std::hash<T>>
class graph<T, Hash>::Node {

public:

	Node(const T& D): data(D) {}
	Node(const graph<T, Hash>::Node& N): data(N.data) {}

	void setData(const T&);
	void setData(T&&);

	T getData() const;
	std::vector<Node*> getAdj() const;

	~Node();

};

// fix iterator inheritance later
template <class T,
		  class Hash = std::hash<T>>
class graph<T, Hash>::iterator: 
	virtual public std::iterator
		<	std::random_access_iterator_tag, // this iterator is random access (it's accessing a hash table) 
			typename hash_table<T>::bucket	> // iterator points to a bucket in the hash table
{


};

#endif