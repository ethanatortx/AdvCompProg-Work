
#ifndef __HASHTABLE_H_INCLUDED__
#define __HASHTABLE_H_INCLUDED__

#include "linkedlist.h"

/*
	hash table class definition:
		this stores a fixed number of linked list for fast element access
*/
template <class T>
class hashtable {

	linkedlist<T>* array; // array of linked lists
	int length; // count of linked lists in hash table
	
	/*
		Generate a hash with the provided key
		Return the index of the hash table that
			the key should be emplaced in
	*/
	int hash(T itemKey);

public:

	//	Make hash table with specific length
	hashtable(int&& tableLength);

	//	Create an item from a key
	void insertItem(T itemKey);

	/*
		Remove an item from a key
		Return TRUE if operation was succesful
	*/
	bool removeItem(T itemKey);

	/*
		Get an item associated with a key
		Return a NULL pointer if no item
			with provided key is found
	*/
	item<T>* getItemByKey(T itemKey);

	//	Print the table to console
	void printTable();

	//	Print histogram of the table to console
	void printHistogram();

	//	Return the length of the table
	int getLength();

	//	Return total element count of the table
	int getNumberOfItems();

	//	De-allocate memory of the table
	~hashtable();
};



#endif

