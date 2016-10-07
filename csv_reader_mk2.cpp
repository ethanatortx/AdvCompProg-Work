#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int rowCount (const char* fileName) {
	int count = 0;
	
	ifstream file;
	file.open(fileName);
	
	while (!file.eof()) {
		if (file.get() == '\n') count++;
	}
	
	file.close();
	
	return count;
}

int getCellWidth(const char* fileName) {
	int count = 0;
	
	ifstream file;
	file.open(fileName);
	
	while (getline(file,line,'\n')) {
		
	}
}

int main() {
	cout << rowCount("inpfile.csv") << endl;
	return 0;
}