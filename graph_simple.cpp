// simple graph class

#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <algorithm>
#include <utility>
#include <typeinfo>

// simple graph class constructor
class graph {
public:
	class node {
	public:
		// value of this node
		double value;

		// constructor
		node() {
			value = 0;
		}

		node(double val) {
			value = val;
		};

		// destructor
		~node() {
			value = 0;
		}

		// return value of node
		double getValue() {
			return value;
		};

		// set value of node
		void setValue(double val) {
			value = val;
		};
	};

	// default constructor
	graph() {
		size = 0;
	};

	/* constructor elements
		keys: std vector of shared smart pointers that serve as the keys to be added to the map in its initialization
	  values: vector of <vector of shared smart pointers> that are the values to be paired with the keys at the same index
	*/
	graph(std::vector< std::shared_ptr<node> > keys, std::vector< std::vector<std::shared_ptr<node> > > values) {
		size = keys.size(); // set graph size to the size of the provided keys vector
		for (int i = 0; i < size; i++) { // emplace each node within the map as a key with its coresponding vector value
			nodes.emplace(keys[i], values[i]);
		}
	};

	// destructor; not done
	~graph() {

	};

	// operator overload of accessor, return value at index
	double operator[] (unsigned int index) {
		std::shared_ptr<node> n = getKey(index); // get key node at position: (index)
		return n->getValue(); // return the value of the key node at position: (index)
	};

	// insert provided node into graph
	void addNode(std::shared_ptr<node> n, std::vector< std::shared_ptr<node> > nvec) {
		nodes.emplace(n, nvec); // insert node into nodes map

	};

	// create a node from supplied value and insert it into graph
	void createNode(double val, std::vector<std::shared_ptr<node>> nvec) {
		// create new node with value: (val)
		std::shared_ptr<node> n (new node(val)); 
		// emplace value and retrieve pair <iterator ref, fail:succeed>
		std::pair<std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator, bool> p (nodes.emplace(n, nvec)); 
		// if emplacement fails, throw an error stating that the node already exists within the graph
		if (!(p.second)) { std::string error("Node already in <nodes> map"); throw std::domain_error(std::string(error)); }
		// add refences to this node within the map
		addReferences(p.first);
	};

	// remove a node from the graph and return its value
	double pull(std::shared_ptr<node> node) {
		double val = node->getValue();

		for (std::map< std::shared_ptr<graph::node>, std::vector< std::shared_ptr<graph::node> > >::iterator outside = nodes.begin(); outside != nodes.end(); outside++) {
			for (std::vector< std::shared_ptr<graph::node> >::iterator inside = (*outside).second.begin(); inside != (*outside).second.end(); inside++) {
			}
		}

		return val;

	};

	// return all values of nodes in vector form
	std::vector< double > getAll() {
		// temp holder for keys held in the map
		std::shared_ptr< node > temp;
		// vector to hold values of all key nodes
		std::vector< double > vals;
		// iterate through the map of nodes
		for (std::map< std::shared_ptr<graph::node>, std::vector< std::shared_ptr<graph::node> > >::iterator it = nodes.begin(); it != nodes.end(); ++it) {
			temp = (*it).first; // get the key in reference to the current place of the iterator
			vals.push_back(temp->getValue()); // push the value of the current key to the return vector
		}
		delete &temp; // delete temporary key holder
		return vals; // return values vector
	};

	// return all nodes at a certain amount of steps from a provided node
	// this doesnt work at all
	std::vector< std::vector<node> > stepsFrom(std::shared_ptr<node> n, int steps) {

		std::vector< std::vector< std::shared_ptr<node> > > ret; // return vector; vector of vectors (each contained vector is ALL nodes the next step removed from the previos node step)
		std::vector< std::shared_ptr<node> > temp_v;
		std::shared_ptr<node> temp_n;

		for(; steps>0; steps--) {
		}
	};

protected:

	/* map of nodes in graph
		<key: smart pointer to a specific node (essentially a node),
	   value: vector of smart pointers referencing other nodes (essentially the edges of node: (key))> */
	std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > > nodes;
	// size of graph (amount of active nodes)
	unsigned int size;

private:
	// return the key at a certain index
	std::shared_ptr<node> getKey(unsigned int index) {
		// create iterator
		std::map<std::shared_ptr<node>, std::vector< std::shared_ptr<node> >>::iterator it = nodes.begin();
		do { it++; index--; } while(index>0); // repeat (steps) amount of times, incrementing the iterator
		return it->first; // return the key at position (it)
	};

	// fix references to a node
	void addReferences(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator it) { // param it: map iterator to the node references are being corrected towards
		// smart pointer in reference to the first term of the provided node within the graph
		std::shared_ptr<node> n = (*it).first;
		// vector contained in second term of pair pointer at by provided iterator
		std::vector<std::shared_ptr<node>> ref = (*it).second;

		// iterate through the map
		for(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator outside; outside != nodes.end(); outside++) {
			// iterate through the edges of provided node
			for (std::vector<std::shared_ptr<node> >::iterator inside = ref.begin(); inside != ref.end(); inside++) {
				if ((*inside == (*outside).first) && ((*outside).first != n)) { // compare the current node in the map iteration
					outside->second.push_back(n);
				}
			}
		}
	};

	void removeRefences(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator it) {

		// define provided node
		std::shared_ptr<node> n = (*it).first;

		// define edges of provided node
		std::vector<std::shared_ptr<node>> ref = (*it).second;

		// use a map iterator to list through all nodes
		for (std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator outside; outside != nodes.end(); outside++) {
			// iterate through the edges of the current node in the map iterator
			if ((*outside).first != n) { // perform this operation for all nodes BUT the provided node, it is unecessary to do this for the provided node as it is getting removed anyway
				for (std::vector<std::shared_ptr<node> >::iterator inside = (*outside).second.begin(); inside != (*outside).second.end(); inside++) {
					if (*inside == n) { // compare the current edge of the current node to the provided node
						(*outside).second.erase(inside); // erase the edge referenceing the provided node
					}
				}
			}
		}
	};
};

int main() {
	return 0;
}