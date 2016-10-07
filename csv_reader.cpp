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
	
	for (int outside = 0; outside < data.size(); outside++) {
		vector<string> vec = data[outside];
		for (int inside = 0; inside < data.size(); inside++) {
			string item = vec[inside];
			int strLength = sizeof(item)/sizeof(*item);
			if (item[0] == '"') {
				while (item[strLength] != '"') {
					strLength = sizeof(item)/sizeof(*item);
					item += vec[inside+1];
					vec.erase(inside+1);
				}
			}
		}
	}
	
	file.close();
	
	return data;
}

/*string searchFor(vector<vector<string> > vec, const char* keyword) {
	for (int outside = 0; outside < vec.size(); outside++) {
		vector<string> tempElement = vec[outside];
		for (int inside = 0; inside < tempElement.size(); inside++) {
			if (tempElement[inside] == keyword) return ('' + outside + ' ' + inside);
		}
	}
}*/

void writeData(const char* title, const vector<vector<string> > &data) {
	ofstream file;
	file.open(title);
	
	for (int outside = 0; outside < data.size(); outside++) {
		vector<string> tempElement = data[outside];
		for (int inside = 0; inside < tempElement.size(); inside++) {
			file << tempElement[inside] + ',';
		}
		file << '\n';
	}
}

int searchColumn(const vector<vector<string> > &vec, const char* columnHeader) {
	
	int count = -1;
	
	vector<string> tempElement;
	
	for (int outside = 0; outside < vec.size(); outside++) {
		tempElement = vec[outside];
		if (outside == 16) {
			for (int inside = 0; inside < tempElement.size(); inside++) {
				count++;
				string element(tempElement[inside]);
				if (element == columnHeader) return count;
			}
			count = -1;
		}
	}
	return count;
}

int main() {
	vector<vector<string> > data = readInData("inpfile.csv");
	writeData("newcsv.csv", data);
	//cout << searchFor(data,"2000-2005");
	cout << searchColumn(data,"2000-2005");
	return 0;
}