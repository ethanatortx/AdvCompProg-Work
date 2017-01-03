// linked LinkedList driver program

#include "LinkedList.h"
#include <algorithm>
#include <numeric>
#include <iostream>

int main()
{
	LinkedList<int> x;
	x.push_front(3);
	x.push_front(4);
	x.push_front(9);
	std::copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout,"\n"));
	LinkedList<int>::iterator it = std::find(x.begin(),x.end(),4);
	if (it != x.end())
		std::cout << *it << std::endl;

	x.insert (it,11);
	std::cout << "The LinkedList is: " << std::endl;
	std::copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout,"\n"));

	int sum = std::accumulate ( x.begin(),x.end(),0);
	int sumsq = std::inner_product( x.begin(),x.end(),x.begin(),0);

	std::cout << "sum " << sum << std::endl;
	std::cout << "sum sq " << sumsq << std::endl;


	LinkedList<int> y = x;
	std::cout << "Copying... " << std::endl;
	std::copy(y.begin(), y.end(), std::ostream_iterator<int>(std::cout,"\n"));

	std::cout << "Rotating 11 to front ... " << std::endl;
	y.rotate(std::find(y.begin(),y.end(),11));
	std::copy(y.begin(), y.end(), std::ostream_iterator<int>(std::cout,"\n"));

}