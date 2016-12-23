#ifndef __ADJACENCT_MATRIX_H_INDLUDED__
#define __ADJACENCT_MATRIX_H_INDLUDED__

#include <iostream>

class adjacency_matrix {
	// two dimensional array of boolean values
	bool** array;
	// count of height of array stack
	int size;
public:
	// construct array of arrays of booleans of provided size
	adjacency_matrix(int vertexCount);
	// add edge between the two vertices
	void addEdge(int p, int q);
	// remove edge between the two vertices
	void removeEdge(int p, int q);
	// check if there is an edge between the two vertices
	bool isEdge(int p, int q);
	// print matrix to console
	void printMatrix();
	// free memory
	~adjacency_matrix();
};

#endif