
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <memory>



class graph {
public:

	struct node {
		double value;
		double getValue() {return value;}
		void setValue(double val) {value=val;}
	};

	// construct a graph with the provided map of <node, node vector>
	graph(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > > n) {
		for(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator out = n.begin(); out != n.end(); out++) {
			nodes.emplace(out->first,out->second);
		}
	}

	// graph destructor
	~graph() {
		// delete all nodes from graph, smart pointers will free the memory on their own
		for(std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator out = nodes.begin(); out != nodes.end(); out++) {
			nodes.erase(out);
		}
		// free the memory used by the graph's nodes
		free(&nodes);
	}

	// get nodes connected to specified entry node
	std::vector< std::shared_ptr<node> > getConnected(std::shared_ptr<node> entry) {
		return nodes[entry];
	}

	// add an edge to a specified node
	void pushEdge(std::shared_ptr<node> entry, std::shared_ptr<node> end) {
		nodes[entry].push_back(end);
		nodes[end].push_back(entry);
	}

	// emplace node with provided entry node and edges
	void push(std::shared_ptr<node> entry, std::vector<std::shared_ptr<node>> connections) {
		// emplace new node
		nodes.emplace(entry, connections);

		// fix connections from each node that shares an edge with the node to be added
		for (std::vector<std::shared_ptr<node>>::iterator iter = connections.begin(); iter != connections.end(); iter++) {
			nodes.at(*iter).push_back(entry);
		}
	}

	// remove a node from the graph and return its value
	double pull(std::shared_ptr<node> entry) {

		// intialize iterator
		std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator iter = getIter(entry);

		// iterate through the map
		for (std::map<std::shared_ptr<node>, std::vector< std::shared_ptr<node> >>::iterator out = nodes.begin(); out != nodes.end(); out++) {
			// iterate through the edges of each node and remove edges referencing the node
			for (std::vector<std::shared_ptr<node>>::iterator in = out->second.begin(); in != out->second.end(); in++) {
				if ((*in) == entry) {
					out->second.erase(in);
				}
			}
		}

		// get the value of the node to return
		double val = iter->first->getValue();

		// erase the node from the map
		nodes.erase(iter);

		// return the value of the removed node
		return val;
	}
protected:

	// map of nodes in format
	//	< Key: smart shared pointer refencing a node,
	//	Value: vector of smart shared pointers referencing other nodes (essentially edges) >
	std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > > nodes;

private:

	// return an iterator pointing to a node in the graph
	std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator getIter(std::shared_ptr<node> entry) {
		// initialize iterator
		std::map< std::shared_ptr<node>, std::vector< std::shared_ptr<node> > >::iterator iter;
		// loop through graph nodes
		for (iter = nodes.begin(); iter != nodes.end(); iter++) {
			if (iter->first == entry) {
				return iter;
			}
		}
	}
};

int main() {
	return 0;
}