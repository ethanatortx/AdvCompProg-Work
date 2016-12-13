
#include <vector>
#include <iostream>

class graph {
	
};

class diGraph {
};

// digraph where nodes have multiple edges
class multiDiGraph {
public:
	class multiNode { // node with multiple edges
	public:
		class edge {
		public:
			multiNode *start; // pointer to start of the edge
			multiNode *end;	 // pointer to end of the edge

			multiNode* getstart() { // return starting pointer of this edge
				return start;
			};

			multiNode* getEnd() { // return end pointer of this edge
				return end;
			};

			void setStart(multiNode* n) { // set the starting pointer of this edge
				start = n;
			};

			void setEnd(multiNode* n) { // set the end pointer of this edge
				end = n;
			};
		};



		std::vector< edge* > outgoing;
		std::vector< edge* > incoming;
		double value;

		std::vector< multiNode* > allAccessable() { // return all nodes accessable from this node
			
			std::vector< multiNode* > vec; // vector to contain addresses of reachable nodes
			for (int i = 0; i < outgoing.size(); ++i) {
				vec.push_back(outgoing[i]->end); // add the pointer at the end of the current edge to the return vector
			}
		}
	};
};

int main() {
	return 0;
}
