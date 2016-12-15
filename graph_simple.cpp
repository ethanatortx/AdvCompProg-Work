// simple graph class

#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <algorithm>
#include <utility>

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

	graph() {
		size = 0;
	};

	~graph() {
		
	};

	// opeartor overload of accessor, return value at index
	double operator[] (unsigned int index) {
		std::shared_ptr<node> n = getKey(index);
		return n->getValue();
	};

	// return all values of nodes in vector form
	std::vector< double > getAll() {
		// temp holder for keys held in the map
		std::shared_ptr< node > temp;
		// vector to hold values of all key nodes
		std::vector< double > vals;
		// iterate through the map of nodes
		for (std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator it = nodes.begin(); it != nodes.end(); ++it) {
			temp = (*it).first; // get the key in reference to the current place of the iterator
			vals.push_back(temp->getValue()); // push the value of the current key to the return vector
		}
		delete &temp; // delete temporary key holder
		return vals; // return values vector
	};

	// return all nodes at a certain amount of steps from a provided node
	std::vector< std::vector<node> > stepsFrom(std::shared_ptr<node> n, int steps) {

		std::vector< std::vector< std::shared_ptr<node> > > ret; // return vector; vector of vectors (each contained vector is ALL nodes the next step removed from the previos node step)
		std::vector< std::shared_ptr<node> > temp_v;
		std::shared_ptr<node> temp_n;

		for(; steps>0; steps--) {
		}
	};

protected:
	std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > > nodes;
	unsigned int size;

	// return the key at a certain index
	std::shared_ptr<node> getKey(unsigned int index) {
		std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator it = nodes.begin();
		do { it++; index--; } while(index>0);
		return it->first;
	};
};

int main() {
	return 0;
}