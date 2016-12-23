#include "adjacency_matrix.h"

// construct array of arrays of booleans of provided size
adjacency_matrix::adjacency_matrix(int vertexCount) {
	this->size = vertexCount;
	array = new bool*[vertexCount];

	for (int i = 0; i < adjacency_matrix::size; i++) {
		array[i] = new bool[vertexCount];
		for (int k = 0; k < adjacency_matrix::size; k++) {
			array[i][k] = false;
		}
	}
};

// add edge between the two vertices
void adjacency_matrix::addEdge(int p, int q) {
	if (p >= 0 && p < adjacency_matrix::size && q >= 0 && q < adjacency_matrix::size) {
		array[p][q] = true;
		array[q][p] = true;
	}
};

// remove edge between the two vertices
void adjacency_matrix::removeEdge(int p, int q) {
	if (p >= 0 && p < adjacency_matrix::size && q >= 0 && q < adjacency_matrix::size) {
		array[p][q] = false;
		array[q][p] = false;
	}
}

// check if there is an edge between the two vertices
bool adjacency_matrix::isEdge(int p, int q) {
	if (p >= 0 && p < adjacency_matrix::size && q >= 0 && q < adjacency_matrix::size) {
		return (array[p][q] && array[q][p]);
	} else return false;
}

// print matrix to console
void adjacency_matrix::printMatrix() {
	for (int p = 0; p < adjacency_matrix::size; p++) {
		for (int q = 0; q < adjacency_matrix::size; q++) {
			std::cout << array[p][q];
		}
		std::cout << '\n';
	}
};

// free memory
adjacency_matrix::~adjacency_matrix() {
	for (int i = 0; i < adjacency_matrix::size; i++) {
		delete[] array[i];
	}
	delete[] array;
}