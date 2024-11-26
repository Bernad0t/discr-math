#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ProcessFile {
public:
	static vector<vector<int>> GetBipGraph(ifstream& file) {
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
		if (res.size() > res[0].size()) {
			vector<vector<int>> new_res;
			new_res.resize(res[0].size());
			for (int i = 0; i < res[0].size(); i++) {
				for (int j = 0; j < res.size(); j++) {
					new_res[i].push_back(res[j][i]);
				}
			}
			res = new_res;
		}
		return res;
	}
};