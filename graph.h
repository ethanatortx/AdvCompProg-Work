

class graph {
	class node {
	public:

		float value;
		std::vector< int* > edges;
		void setValue(float val) {
			value = val;
		}
		float getValue() {
			return value;
		}
		void setAllEdges(std::vector< int* > vec) {
			edges = vec;
		}

		void setEdge(int index, int reference) {
			edges[index] = reference;
		}

		std::vector< int > getAllEdges() {
			return edges;
		}

		int getEdge(int index) {
			return edges[index];
		}
public:
	graph() {

	}

	~graph() {

	}

	int size() {
		return size;
	}

	bool adjacent() {

	}

	std::vector< int > neighbors(node* x) {

		std::vector< int > vec;
		for (int i - 0; i < this.size(); i++) {
			node* node = this[i];
			vec.push_back(node->value);
		}
		return vec;
	}

private:
	unsigned int size;
}