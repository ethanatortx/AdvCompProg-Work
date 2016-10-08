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
					strLength = item.length()-1;
					item.append("," + vec[inside+1]);
					//cout << item[strLength] << " " << strLength << endl;
					vec.erase(vec.begin()+inside+1);
				}
				//cout << item;
				vec[inside] = item;
			}
		}
		data[outside] = vec;
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
		
		//cout << currentPoint << '\n';
		
		columnReal.push_back(currentPoint);
		
		int inside = 0;
		
		while (inside < sorted.size()) {
			if (currentPoint <= sorted[inside]) {
				inside++;
			} else if (currentPoint > sorted[inside]) {
				break;
			}
		}
		sorted.insert(sorted.begin()+inside, columnReal[iter]);
		sortingIndex.insert(sortingIndex.begin()+inside, iter);
		
		
	}
	
	/*for (int rtg = 0; rtg < sorted.size(); rtg++) {
		cout << sorted[rtg] << " " << sortingIndex[rtg] << '\n';
	}*/
	
	vector<vector<string> > finalData;
	
	int dif = data.size() - sortingIndex.size();
	
	for (int finalIter = 0; finalIter < data.size(); finalIter++) {
		int discrepancy = finalIter - dif;
		int elementIndex = sortingIndex[discrepancy];
		if (finalIter > dif) {
			finalData.push_back(data[elementIndex]);
			
		} else {
			finalData.push_back(data[finalIter]);
			//cout << '\n';
		}
		/*for (int rtg = 0; rtg < data[finalIter].size(); rtg++) {
			cout << finalData[finalIter][rtg] << " ";
		}
		cout << '\n' << elementIndex << " " << discrepancy << '\n';*/
	}
	cout << dif;
	
	/*for (int rtg = 0; rtg < finalData.size(); rtg++) {
		vector<string> tempElementLul = finalData[rtg];
		for (int rtg2; rtg2 < tempElementLul.size(); rtg2++) {
			cout << tempElementLul[rtg2] << ' ';
		}
		cout << '\n';
	}*/
	
	/*for (int rtg = 0; rtg < data.size(); rtg++) {
		vector<string> tempElementLul = data[rtg];
		for (int rtg2; rtg2 < tempElementLul.size(); rtg2++) {
			cout << tempElementLul[rtg2] << ' ';
		}
		cout << '\n';
	}*/
	
	return finalData;
}

int main() {
	vector<vector<string> > data = readInData("inpfile.csv");
	vector<vector<string> > sorted = sortBy("\"2000-2005\"",data,true);
	writeData("newcsv.csv", sorted);
	//cout << searchFor(data,"2000-2005");
	vector<int> cell = getCell(data,"\"2000-2005\"");
	vector<vector<string> > vec = sortBy("\"2000-2005\"", data, true);
	return 0;
}