
#include <iostream>
#include <memory>
#include <vector>


template <class T>
class graph {
public:
	class node;

	// define node id as type
	typedef typename std::vector<graph<T>::node>::iterator nodeid;

	// main node class functionality
	class node {

		// pre-declare edge for node's edge vector declaration
		class edge;
		
		/* side note on the id thing:
			I don't think I want anyone to be able to modify this in any
			way outside the node declaration. I think that could only end badly,
			but I'll come back to this later and add that functionality if it's
			needed.
		*/

		// id of this node
		typename graph<T>::nodeid id;
		// vector of edges belonging to this node
		std::vector<graph<T>::node::edge> edges;
		// value of this node
		T value;

		// edge class functionality
		class edge {
			typename graph<T>::nodeid origin; // starting node for this edge
			typename graph<T>::nodeid destination; // ending node for this edge

		public:

			// constructor
			edge(typename graph<T>::nodeid&& o, typename graph<T>::nodeid&& d) {
				origin = o;
				destination = d;
			}

			// get and set for origin of this edge
			typename graph<T>::nodeid getOrigin() {
				return origin;
			}

			void setOrigin(typename graph<T>::nodeid&& id) {
				origin = id;
			}

			// get and set for destination of this edge
			typename graph<T>::nodeid getDest() {
				return destination;
			}

			void setDest(typename graph<T>::nodeid&& id) {
				destination = id;
			}
		};

	public:

		// constructor
		node(typename graph<T>::nodeid i) {
			
		}

		node(typename graph<T>::nodeid i, T val, std::vector<typename graph<T>::node::edge> evec) {

		}

		// get the id of the node
		typename graph<T>::nodeid getid();
	
		// dereference node and return value of this node
		T& operator*() {
			return value;
		}

		// return the value held by the node
		T getValue();

		// set the value of the node
		void setValue(T);
		
		/*
		add an edge to the node
			if there is no edge pointing to the supplied node, add the edge to the vector
				and return an iterator pointing to the new edge's position within the vector
				and a bool of TRUE representing that the edge was succesfully inserted
		
			if there is already an edge pointing to the specified node, 
				return an iterator pointing to the edge that was already in place
				and a bool of FALSE indicating that no edge was inserted 
		*/
		std::pair<typename std::vector<graph<T>::node::edge>::iterator, bool> addEdge(typename graph<T>::nodeid&&);

		/*
		remove an edge leading to a specified node
			if no edge exists leading to the specified node,
				return FALSE indicating that no edge could be removed since it didn't exists

			if there is an edge pointing to the supplied ref,
				remove the edge from the edges vec
				and return TRUE indicating the edge was removed
		*/
		bool removeEdge(typename std::vector<graph<T>::node::edge>::iterator&&);

		// check if there is an edge leading to the specified node
		bool isConnected(typename graph<T>::nodeid&&);
	};

private:

	// declare node vector
	std::vector<graph<T>::node> nodes;

public:

	graph(std::vector<T>&&, std::vector<std::vector<typename graph<T>::nodeid>>&&);

	~graph();

	graph<T> &operator=(graph<T>&&);

	std::pair<T, std::vector<graph<T>::nodeid>> at(typename graph<T>::nodeid&&);

	bool empty();

	int size();

	std::pair<typename graph<T>::nodeid, bool> add(T&&, std::vector<typename graph<T>::nodeid>&&);

	/*
		maybe implement this later, not sure yet:
	std::vector<std::pair<typename graph<T>::nodeid, bool>> add_multiple(std::vector<T&&>, std::vector<std::vector<typename graph<T>::nodeid&&>>);
	*/

	bool erase(typename graph<T>::nodeid&&);

	/*
		maybe implement this also:
	std::vector<bool> erase_multiple(std::vector<typename graph<T>::nodeid&&>);
	*/

	T extract(typename graph<T>::nodeid&&);

	/*
		and this:
	T extract_multiple(std::vector<typename graph<T>::nodeid&&>);
	*/

	bool link(graph<T>::nodeid&&, graph<T>::nodeid&&);

	int path(graph<T>::nodeid&&, graph<T>::nodeid&&);
};

int main() {return 0;}