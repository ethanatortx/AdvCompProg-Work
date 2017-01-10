#ifndef __DIRECTED_GRAPH_H_INCLUDED__
#define __DIRECTED_GRAPH_H_INCLUDED__

#include "circular_list.h"
#include <functional>
#include <utility>

template <class T>
class digraph_list {

	struct Vertex;

	// pair of one vertex to another
	typedef std::pair<Vertex*, Vertex*> edge;
	typedef std::string hash;
	typedef List<edge> adjacent;
	typedef std::pair<T, adjacent> vertex;
	typedef std::unordered_map<hash, vertex> vert_umap;

	// unordered map of hashes-corresponding unhashed vertices
	vert_umap digraph;

public:

	digraph_list();
	digraph_list(const digraph_list&);
	digraph_list(digraph_list&&);

	iterator emplace(T data, )
};

template <class T>
class dirgraph_matrix {



public:


};

#endif