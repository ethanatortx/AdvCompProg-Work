#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int getRows(const char* fileName) {
	
	int rowCount = 0;
	
	ifstream file;
	file.open(fileName);
	
	for (!file.eof()) {
		if (file.get() == '\n') rowCount++;
	}
	
	file.close();
	
	return rowCount;
}

int getCellWidth (const char* fileName) {
	
	int pointer = 0;
	string line;
	string dataArray[getRows(fileName)];
	
	ifstream file;
	file.open(fileName);
	
	
	
	while (!file.eof()) {
		getline(file,line,'\n');
		dataArray[pointer] = line;
		pointer++;
		
	}
	cout <<dataPoints<<endl;
	
	return 0;
}

int readIn (const char* fileName) {
	string line;
	
	ifstream file;
	file.open(fileName);
	
	int cellWidth = cellCountAtWidest(fileName);
	
	return 0;
}


main() {
	readIn("inpfile.csv");
	
}