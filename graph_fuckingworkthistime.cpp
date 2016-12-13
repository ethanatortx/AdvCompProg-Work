
#include <vector>
#include <iostream>

class graph {
	
};

class diGraph {
};

// digraph where nodes have multiple edges
class multiDiGraph {
public:
	class node { // node with multiple edges
	public:
		class edge {
		public:
			node *start; // pointer to start of the edge
			node *end;	 // pointer to end of the edge

			node* getStart() { // return starting pointer of this edge
				return start;
			};

			node* getEnd() { // return end pointer of this edge
				return end;
			};

			void setStart(node* s) { // set the starting pointer of this edge
				std::cout << "deeptest" << std::endl;
				start = s;
				std::cout << "deeptest" << std::endl;
			};

			void setEnd(node* e) { // set the end pointer of this edge
				end = e;
			};
		};


		// node class stuff
		// edge variables
		std::vector< edge* > edges; // edges edge vector
		double value; // value of this node

		node() {
			value = 0.0;
		};

		~node() {
			delete &edges;
			value = 0.0;
		};

		// assignment operator overload
		void operator= (node* n) {
			value = n->value;
			edges.erase(edges.begin(),edges.end());
			edges = n->edges;
		};

		// return value
		double getValue() {
			return value;
		};

		// assign value of current node
		void setValue(double val) {
			value = val;
		};

		// add already defined edge
		void addEdge(edge* e) {
			edges.push_back(e);
		};

		// create incoming edge with specified end point
		void createEdge(node* start, node* end) {
			edge* e;
			e->setStart(start);
			e->setEnd(end);
			edges.push_back(e);
		};

		// return all nodes accessible from the current node
		std::vector<node*> allAccessable() { // return all nodes accessable from this node	
			std::vector< node* > vec; // vector to contain addresses of reachable nodes
			for (int i = 0; i < edges.size(); ++i) {
				vec.push_back(edges[i]->end); // add the pointer at the end of the current edge to the return vector
			}
		};

		edge* edgeTo(node* n) {
			int index = indexEdges(n);
			return edges[index];
		};

	private:
		int indexEdges(node* n) {
			for (int i = 0; i < edges.size(); ++i) {
				if (edges[i]->end == n) {
					return i;
				}
			}

			std::string error("No edges connection to node");
			throw std::domain_error(std::string(error));
		};
	}; // end of node class

	multiDiGraph() {
		size = 0;
	};

	~multiDiGraph() {
		size = 0;
		delete &nodes;
	};

	std::vector< node* > getNodes() {
		return nodes;
	};

	std::vector< std::vector< node* > > stepsFromNode(node* start, int steps) {
		std::vector< std::vector< node* > > vec;
		std::vector< node* > step;
		std::vector< node* > temp;
		node* tempPointer;

		// repeat gathering script (steps) amount of times
		while (steps>0) {
			// loop through the nodes of the current step
			for (int i = 0; i < step.size(); ++i) {
				// loop through the edges of the current node
				for (int k = 0; k < step[i]->edges.size(); ++k) {

					// get pointer to start of current edge
					tempPointer = step[i]->edges[k]->start;

					// compare start with the current node of the current step
					if (tempPointer == step[i]) {
						temp.push_back(step[i]->edges[k]->end); // append the end of the current edge to the temporary node pointer vector
					}
				}
			}
			vec.push_back(step); // add totaled step to the current step frame of the return vector
			step.erase(step.begin(),step.end()); // erase the current step
			step = temp; // set step equal to the totaled temporary step
			temp.erase(temp.begin(),temp.end()); // erase the previously totaled step
		}

		return vec;
	};


private:
	std::vector< node* > nodes;
	unsigned int size;
};

int main() {

	multiDiGraph::node* n = new multiDiGraph::node();
	multiDiGraph::node* n2 = new multiDiGraph::node();
	n->setValue(1988.125764);
	std::cout << n->value <<  std::endl;
	
	n->createEdge(n, n2);

	


	return 0;
}
