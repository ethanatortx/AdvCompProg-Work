

#include <iostream>
#include <stdexcept>

class linkedList() { // initialize linked list class
	friend class iterator;
	class Node {
	public:
		// initialize variables essential to node and linked list structure
		int value;	// value for node
		Node* next;	// pointer to next node in linked list
		Node* prev; // pointer to previous node in linked list

		void setNext(Node* n) { // set node pointer to previous node in list
			next = n;
		};
		void setPrev(Node* n) { // set node pointer to next node in list
			prev = n;
		};
	};
public:
	linkedList() { // default constructor
		head = NULL;
		tail = NULL;
		length = 0;
	};
	~linkedList() { // destroy nodes within origin linked list
		while(head != NULL && tail != NULL) pop();
	};

	unsigned int size() { // returns linked list size
		return length;
	};

	int &operator[](unsigned int place) { // operator overload for accessor
		// initialize node from copy of node in first position in linked list
		Node* node = head;

		// follow the linked list through until it reaches the specified index
		for (int i = 0; i < place; ++i) {

			// set node equal to pointer of next node
			node = node.next;

			// if node doesn't exist throw and out of range error
			if (node==NULL) {
				std::string error("Offset out of range");
				throw std::range_error(str::string(error));
			}
		}

		// return the node at position: place
		return node;
	};

	void add(int val) {
		// declare new node to add in
		Node* newNode = new Node();
		
		// set value of new node to provided value
		newNode.value = val;

		// check if there is a node at beginning of linked list
		if (head!=NULL) head.setPrev(newNode); // set head previous node indicator to pointer of the new node

		// modify next and previous pointers to connect list
		newNode.next = head;
		newNode.prev = NULL;
		head = newNode;

		// if new node is the only element to be in the list, set tail of list to be position of new node
		if (length==0) tail = newNode;

		// incriment list length by one to account for new node added to list
		length+=1;
	}

	void push(int val) {

		Node* newNode = new Node();
		newNode.value = val;
		if (tail != NULL) {
			tail.setNext(newNode);
		}
		newNode.prev = tail;
		newNode.next = NULL;
		tail = newNode;
		if (length == 0) {
			head = newNode;
		}

		length++;
	}

	void insert

	void pop

	void shift

	void remove

private:
	Node* nodeAt(int place) {
		Node* node = head;
		for (int i = 0; i < place; ++i) {

			node = node.next;

			if (node==NULL) {
				std::string error("Offset out of range");
				throw std::range_error(str::string(error));
			}
		}
		return node;
	}

	Node* head;
	Node* tail;
	unsigned int length;
}

class iterator() {
	friend class linkedList;
public:
	void begin();
	void operator++();
	void operator--();
	int operator*();
}

void main() {


}