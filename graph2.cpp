
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <memory>
#include <string>

template <class T>
class graph {
private:
	// define nodes, edges, and node maps as types for usage in function definition
	typedef std::shared_ptr<T> node;
	typedef std::vector<std::shared_ptr<T>> nodeVec;
	typedef std::map<typename graph::node, typename graph::nodeVec> nodeMap;
	
	// construct node map
	nodeMap nodes;

	// return iterator in reference to specific node
	typename graph::nodeMap::iterator getIter(typename graph::node);
	// return all keys and iterators pointing to those keys
	std::vector<std::pair<typename graph<T>::node, typename graph<T>::nodeMap::iterator>> getKeys();

public:
	// default constructor
	graph();
	// constructor with full map input
	graph(typename graph::nodeMap);
	// destructor
	~graph();
	// return amount of nodes in graph
	int size();
	// insert a node into the graph
	void push(typename graph::node, typename graph::nodeVec);
	// erase an element from the graph
	void erase(typename graph::nodeMap::iterator);
	// erase elements in a range from the graph
	void erase_r(typename graph::nodeMap::iterator, typename graph::nodeMap::iterator);
	// remove a node from the graph and return its value
	T pull(typename graph::node);
	// get node and edges from node
	std::pair<typename graph::node, typename graph::nodeVec> at(typename graph::node);
	// get edges at
	std::pair<typename graph::node, typename graph::nodeVec> operator[](typename graph::node);
	// get values connected to
	T connectedValues(typename graph::node);
};

// private function intialization

// get an iterator pointing to a specific node
template <class T>
typename graph<T>::nodeMap::iterator graph<T>::getIter (typename graph::node n) {
	typename graph::nodeMap::iterator pos = nodes.begin();
	for (; pos != nodes.end(); pos++) {
		if (pos->first == n) {
			return pos;
		}
	}
};

// return all nodes from the graph
template <class T>
std::vector<std::pair<typename graph<T>::node, typename graph<T>::nodeMap::iterator>> graph<T>::getKeys() {

	// declare return vector:
	// < First: key of a node,
	//  Second: iterator pointing to that node in the nodes map >
	std::vector<std::pair<typename graph<T>::node, typename graph<T>::nodeMap::iterator>> vec;	
	
	// loop through nodes map
	for (typename graph::nodeMap::iterator it = graph::nodes.begin(); it != graph::nodes.end(); it++) {
		// create a pair from the current node and an iterator pointing to it
		std::pair<typename graph::node, typename graph::nodeMap::iterator> p (*it.first,it);
		// add the newly created pair to the return vector (pass by value)
		vec.push_back(*p);
		// delete the pair to free memory
		delete p;
	}
	// return pair vector
	return vec;
};

// public function initialization
// graph class constructor
template <class T>
graph<T>::graph () {
};

// graph class constructor
template <class T>
graph<T>::graph (typename graph::nodeMap nm) {
	for (typename graph::nodeMap::iterator out = nm.begin(); out != nm.end(); out++) {
		graph::nodes.emplace(out->first,out->second);
	}
};

// graph class destructor
template <class T>
graph<T>::~graph () {
	graph::nodes.erase(nodes.begin(),nodes.end());
	delete &(graph::nodes);
	delete this;
};

// return amount of nodes in graph
template <class T>
int graph<T>::size() {
	int count = 0;
	for (typename graph::nodeMap::iterator it = graph::nodes.begin(); it != graph::nodes.end(); it++) {
		count++;
	}
	return count;
};

// get edges at node
template <class T>
std::pair<typename graph<T>::node, typename graph<T>::nodeVec> graph<T>::at(typename graph::node n) {
	typename graph::nodeMap::iterator it = getIter(n);
	return std::pair<(*it).first,(*it).second>;
}

// push function
template <class T>
void graph<T>::push (typename graph::node n, typename graph::nodeVec vec) { 
	graph::nodes.emplace(n,vec);
	for (typename graph::nodeMap::iterator out = graph::nodes.begin(); out != graph::nodes.end(); out++) {
		for (typename graph::nodeVec::iterator in = vec.begin(); in != vec.end(); in++) {
			if (*in == n) {
				out->second.push_back(n);
			}
		}
	}
};

// erase a node
template <class T>
void graph<T>::erase(typename graph::nodeMap::iterator position) {

	// loop through nodes
	for (typename graph::nodeMap::iterator out = graph::nodes.begin(); out != graph::nodes.end(); out++) {
		// dont perform comparison check on the node to be removed
		if (out->first != position->first) {
			// loop through the current nodes connections
			for (typename graph::nodeVec::iterator in = out->second.begin(); in != out->second.end(); in++) {
				// compare the current edge of the current node to the node to be removed
				if (*in == position->first) {
					out->second.erase(in); // remove the connection to the to-be-removed edge from the current node in the iteration
				}
			}
		}
	}
	// erase the node from the nodes map
	nodes.erase(position);
};

// erase a range of nodes
template <class T>
void graph<T>::erase_r(typename graph::nodeMap::iterator start, typename graph::nodeMap::iterator end) {

	// get the keys for comparison and reference
	std::vector<std::pair<typename graph::node, typename graph::nodeMap::iterator>> vec = graph::getKeys();

	for (; start != end; start++) {
		// loop through the pair<key,iter> vector
		for (typename std::vector<std::pair<typename graph::node, typename graph::nodeMap::iterator>>::iterator out = vec.begin(); out != vec.end(); out++) {
			// dont remove edges referencing this node from this node (the graph is not acyclical)
			if (out->first != start) {
				// loop through the edges within the current key iterator
				for (typename graph::nodeVec::iterator in = out->second->second.begin(); in != out->second->second.end(); in++) {
					// compare the current edge to the current node to be removed
					if (*in == start) {
						out->second.erase(in);
					} // if end
				} // for end
			} // if end
		} // for end

		// remove the current node in the remove cycle
		nodes.erase(start);
	} // for end
};

// erase a node from the graph and return its value
template <class T>
T graph<T>::pull(typename graph::node n) {
	T val = *n;
	typename graph::nodeMap::iterator it = getIter(n);
	graph::erase(it);
	return val;
}

int main() {
	graph<double> g;
	double temp = 9.24;
	std::shared_ptr<double> f1 (&temp);
	temp = 7.33;
	std::shared_ptr<double> f2 (&temp);

	std::vector<std::shared_ptr<double>> e1 = {f2};
	std::vector<std::shared_ptr<double>> e2 = {f1};

	g.push(f1, e1);
	g.push(f2, e2);


	std::cout << g.pull(f1) << "Hello World!" << std::endl;
	return 0;
}