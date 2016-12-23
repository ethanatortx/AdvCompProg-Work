#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__

#include "hashtable.h"

template <typename T>
struct vertex {
	T value;
	std::vector<vertex*> edges;
};

template <class T>
class graph {

}

#endif