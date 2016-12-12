
#include <iostream>
#include <vector>

class diGraph {
	class node {
		class edge {
		public:
			int origin; 
			int end;
			
			void setEnd(int e) {
				end = e;
			};

			void setOrigin(int o) {
				origin = o;
			};

			int getEnd() {
				return end;
			};

			int getOrigin() {
				return origin;
			};
		}

	public:
		int value; // value of this node
		vector<edge> originating; // vector of edges originating AT this node
		vector<edge> recieving; // vector of edges pointing TO this node

		node() {
			value = 0;
		}

		~node() {
			delete originating;
			delete recieving;
			value = 0;
		}

		// operator overload functions within the node class are made to ease iteration of the value variable
		// operator overload for ++
		void operator ++ () {
			value += 1;
		};

		// operator overload for +=
		int operator += (int mod) {
			value += mod;
		};

		// operator overload for --
		void operator --() {
			value -= 1;
		};

		// operator overload for -=
		void operator -= (int mod) {
			value -= mod;
		};

		// specific value mod functions
		// set value
		void setValue(int val) {
			value = val;
		};

		// return value
		int getValue() {
			return value;
		};

		// edge mod functions
		// add incoming edge
		void addIncomingEdge(edge* e) {
			recieving.push_back(e);
		};

		// add outgoing edge
		void addOutgoingEdge(edge* e) {
			originating.push_back(e);
		};

		// get edge leading to specified reference
		edge* getEdgeOutgoing(int ref) {
			for (std::vector<node>::iterator i = .begin(); i != .end(); ++i) {
				if (outgoing[i] == ref) {
					return outgoing[i];
				}
			}

			std::string error("No edge of that destination");
			throw std::domain_error(std::string(error));
		}

		// get edge originating at specified reference
		edge* getEdgeRecieving(int ref) {
			for (std::vector<edge>::iterator i = .begin(); i != .end(); ++i) {
				if (recieving[i] == ref) {
					return recieving[i];
				}
			}

			std::string error("No edge of that origin");
			throw std::domain_error(std::string(error));
		}

		void removeOutgoingEdge(int ref) {

			// loop until an outgoing edge matching the provided reference is found
			for (std::vector<edge>::iterator i = .begin(); i != .end(); ++i) {
				if (outgoing[i] == ref) {
					outgoing.erase(i); // erase the edge at the specified ref
					return;
				}
			}

			std::string error("No edge of that destination");
			throw std::domain_error(std::string(error));
		};

		void removeIncomingEdge(int ref) {

			// loop until an incoming edge matching the provided reference is found
			for (std::vector<edge>::iterator i = .begin(); i != .end(); ++i) {
				if (recieving[i] == ref) {
					recieving.erase(i); // erase the edge at the specified ref
					return;
				}
			}

			std::string error("No edge of that origin");
			throw std::domain_error(std::string(error));
		};
	}

public:
	// default constructor
	diGraph() {
		size = 0;
	};

	// destructor
	~diGraph() {
		delete nodes;
		size = 0;
	};

	void setNodeValue(node* n, int val) {
		for (std::vector<node>::iterator i = .begin(); i != .end(); ++i) {
			if (nodes[i] == n) { // compare current node in nodes vector to provided node address

				// assign value of the node to the value
				nodes[i].setValue(val);
				return; // return nothing to end script
			}
		}

		// if the node is not found, throw out of domain error
		std::string error("No node of specified reference");
		throw std::domain_error(std::string(error));
	};

	// set the size of the graph
	void setSize(int s) {
		size = s;
	};

	// return the value of a node referenced by an edge
	

	// insert node into graph
	void addNode(node* node) {
		
		// declarations for temporary edge containers
		int o; // outgoing
		int r; // recieving

		// loop through the nodes within the digraph
		for (int out = 0; out < size; out++) { // out: outside loop iterator for nodes within local digraph

			// loop through the outgoing edges within the specified node
			for (int in_outg = 0; in_outg < nodes[out]->recieving.size(); in_outg++) { // in_outg: inside loop iterator for outgoing edges

				// assign the current edge to a local variable
				o = *(node->recieving[in]);

				// compare the end of the edge for the specified node with the address of the current node within the digraph
				if (o.end == &nodes[out]) {
					nodes[out].addIncomingEdge(o); // add the edge connecting the supplied node to the current node within the digraph
					break; // break out of the for loop
				}
			}

			// loop through the outgoing edges within the specified node
			for (int in_rec = 0; in_rec < nodes[out]->originating.size(); in_rec++) { // int_red: inside loop iterator for incoming edges

				// assign the current edge to a local variable
				r = *(node->originating[in_rec]);

				// compare the end of the edge for the specified node with the address of the current node within the digraph
				if (r.end == &nodes[out]) {
					nodes[out].addOutgoingEdge(r); // add the edge connecting the supplied node to the current node within the digraph
					break; // break out of the for loop
				}
			}
		}

		// add node to digraph nodes vector
		nodes.push_back(node);

		// increment size by one
		size += 1;
	}

	void addNodeMultiple(std::vector<node> n) {
		// iterate through provided node vector
		for (std::vector<node>::iterator i = .begin(); i != .end(); ++i) {
			addNode(n[i]); // use add node function to add each node to the nodes vertor within the digraph
		}
	}

	// remove a node and the references to and from it from the graph; return its value
	int pull(Node* node) {
		int ind = getIndexOf(node);
		int* o;
		int* r;
		if (ind >= 0) {

			for (std::vector<node>::iterator i = .begin(); i != .end(); ++i) {

				for (int in_outg = 0; in_outg < nodes[i]->originating.size(); in_outg++) { // in_outg: inside loop iterator for outgoing edges
					o = (nodes[i]->originating[in_outg]);

					if (o->end == node) {
						nodes[i].removeOutgoingEdge(o);
					}
				}

				for (int in_rec = 0; in_rec < nodes[i]->recieving.size(); in_rec++) { // int_red: inside loop iterator for incoming edges
					r = (nodes[i]->recieving[in_rec]);

					if (r->origin == node) {
						nodes[i].removeIncomingEdge(r);
					}
				}
			}

			int val = nodes[ind].getValue();
			nodes.erase(ind);
		}
	};

private:
	int size; // size of the graph;
	vector<node> nodes; // vector of nodes within this graph

	// returns -1 if no node matching the ref is found
	int getIndexOf(node* node) {
		for (std::vector<node>::iterator i = .begin(); i != .end(); ++i) {
			if (nodes[i] == node) {
				return i;
			}
		}

		return -1;
	}
}

int main() {

	diGraph G = new diGraph();

	node node1 = new node();
	node node2 = new node();

	vector<node> nodes{2,node1,node2};

	edge connection = new edge(&node1, &node2) // edge from the address of node 1 to the address of node 2

	node1.addOutGoingEdge(connection);
	node2.addIncomingEdge(connection);

	diGraph.addNodeMultiple(nodes);
	return 0;
}