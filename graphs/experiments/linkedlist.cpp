
#include "linkedlist.h"

/*	
	Create head node
	set length to zero
*/
template <class T>
linkedlist<T>::linkedlist() {
	head = new item<T>;
	head->next = NULL;
	length = 0;
};

// 	Deallocate memory
template <class T>
linkedlist<T>::~linkedlist() {
	item<T>* p = head;
	item<T>* q = head;
	while (q) {
		p = q;
		q = p->next;
		if (q) delete p;
	}
}

/*
	Insert an item at the end of the list
*/
template <class T>
void linkedlist<T>::insertItem(item<T>* newItem) {
	if (!head->next) {
		head->next = newItem;
		length++;
		return;
	}

	item<T>* p = head;
	item<T>* q = head;

	while (q) {
		p = q;
		q = p->next;
	}

	p->next = newItem;
	newItem->next = NULL;
	length++;
};

/*
	Remove an item from the list
	Return TRUE if the operation was successful
*/
template <class T>
bool linkedlist<T>::removeItem(T itemKey) {

	if (!head->next) return false;

	item<T>* p = head;
	item<T>* q = head;

	while (q) {
		if (q->key == itemKey) {
			p->next = q->next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p->next;
	}

	return false;
};

/*
	Search for an item by its key
	Return a reference to the first match
	Return a NULL pointer if no match is found
*/
template <class T>
item<T>* linkedlist<T>::getItem(T itemKey) {
	item<T>* p = head;
	item<T>* q = head;

	while (q) {
		p = q;
		if ((p!=head) && (p->key == itemKey)) {
			return p;
		}
		q = p->next;
	}

	return NULL;
}

// 	Print the list to the console window
template <class T>
void linkedlist<T>::printList() {
	if (length==0) {
		std::cout<<"\n{ }\n";
		return;
	}

	item<T>* p = head;
	item<T>* q = head;

	std::cout << "\n{ ";

	while (q) {
		if (p!=head) {
			std::cout << p->key;
			if (p->next) std::cout << ", ";
			else std::cout << " ";
		}
		q=p->next;
	}

	std::cout << "}\n";
}

// 	Return the length of the linked list
template <class T>
int linkedlist<T>::getLength() {
	return length;
}