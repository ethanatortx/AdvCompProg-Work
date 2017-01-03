#ifndef __ADJACENCYMATRIXX_H_INCLUDED__
#define __ADJACENCYMATRIXX_H_INCLUDED__


template <class T>
class sgraph {

	struct Node {
		Node(const T& d, std::vector<Node*> e): data(d) {
			for (std::vector<Node*>::iterator i = e.begin(); i != e.end(); ++i) {
				edges.push_back(d[i]);
			}
		} 
		T data;	
		std::vector<Node*> edges;
	};

public:
};

#endif