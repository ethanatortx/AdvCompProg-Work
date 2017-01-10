#ifndef __DIRECTED_GRAPH_H_INCLUDED__
#define __DIRECTED_GRAPH_H_INCLUDED__

#include "circular_list.h"
#include <unordered_map>
#include <functional>
#include <iterator>
#include <utility>

template < class Key,
		   class Hash = std::hash<Key>,
		   class Pred = std::equal_to<Key>,
		   class Alloc = std::allocator< std::pair<const Key, List<Key*>>>
		   >
class digraph_list 
{

	typedef Key* key_type;
	typedef List<Key*> mapped_type;
	typedef std::pair<const key_type, mapped_type> value_type;

	std::unordered_map<key_type, mapped_type, Hash, Pred, Alloc> digraph;

public:

	// pre definition for iterators
	class iterator;
	class const_iterator;

	digraph_list(); // default initialization constructor

	// copy constructor
	digraph_list(const digraph_list&); 

	digraph_list& operator=(const digraph_list&);
	digraph_list& operator=(digraph_list&&);

	List<Key*> operator[](const iterator&) const;
	List<Key*> operator[](iterator&&) const;

	// get iterator to key
	iterator& find(Key*);

	// main iterator declaration
	class iterator {
		
	};

	// main constant iterator declaration
	class const_iterator {};

	~digraph_list();
};

template <class T>
class dirgraph_matrix {



public:


};

#endif