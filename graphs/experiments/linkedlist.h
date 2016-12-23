
#ifndef __LINKEDLIST_H_INCLUDED__
#define __LINKEDLIST_H_INCLUDED__

#include <iostream>
#include <string>


// item structure
/*
	Linked lists are made out of a chain of these items
*/
template <typename T>
struct item {
	// key of type T
	T key;
	// pointer to next item in list
	item *next;
};

// linked list class definition
/*
	Store items of type T in a linked list
*/
template <class T>
class linkedlist {

	// first term in the list
	item<T> *head;
	// length of the list as an integer value
	int length;

public:

	/*	
		Create head node
		set length to zero
	*/
	linkedlist();

	// 	Deallocate memory
	~linkedlist();

	/*
		Insert an item at the end of the list
	*/
	void insertItem(item<T>* newItem);

	/*
		Remove an item from the list
		Return TRUE if the operation was successful
	*/
	bool removeItem(T itemKey);

	/*
		Search for an item by its key
		Return a reference to the first match
		Return a NULL pointer if no match is found
	*/
	item<T>* getItem(T itemKey);

	// 	Print the list to the console window
	void printList();

	// 	Return the length of the linked list
	int getLength();
};

#endif