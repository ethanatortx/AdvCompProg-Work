// digraph

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <memory>

template <class T>
class digraph {

private:
	// edge
	typedef std::pair<std::shared_ptr<T>, bool> edge;
	// node map
	typedef std::map<std::shared_ptr<T>, std::vector<typename digraph::edge>> nodemap;
	// declare nodes map
	typename digraph::nodemap nodes;

public:
	// default constructor
	digraph();
	// construct from provided map
	digraph(typename digraph::nodemap);
	// destructor
	~digraph();
	// return whether or not graph contains any nodes
	bool empty();
	// return count of nodes in graph
	int size();
	// add an edge to a node
	void add_edge(std::shared_ptr<T>, typename digraph::edge);
	// insert node
	typename digraph::nodemap::iterator push(std::shared_ptr<T>, std::vector<typename digraph::edge>);
	// insert multiple nodes
	std::vector<typename digraph::nodemap::iterator> push_mult(std::vector<std::pair<std::shared_ptr<T>, std::vector<typename digraph::edge>>>);
	// create and insert node
	typename digraph::nodemap::iterator emplace(T, std::vector<typename digraph::edge>);
	// create and insert multiple nodes
	std::vector<typename digraph::nodemap::iterator> emplace_mult(std::vector<std::pair<T, std::vector<typename digraph::edge>>>);
	// erase node (pointer)
	void erase(std::shared_ptr<T>);
	// erase node (iterator)
	void erase(typename digraph::nodemap::iterator);
	// erase node and return its value (pointer)
	T pull(std::shared_ptr<T>);
	// erase node and return its value (iterator)
	T pull(typename digraph::nodemap::iterator);
	// erase all nodes in the provided vector
	void erase_v(std::vector<std::shared_ptr<T>>);
	// erase all nodes in a range
	void erase_r(typename digraph::nodemap::iterator, typename digraph::nodemap::iterator);
	// erase all nodes in the provided vector and return their values
	std::vector<T> pull_v(std::vector<std::shared_ptr<T>>);
	// erase all nodes in a range and return their values
	std::vector<T> pull_r(typename digraph::nodemap::iterator, typename digraph::nodemap::iterator);
	// erase all nodes with value and return count of nodes erased
	int erase_a(T);
	// print out all nodes' values and their edges
	void printall();
};

template <class T>
digraph<T>::digraph() {};

template <class T>
digraph<T>::digraph(typename digraph<T>::nodemap nmap) {};

template <class T>
digraph<T>::~digraph() {};

template <class T>
bool digraph<T>::empty() {};

template <class T>
int digraph<T>::size() {};

template <class T>
void digraph<T>::add_edge(std::shared_ptr<T> n, typename digraph<T>::edge e) {};

template <class T>
typename digraph<T>::nodemap::iterator digraph<T>::push(std::shared_ptr<T> n, std::vector<typename digraph<T>::edge> evec) {};

template <class T>
std::vector<typename digraph<T>::nodemap::iterator> digraph<T>::push_mult(std::vector<std::pair<std::shared_ptr<T>, std::vector<typename digraph<T>::edge>>> nvec) {};

template <class T>
typename digraph<T>::nodemap::iterator digraph<T>::emplace(T val, std::vector<typename digraph<T>::edge> evec) {};

template <class T>
std::vector<typename digraph<T>::nodemap::iterator> digraph<T>::emplace_mult(std::vector<std::pair<T, std::vector<typename digraph<T>::edge>>> nvec) {};

template <class T>
void digraph<T>::erase(std::shared_ptr<T> n) {};

template <class T>
void digraph<T>::erase(typename digraph<T>::nodemap::iterator n) {};

template <class T>
T digraph<T>::pull(std::shared_ptr<T> n) {};

template <class T>
T digraph<T>::pull(typename digraph<T>::nodemap::iterator n) {};

template <class T>
void digraph<T>::erase_v(std::vector<std::shared_ptr<T>> nvec) {};

template <class T>
void digraph<T>::erase_r(typename digraph<T>::nodemap::iterator start, typename digraph<T>::nodemap::iterator end) {};

template <class T>
int digraph<T>::erase_a(T val) {};

template <class T>
std::vector<T> digraph<T>::pull_v(std::vector<std::shared_ptr<T>> nvec) {};

template <class T>
std::vector<T> digraph<T>::pull_r(typename digraph<T>::nodemap::iterator start, typename digraph<T>::nodemap::iterator end) {};

template <class T>
void digraph<T>::printall() {};

int main() {
	return 0;
}