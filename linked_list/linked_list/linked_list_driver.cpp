
#include "..\linked_list.h"

int main() 
{
	linked_list<int> list;

	list.push_back(20);
	list.push_back(10);

	list.print();

	return 0;
};