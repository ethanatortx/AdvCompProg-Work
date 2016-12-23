#ifndef __ADJACENCY_MATRIX_H_INCLUDED__
#define __ADJACENCY_MATRIX_H_INCLUDED__

#include <vector>

class adjacency_matrix {

	std::vector<std::vector<bool>> matrix;
	int size;

public:
	adjacency_matrix();

	~adjacency_matrix();
};

#endif