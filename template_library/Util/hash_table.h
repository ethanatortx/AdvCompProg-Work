#ifndef HASH_H
#define HASH_H

#include "circular_list.h"

/* hexidecimal ref:
		ALL hex numbers are preceded by '0x'
		This indicates it is a hex number to
		the C++ compiler.

	0: 0	4: 4	8: 8	C: 12
	1: 1	5: 5	9: 9	D: 13
	2: 2	6: 6	A: 10	E: 14
	3: 3	7: 7	B: 11	F: 15
*/

template <class T>
class hash_table {

	struct hash_node {
		T data;
		std::string hash;
	};

	std::size_t bucket_constant;
	typedef List<hash_node> bucket;

public:

	hash_table(const std::size_t& size = 0, const std::size_t& bucket_const = 0): bucket_const(bucket_const) 
	{
		table[size];
	}
	hash_table(const hash_table&);

	bool empty() const;

	std::size_t size() const;
	std::size_t max_size() const;

	void resize(const std::size_t&);
	void resize(std::size_t&&);

	void add(const T&);
	void add(T&&);

	void clear();
};

#endif