
#include <vector>
#include <iostream>
#include <map>

class graph {

public:
	class node {
	public:
		// value of this node
		double value;

		// return value
		double getValue() {
			return value;
		}

		// set value
		void setValue(double val) {
			value = val;
		}
	};

	~graph() {
		std::map<node*,std::vector<node*>>::iterator iter;
		for (iter = nodes.begin(); iter != nodes.end(); ++iter)
		{
			nodes.erase(iter);
		}
	};

	std::vector<graph::node*> getNodes(node* n) {
		return nodes[n];
	};

	void insertNode(node* n, std::vector<graph::node*> nVec) {
		node* t = new node();
		for (int outside = 0; outside < nVec.size(); ++outside){
			
		}
	};
private:
	// map of nodes
	// key: node pointers
	// value: vector of pointers to other nodes (essentially edges)
	std::map<node*, std::vector<graph::node*>> nodes;
	unsigned int size;
};

int main() {
	return 0;
}