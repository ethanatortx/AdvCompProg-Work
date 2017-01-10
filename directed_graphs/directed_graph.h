#ifndef __DIRECTED_GRAPH_H_INCLUDED__
#define __DIRECTED_GRAPH_H_INCLUDED__

#include "circular_list.h"
#include <functional>
#include <utility>

template <class T>
class digraph_list {

	struct Vertex {
		// pair of one vertex to another
		typedef std::pair<Vertex*, Vertex*> edge;

		// constructor for Vertex
		Vertex(T&& x, const List<edge> y): data(x), adj(y) {}

		T data; // data of this vertex
		List<edge> adj; // nodes adjacent to this node
	}

	typedef std::pair<std::string, Vertex*> hash;
	typedef std::set<hash> graph;
};

template <class T>
class dirgraph_matrix {



public:


};

#endif