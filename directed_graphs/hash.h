#ifndef __HASH_H_INCLUDED__
#define __HASH_H_INCLUDED__


/* hexidecimal ref:
		ALL hex numbers are preceded by '0x'
		This indicates it is a hex number to
		the C++ compiler.

	0: 0	4: 4	8: 8	C: 12
	1: 1	5: 5	9: 9	D: 13
	2: 2	6: 6	A: 10	E: 14
	3: 3	7: 7	B: 11	F: 15

	hex example: 0x18FE92
	dec convert: 1638034
*/

template <typename K, typename V>
class hash_node {
public:
	hash_node(const K& key, const V& value):
		key(key), value(value), next(NULL) {}

	inline K getKey() const { return key; }

	inline V getValue() const { return value; }
	inline void setValue(V value) { hash_node::value = value; }

	inline hash_node* getNext() const { return next; }
	inline void setNext(hash_node* next) { hash_node::next = next; }

private:
	// key-value pair of this node
	K key;
	V value;
	// next bucket with this same key
	hash_node* next;
};

template<typename K,
		 typename V,
		 typename F =KeyHash<K>> 

#endif