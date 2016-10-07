#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int getRows(const char* fileName) {
	
	int rowCount (0);
	
	ifstream file;
	file.open(fileName);
	
	while (!file.eof()) {
		if (file.get() == '\n') rowCount++;
	}
	
	file.close();
	
	return rowCount;
}

int getCellWidth (const char* fileName) {
	
	int pointer = 0;
	int rowCount = (getRows(fileName));
	string line;
	string dataArray[rowCount];
	
	cout << rowCount << endl;
	
	cout << sizeof(dataArray)/sizeof(*dataArray)<<endl;
	ifstream file;
	file.open(fileName);
	
	while (!file.eof()) {
		getline(file,line,'\n');
		dataArray[pointer] = line;
		cout << line << endl;
		pointer++;
		//cout << pointer << endl;
	}
	
	cout << pointer << endl;
	
	return 0;
}

int readIn (const char* fileName) {
	string line;
	
	ifstream file;
	file.open(fileName);
	
	int cellWidth = getCellWidth(fileName);
	
	return 0;
}


int main() {
	readIn("inpfile.csv");
	return 0;
}