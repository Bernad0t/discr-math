#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ProcessFile {
public:
	static vector<vector<int>> GetMatrix(ifstream& file) {
		string line;
		vector<vector<int>> res;
		int count = 0;
		while (getline(file, line)) {
			stringstream ss(line);
			res.push_back(vector<int>());
			int i;
			while (ss >> i)
				res[count].push_back(i);
			count++;
		}
		return res;
	}
};