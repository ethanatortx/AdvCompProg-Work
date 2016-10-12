
/*  This program will sort a csv file by high to low or low to high
	and create a new file called "newcsv" which contains the newly
	sorted data. It should work for whatever you feed into it, but I
	only tested it with the given csv file.
		-Ethan Rivers, Advanced Computer Programming 02 */

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
		for (int inside = 0; inside < vec.size(); inside++) {
			string item = vec[inside];
			int strLength = item.length()-1;
			if (item[0] == '"') {
				while (!(item[strLength] == '"')) {
					item.append("," + vec[inside+1]);
					vec.erase(vec.begin()+inside+1);
					strLength = item.length()-1;
				}
				vec[inside] = item;
			}
		}
		data[outside] = vec;
	}
	
	file.close();
	
	return data;
}

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

vector<int> getCell(const vector<vector<string> > &vec, const string columnHeader) {
	
	int countCol = -1;
	vector<int> retVal(2,-1);
	
	vector<string> tempElement;
	
	for (int outside = 0; outside < vec.size(); outside++) {
		tempElement = vec[outside];
		for (int inside = 0; inside < tempElement.size(); inside++) {
			countCol++;
			string element(tempElement[inside]);

			if (element == columnHeader) {
				retVal[0] = outside;
				retVal[1] = countCol;
				return retVal;
			}
		}
		countCol = -1;
	}
	
	return retVal;
}

vector<vector<string> > sortBy(const string columnHeader, const vector<vector<string> > vec, const bool config) {
	
	vector<vector<string> > data = vec;
	vector<int> cell = getCell(data, columnHeader);
	
	vector<string> columnData;
	
	for (int outside = cell[0]; outside < data.size(); outside++) {
		columnData.push_back(data[outside][cell[1]]);
	}
	
	vector<double> columnReal;
	vector<double> sorted;
	vector<int> sortingIndex;
	
	for (int iter = 0; iter < columnData.size(); iter++) {
		string temp = columnData[iter];
		stringstream convert(temp);
		double currentPoint = 0;
		convert >> currentPoint;
		
		columnReal.push_back(currentPoint);
		
		int inside = 0;
		
		while (inside < sorted.size()) {
			if (config) {
				if (currentPoint <= sorted[inside]) {
					inside++;
				} else if (currentPoint > sorted[inside]) {
					break;
				}
			} else if (!config) {
				if (currentPoint >= sorted[inside]) {
					inside++;
				} else if (currentPoint < sorted[inside]) {
					break;
				}
			}
		}
		sorted.insert(sorted.begin()+inside, columnReal[iter]);
		sortingIndex.insert(sortingIndex.begin()+inside, iter);
	}
	
	vector<vector<string> > finalData;
	
	int dif = data.size() - sortingIndex.size();
	int sortIter = 0;
	int sortedPos;
	
	for (int finalIter = 0; finalIter < data.size(); finalIter++) {
		vector<string> tempVec = data[finalIter];
		if (finalIter > dif) {
			sortedPos = (sortingIndex[sortIter]+dif);
			finalData.push_back(data[sortedPos]);
			sortIter++;
		} else if (finalIter <= dif) {
			finalData.push_back(tempVec);
		}
	}	
	return finalData;
}

int main() {
	string temp1;
	string temp2;
	string temp3;
	string columnHeader;
	bool config = true;
	cout << "Input file name: ";
	cin >> temp1;
	const char* fileName = temp1.c_str();
	cout << "\nOutput file name: ";
	cin >> temp2;
	const char* outputFileName = temp2.c_str();
	cout << "\nColumn header to sort by: ";
	cin >> columnHeader;
	cout << "\nSort ascending or descending (ascending : y/descending : n): ";
	cin >> temp3;
	
	if (temp3 == "y") {
		config = true;
	} else if (temp3 == "n") {
		config = false;
	}

	vector<vector<string> > data = readInData(fileName);
	vector<vector<string> > sorted = sortBy(columnHeader,data,config);
	writeData(outputFileName, sorted);

	cout << "Sorted file " << fileName << " under column " << columnHeader << '\n';
	cout << "Output file under " << outputFileName << '\n';
	return 0;
}