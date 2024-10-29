#include "./BipartiteGraph.h"
#include "./Interface.h"

int main() {
	/*vector<vector<int>> vec{
		{1, 1, 1, 0, 0},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 1, 1, 1, 1}
	};

	BipartiteGraph graph(move(vec));
	graph.GetMaxMatching();
	graph.GetMaxMatchingReq();*/
	Interface::processUser();
	return 0;
}