
#include "hashtable.h"

//	Make hash table with specific length
template <class T>
hashtable<T>::hashtable(int&& tableLength) {
	if (tableLength <= 0) length = 13;
	else length = tableLength;
	
	array = { length, new linkedlist<T> };
}

/*
	Generate a hash with the provided key
	Return the index of the hash table that
		the key should be emplaced in
*/
template <class T>
int hashtable<T>::hash(T itemKey) {
	int val = sizeof(itemKey)/sizeof(*itemKey);
	return (val * (sizeof(itemKey)/sizeof(*itemKey))) % length;
}

//	Create an item from a key
template <class T>
void hashtable<T>::insertItem(T itemKey) {
	int index = hash(itemKey);
	item<T>* item = new (struct item<T>);
	item->value = itemKey;
	item->next = NULL;
	array[index]->insertItem(item);
};

/*
	Remove an item from a key
	Return TRUE if operation was succesful
*/
template <class T>
bool hashtable<T>::removeItem(T itemKey) {
	int index = hash(itemKey);
	return array[index]->removeItem(itemKey);
};

/*
	Get an item associated with a key
	Return a NULL pointer if no item
		with provided key is found
*/
template <class T>
item<T>* hashtable<T>::getItemByKey(T itemKey) {
	int index = hash(itemKey);
	return array[index]->getItem(itemKey);
};

//	Print the table to console
template <class T>
void hashtable<T>::printTable() {
	std::cout << "\nHash Table:\n";
	for (int i = 0; i < length; i++) {
		std::cout << i+1 << ": ";
		array[i]->printList();
	}
};

//	Print histogram of the table to console
template <class T>
void hashtable<T>::printHistogram() {
	std::cout << "\nHash Table:\n";
	std::cout << "Total Items: " << getNumberOfItems() << '\n';
	for (int i = 0; i < length; i++) {
		std::cout << i+1 << ": ";
		for (int x = 0; x < array[i]->getLength(); x++) {
			std::cout << " X";
		}
		std::cout << "\n";
	}
};

//	Return the length of the table
template <class T>
int hashtable<T>::getLength() {
	return length;
};

//	Return total element count of the table
template <class T>
int hashtable<T>::getNumberOfItems() {
	int count = 0;
	for (int i = 0; i < length; i++) {
		count += array[i]->getLength();
	}
	return count;
};

//	De-allocate memory of the table
template <class T>
hashtable<T>::~hashtable() {
	delete[] array;
};
