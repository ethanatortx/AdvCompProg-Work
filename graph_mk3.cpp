
#include <vector>
#include <iostream>

// digraph class declaration
class diGraph{
	// node class declaration
	class node {
	public:
		
		// edge class declaration
		class edge {
		public:
			node* start;
			node* end;
			
			node* getStart() {
				return start;
			};

			node* getEnd() {
				return end;
			};

			void setStart(node* n) {
				start = n;
			};

			void setEnd(node* n) {
				end = n;
			};
		};

		int value; // value of the node
		std::vector< edge > edges; // vector conatining all edges of the node, OUTGOING only

		// return the value of the node
		int getValue() {
			return value;
		};

		// set the value of the node
		void setValue(int val) {
			value = val;
		};

		// return the edge reference that points to a provided node
		edge getEdgeToNode(node* n) {

			// loop through vector conatining all edges
			for (int i = 0; i < edges.size(); ++i) {
				// check if the current edge's end pointer is that of the specified node
				if (edges[i].end == n) {
					return edges[i]; // return the edge that connects this node to the specified node
				}
			}

			// throw an error if no connection is found
			std::string error("No edge pointing to specified node");
			throw std::domain_error(std::string(error));
		};
	};

	

public:

private:
	unsigned int size;
	std::vector<node> nodes;
};