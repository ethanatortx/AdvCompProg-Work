#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iterator>
#include <functional>
#include "circular_list.h"
#include "hash\hashing_algorithms\sha-2\sha256\sha256.h"
/* hexidecimal ref:
		ALL hex numbers are preceded by '0x'
		This indicates it is a hex number to
		the C++ compiler.

	0: 0	4: 4	8: 8	C: 12
	1: 1	5: 5	9: 9	D: 13
	2: 2	6: 6	A: 10	E: 14
	3: 3	7: 7	B: 11	F: 15
*/

template <class T,
		  class Hash = std::hash<T>,
		  class Alloc = std::allocator<T> >
class hash_table {

	struct hash_node {
		hash_node(const T& x, const std::string& y = 0): data(x), hash(y) {}
		T data;
		std::string hash;
	};

	typedef List<typename 	hash_table<T>::hash_node> bucket;
	typedef typename std::vector<typename hash_table<T>::bucket> h_table;

	std::size_t bucket_constant;
	typename hash_table<T>::h_table table;

	void reallocate(const std::size_t&);

public:

	class iterator;
	class const_iterator;

	typedef typename hash_table<T>::bucket value_type;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;


	hash_table(const std::size_t& bucket_constant = 0): 
		bucket_constant(bucket_constant) {}
	hash_table(const hash_table&);

	inline bool empty() const { return this->table.empty(); }

	inline std::size_t size() const { return this->table.size(); }
	inline std::size_t max_size() const { return this->table.max_size(); }

	inline void set_bucket_const(const std::size_t& b_const) { this->bucket_constant = b_const; }
	inline void set_bucket_const(std::size_t&& b_const) { this->bucket_constant = b_const; }
	inline std::size_t get_bucket_const() const { return bucket_constant; }

	inline void clear() { this->table.clear(); }

	void resize(const std::size_t&);
	void resize(std::size_t&&);

	void add(const T&);
	void add(T&&);

	~hash_table();

	class iterator: public std::iterator<std::random_access_iterator_tag, typename hash_table<T>::bucket> {


	public:
		friend class hash_table;
		friend class const_iterator;

		typedef typename hash_table<T>::value_type value_type;
		typedef typename hash_table<T>::value_type& reference;
		typedef typename hash_table<T>::value_type* pointer;
	};

	class const_iterator: public std::iterator<std::random_access_iterator_tag, typename hash_table<T>::bucket> {


	public:
		friend class hash_table;
		friend class iterator;
		

	};
};

#endif