
#include <vector>

// directed graph class definition (https://en.wikipedia.org/wiki/Directed_acyclic_graph)
class diGraph {

	// class definition for nodes (points of data within a graph connected by edges)
	/* 	NOTE:
		The way I have nodes defined, the class of each node only contains edges that originate
		at their own pointer. That way each edge is essentially 'directed' in that it always
		has a clear begin and end point that is easy to evaluate. The direction of each edge is
		ALWAYS from the edge it is associated with TOWARDS ANOTHER node. NO edges are associated
		with a node that point FROM another node. */
	class node {

		// class definition for edges (connections between nodes)
		class edge {
		public:
			// references for this edge (pointers to previous and subsequent nodes)
			int origin; // origin of the edge
			int end;	// end of the edge

			// remember these return pointers, need to dereference any returned values
			// returns end reference
			int getEnd() {
				return end;
			}

			// return origin reference 
			int getOrigin() {
				return origin;
			}

			// always pass these functions pointers, it wont work otherwise
			// set end of this edge to specified reference
			void setEnd(int e) {
				end = e;
			}

			// set origin of this edge to specified reference
			void setOrigin(int o) {
				origin = o;
			}
		}
	public:

		// value and edges of this node
		int value; // the value contained by this node
		std::vector<edge> edges; // vector containing all edges with this node as their origin
	
		// value modifiers:
		// set the value of this node
		void setValue(int val) {
			value = val;
		};

		// return value of this node
		int getValue() {
			return value;
		};

		// operator overload to increment value by one
		int operator ++() {
			value += 1;
		}

		// operator overload to decrement value by one
		int operator --() {
			value -= 1;
		}

		// edge modifiers:
		// add an edge to this node's edge definition
		void addEdge(edge* edge) {
			edges.push_back(edge);
		};

		// add multiple edges to the current node
		void addEdgeMult(vector<edge> vec) {

			// loop through the vector of new edges
			for (int i = 0; i < vec.size(); ++i) {
				edges.push_back(vec[i]); // add all new edges to the class vector containing this node's edges
			}
		}

		// return an edge that connects this node to the specified other node
		edge* getEdge(node* node) {

			// assign pointer to the specified node to a new variable
			const int pointer = &node;

			// declare edge end
			int edgeEnd;

			// loop through edge vector
			for (int i = 0; i < edges.size(); ++i) {

				// assign current edge destination to variable for comparison
				edgeEnd = edges[i]->end;

				// check if the current edge destination is equal to the pointer for the specified node
				if(end==pointer) {
					return *edges[i]; // return the edge connecting the two nodes
				}
			}

			// throws domain error if no edge connecting the two nodes (the current node and the specified) is found and returned
			std::string error("No edge directing to specified node");
			throw std::domain_error(std::string(error));
		};

		// return edges in reference to input nodes (NULL if no edge connection OUTGOING to specified node)
		vector<edge> getEdgeMult(vector<node*> nodes) {

			vector<edge> retVec{nodes.size(),NULL};

			// loop through node list
			for (int o = 0; o < nodes.size(); o++) {

				// loop through the edges of THIS node to check for connections with the current node in node list
				for (int i = 0; i < edges.size(); i++) {

					// check if the current edge connects to the current node within the specified nodes list
					if (edges[i]->end == nodes[o]) {
						retVec.push_back(edges[i]); // append TRUE edge to return vector
						break; // break out of the loop once a edge connecting the two has been found
					}
				}
			}
			return retVec;
		}

		// clear all edges from this node (remove all OUTGOING edges)
		void clearEdges() {
			edges.resize(0); // set the size of the edges vector to zero(0), effectively deleting all edges OUTGOING from this node
		}
	}
public:

	// default constructor
	diGraph() {
		size = 0;
	}

	// destructor
	~diGraph() {
		delete nodes;
	}

	void setNode(node* node, int value) { // set the value of a specific node that already exists
		for (int i = 0; i < nodes.size(); ++i) {
			if(&nodes[i] == node) {
				nodes[i].setValue(value);
				break;
			}
		}
	}

	int getSize() { // return the size of the graph
		return size;
	};

	void pull() { // pull a node out, deleting all references to it within the graph, and return the node's value

	};

	void push() { // insert a node into the graph, edges and all
		
	};

private:
	int size;
	std::vector<node> nodes;

}