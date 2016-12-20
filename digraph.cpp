

#include <utility>
#include <memory>
#include <vector>
#include <map>
#include <iostream>

template <class T>
class digraph {
private:
	// define edges as a type
	typedef std::pair<std::shared_ptr<T>, bool> edge;
	// define map of nodes as a type
	typedef std::map<T, std::vector<typename digraph::edge>> nodeMap;
	// construct map to hold stored nodes
	typename digraph::nodeMap nodes;

public:
	// default constructor
	digraph();

	// constructor with pre-defined map of nodes
	digraph(typename digraph::nodeMap);

	// destructor
	~digraph();

	// return the size of the graph
	int size();

	// returns true if graph is empty
	bool empty();

	// return vector of iterators pointing to nodes with value
	std::vector<typename digraph::nodeMap::iterator> at(T);

	// push a node to the graph
	std::pair<typename digraph::nodeMap::iterator, bool> push(T, std::vector<typename digraph::edge>);

	// erase at specific iterator and return T
	T erase(typename digraph::nodeMap::iterator);

	// erase all nodes and return their values in a range
	std::vector<T> erase_r(typename digraph::nodeMap::iterator, typename digraph::nodeMap::iterator);
	
	// erase all with a certain value of T, return the count of how many erased
	int erase_a(T);
};

// default class constructor
template <class T>
digraph<T>::digraph() {
	digraph<T>::nodes = new digraph<T>::nodeMap;
};

// class constructor with provided node map
template <class T>
digraph<T>::digraph(typename digraph<T>::nodeMap nm) {
	// dynamically allocate new node map
	&digraph<T>::nodes = new std::shared_ptr<digraph<T>::nodeMap>

	// create iterator to loop through the map
	typename digraph<T>::nodeMap::iterator it = nm.start();

	// emplace key/value pairs from the provided map into the digraphs map
	for (; it != nm.end(); it++) {
		digraph<T>::nodes.emplace((*it).first,(*it).second);
	}
};

// class destructor
template <class T>
digraph<T>::~digraph() {

};

// return the amount of nodes in the graph
template <class T>
int digraph<T>::size() {

};

// check if empty (empty:not empty ? true:false)
template <class T>
bool digraph<T>::empty() {

};

// get vector of iterators pointing to each node with provided value
template <class T>
std::vector<typename digraph<T>::nodeMap::iterator> digraph<T>::at(T val) {

};

// push a node into the graph
template <class T>
std::pair<typename digraph<T>::nodeMap::iterator, bool> push(T n, std::vector<typename digraph<T>::edge> evec) {

};

// erase a node a specific iterator position and return its value
template <class T>
T digraph<T>::erase(typename digraph<T>::nodeMap::iterator pos) {

};

// erase nodes in a range and return their values
template <class T>
std::vector<T> digraph<T>::erase_r(typename digraph<T>::nodeMap::iterator start, typename digraph<T>::nodeMap::iterator end) {

};

// erase all nodes with a certain value and return the amount of total nodes erased
template <class T>
int digraph<T>::erase_a(T val) {

};

int main() {
	return 0;
}