//Classes

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class SALESREC
{
	public:
		char     date[10];
		char     region[10];
		char     rep[10];
		char     item[10];
		int      units;
		float    unitCost;
		float    Total;
};

// arguments will be an array of pointers and a count
void simpleSortTotal( SALESREC* arr[] , int c)
{
	for (int i=0; i < c; i++) {
		for (int j=i; j < c; j++) {
			if (arr[i]->Total > arr[j]-> Total)//total pointed at by i < total pointed at by j)=
			{
				//swap pointer to record I with pointer to record j
				SALESREC * pointerForI = arr[i];
				arr[i] = arr[j];
				arr[j] = pointerForI;
			}
		}
	}
} 

int main()
{
	ifstream infile;
	int i=0;
	char cNum[10] ;
	SALESREC salesArr[40];
	int salesArrayCount;
	SALESREC* s[40];

		infile.open ("SalesDataP2.csv", ifstream::in);
		if (infile.is_open())
		{
		int   c=0;
		while (infile.good())
		{
			infile.getline(salesArr[c].date, 256, ',');
			infile.getline(salesArr[c].region, 256, ',');
			infile.getline(salesArr[c].rep, 256, ',');
			infile.getline(salesArr[c].item, 256, ',');
			infile.getline(cNum, 256, ',');
			salesArr[c].units = atoi(cNum);
			infile.getline(cNum, 256);
			salesArr[c].unitCost = atof(cNum);
			salesArr[c].Total = 

			i++ ;
			c++;
		}
		salesArrayCount = c-1;
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	
	// Initialize the sort array pointers
	for (int i=0; i < salesArrayCount; i++)
		s[i] = &salesArr[i]; //Trying to insert the values from Sales arr into the pointer array
	
	simpleSortTotal(s, salesArrayCount);
	  
	for (int i=0; i < salesArrayCount; i++)
		cout << "Record: " << s[i]->date <<", " << s[i]->region << ", " << s[i]->rep << ", " << s[i]->item << ", " << s[i]->units << ", " << s[i]->unitCost << ", " << s[i]->Total << endl;
  
}