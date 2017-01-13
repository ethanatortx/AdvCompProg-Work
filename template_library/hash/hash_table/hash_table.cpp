#include "..\hash_table.h"


template <class T>
void hash_table<T>::reallocate(const std::size_t& new_bucket_count) 
{
	typename hash_table<T>::table new_tbl = new typename hash_table<T>::table();

}

template <class T>
hash_table<T>::hash_table(const hash_table<T>& H) 
{
	this->bucket_constant = H.bucket_constant;
	this->table = H.table;
}