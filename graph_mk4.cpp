
#include <vector>
#include <iostream>

class diGraph {
	class node {
		class edge {
		public:
			node* start; // pointer to beginning of edge
			node* end;	// pointer to end of edge

			// get functions
			node* getStart() { // get start pointer
				return start;
			};

			node* getEnd() { // get end pointer
				return end;
			};

			// set functions
			void setStart(node* s) { // set start pointer
				start = s;
			};

			void setEnd(node* e) { // set end pointer
				end = e;
			};

		};
	public:
		double value; // variable containing value of current node
		std::vector< edge* > outgoing; // vector of edges this node references
		std::vector< edge* > incoming; // vector of edges referencing this node

		// default constructor
		node() {
			value = 0.0;
		};

		// destructor
		~node() {
			delete &outgoing;
			delete &incoming;
			value = 0.0;
		};

		void setValue(double val) { // sets value of this node
			value = val;
		};

		double getValue() { // returns value of this node
			return value;
		};

		edge* getOutgoingEdge(node* n) { // return the edge connecting to a specific reference node
			
			return outgoing[indexOfOutgoing(n)];
		};

		edge* getIncomingEdge(node* n) { // return the edge connecting to this node from a specific reference node
			
			return incoming[indexOfIncoming(n)];
		};

		void removeOutgoingEdge(node* n) { // remove an edge from the outgoing vector
			int index = indexOfOutgoing(n);
			outgoing.erase(outgoing.begin()+index);
		};

		void removeIncomingEdge(node* n) { // remove an edge from the incoming vector
			int index = indexOfIncoming(n);
			incoming.erase(incoming.begin()+index);
		};

	private:
		int indexOfOutgoing(node* n) { // return index of edge from current node to specfied node

			// count iterator
			int count;

			// loop through outgoing edge vector
			for (count = 0; count < outgoing.size(); count++) {
				// compare end pointer of current outgoing edge to reference node
				if (outgoing[count]->end == n) {
					return count; // return current index
				}
			}
		};

		int indexOfIncoming(node* n) { // return index of edge from specfied node to this node 

			// count iterator
			int count;

			// loop through incoming edge vector
			for (count = 0; count < incoming.size(); count++) {
				// compare start pointer of current incoming edge to reference node
				if (incoming[count]->start == n) {
					return count; // return current index
				}
			}
		};
	};

public:
	// default constructor
	diGraph() {
		size = 0;
	};

	// destructor for the graph
	~diGraph() {
		delete &nodes;
		size = 0;
	};

	void addNode(node* node) {

	}

private:
	unsigned int size;
	std::vector< node > nodes;
};

int main() {



	return 0;
}