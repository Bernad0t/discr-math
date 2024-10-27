#pragma once
#include <vector>
#include <stack>

using namespace std;

class OneStep {
public:
	OneStep(int v1, vector<int>&& v2, bool* result) : result(result), v1(v1), v2_checked(move(v2)) {}
	~OneStep() {
		if (result != nullptr)
			delete result;
	}
	bool* result;
	int v1;
	vector<int> v2_checked;
};

class BipartiteGraph
{
	vector<bool> visited;
	vector<int> matching;
	vector<vector<int>> graph;	// (n, m) : n from v1, m from v2, n <= m
	vector<vector<int>> v2_for_v1_i;
	void find_v2_for_v1_i();
	void SearchAug(int v1);
	bool dfs(int v);
public:
	BipartiteGraph(vector<vector<int>>&& graph): graph(move(graph)){
		matching.resize(this->graph[0].size(), -1);
		visited.resize(this->graph.size(), false);
		v2_for_v1_i.resize(this->graph.size());
		find_v2_for_v1_i();
	}
	vector<int> GetMaxMatching();
	vector<int> GetMaxMatchingReq();
};

