#pragma once
#include "heap.h"
class ProcessGraph
{
public:
	static vector<pair<int, int>> GetEdge(vector<int> powers);
	static vector<int> GetPowers(vector<vector<int>> graph) {
		vector<int> result;
		for (int i = 0; i < graph.size(); i++) {
			int power = 0;
			for (int j = 0; j < graph[0].size(); j++) {
				if (i == j)
					continue;
				if (graph[i][j] == 1)
					power++;
			}
			result.push_back(power);
		}
		return result;
	}
};

