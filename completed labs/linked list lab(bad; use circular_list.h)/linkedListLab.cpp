// I dont think that the operator overload functions are needed for this program.
// It works fine without it, and I cant see a time where the operator overload functions would be useful.
// I dont even know what the operator overloads are supposed to do?
// What are we iterating? What are we dereferencing? I have no idea. I dont think it works.

#include <iostream>
#include <stdexcept>

class linkedList { // initialize linked list class
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
		while(head != NULL && tail != NULL) pullHead();
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
			node = node->next;

			// if node doesn't exist throw and out of range error
			if (node==NULL) {
				std::string error("Offset out of range");
				throw std::range_error(std::string(error));
			}
		}

		// return the node at position: place
		return node->value;
	};

	void add(int val) { // add a value to the front of the linked list
		// declare new node to add in
		Node* newNode = new Node();
		
		// set value of new node to provided value
		newNode->value = val;

		// check if there is a node at beginning of linked list
		if (head!=NULL) head->setPrev(newNode); // set head previous node indicator to pointer of the new node

		// modify next and previous pointers to connect list
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;

		// if new node is the only element to be in the list, set tail of list to be position of new node
		if (length==0) tail = newNode;

		// incriment list length by one to account for new node added to list
		length+=1;
	}

	void push(int val) { // push a value to the end of the linked list
		// create new node that will be pushed to the linked list
		Node* newNode = new Node();

		// assign provided value to the new node
		newNode->value = val;

		// if a tail node exists, set the tail pointer to that of the new node
		if (tail != NULL) tail->setNext(newNode);

		// link the list to the new node
		newNode->prev = tail;
		newNode->next = NULL;
		tail = newNode;
		
		// if the list conatins no nodes set first node to the new node
		if (length == 0) head = newNode;
		
		// increment length 
		length+=1;
	}

	void insert(int index, int val) { // insert a value at a specific index

		// if index is at the end of the linked list, push the new value to the end of the list
		if (index == length-1) {
			this->push(val);
			return;
		}

		// create new node
		Node* newNode = new Node();

		// assign provided value to the new node
		newNode->value = val;

		// get nodes before and after inserted index
		Node* before = this->nodeAt(index);
		Node* after = before->next;

		// fix pointers to and from the inserted node
		// set pointers of inserted node to the nodes before and after it
		newNode->next = after;
		newNode->prev = before;
		// fix pointers of before and after to reference the inserted node
		before->next = newNode;
		after->prev = newNode;

		// increment lenght by one
		length += 1;
	}

	int pullHead() { // remove a value from the beginning and return it
		
		// throw out of range error if the list contains no values
		if (head==NULL || tail==NULL) {
			std::string error("Cannot pull from empty list");
			throw std::range_error(error);
		}
		
		// assign pointer for head to new variable
		Node* node = head;

		// assign value of first node to return value
		int ret = node->value;

		// change head to next node in list
		head = head->next;

		// if the list still contains a head node, clear reference for previous node from new head node
		if (head != NULL) head->prev = NULL;

		// delete old head
		delete node;

		// decrement length by one
		length-=1;

		// return value that was removed from the beginning of the list
		return ret;
	}

	int pullTail() { // remove a value from the end of the list and return it
		
		// if linked list conatins no nodes then throw error
		if (head == NULL || tail == NULL) {
			std::string error("Cannot modify empty list");
			throw std::range_error(error);
		}

		// assign pointer for tail to new node
		Node* node = tail;

		// assign value of tail to new variable for return
		int ret = node->value;

		// set node previous to old tail as new tail node
		tail = tail->prev;

		// if tail still exists, clear its next node pointer
		if (tail != NULL) {
			tail->next = NULL;
		}

		// delete old tail node
		delete node;

		// decrement length by one
		length-=1;

		// return value pulled from the end of the linked list
		return ret;
	}

	int remove(int index) { // remove node at index and return its value

		// if index is first of linked list use pull head function
		if (index == 0) {
			return this->pullHead();
		}

		// if index is last of linked list use pull tail function
		if (index == length-1) {
			return this->pullTail();
		}

		// assign pointer for node at index to temp variable
		Node* node = this->nodeAt(index);

		// assign value of node at index to variable for return
		int ret = node->value;

		// assign nodes before and after node at index
		Node* before = node->prev;
		Node* after = node->next;

		// mend linked list around removed node
		before->next = after;
		after->prev = before;

		// delete node that was 'removed'
		delete node;

		// decrement length of linked list by one
		length-=1;

		// return value of removed list
		return ret;
	}

private:
	Node* nodeAt(int place) { // return node at index
		// assign node in first place to variable to start loop
		Node* node = head;

		// loop through the linked list until it reaches index parameter
		for (int i = 0; i < place; ++i) {

			// set node to the pointer for the next node in the list
			node = node->next;

			// if the end of the list is reached before the index is reached, throw out of bounds error
			if (node==NULL) {
				std::string error("Offset out of range");
				throw std::range_error(std::string(error));
			}
		}

		// return pointer for the node at index
		return node;
	}

	// returns all values in the linked list as an array of integer values
	int returnAll() {
		
		Node* node = head;

		// initialize array with size of the linked list
		int valArr[this->size()];

		// loop to iterate through all values and put them into the array
		for (int i = 0; i < this->size(); ++i) {
			// set add the value of the current node to the array
			valArr[i] = node->value;

			// iterate to the next node
			node = node->next;
		}

		// return value array
		return *valArr;
	};

	// default initializers for iterator class
	Node* head; // first node in list
	Node* tail; // last node in list
	unsigned int length; // length of list
};

int main() {
	linkedList list;

	list.add(100); // list = [100]
	list.add(12); // list = [12, 100]
	list.push(15); // list = [12, 100, 15]
	list.insert(2,32); // list = [12, 100, 15, 32]
	list.remove(1); // list = [12, 15, 32]

	while (list.size()) {
		std::cout << list.pullHead() << std::endl; // prints elements one by one
	}

	return 0;
}