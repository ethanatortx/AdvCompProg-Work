#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

vector<string> splitString(const string &str, char delim) {
	stringstream ss(str);
	string item;
	vector<string> data;
	while (getline(ss,item,delim)) {
		data.push_back(item);
	}
	return data;
}


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

vector<vector<string> > readInData(const char* fileName) {
	string line;
	
	vector<vector<string> > data;
	vector<string> temp;
	
	ifstream file;
	file.open(fileName);
	
	while (!file.eof()) {
		if (getline(file,line,'\n')) {
			temp = splitString(line,',');
			data.push_back(temp);
		}
	}
	
	file.close();
	
	return data;
}

void readOutData(vector<vector<string> > vec) {
	for (int outside = 0; outside < vec.size(); outside++) {
		vector<string> tempElement = vec[outside];
		for (int inside = 0; inside < tempElement.size(); inside++) {
			cout << tempElement[inside] << endl;
		}
	}
}

int main() {
	cout << rowCount("inpfile.csv") << endl;
	vector<vector<string> > data = readInData("inpfile.csv");
	readOutData(data);
	return 0;
}