#include "Interface.h"
#include <iostream>
#include "ProcessGraph.h"
#include <fstream>
#include "../bipartite_graph/ProcessFile.h"

using namespace std;

void Interface::processInputUser()
{
	int answer;
	do {
		cout << "1 - get power sqhema of graph\n2 - get edges with power sqhema\n0 - exit" << endl;
		cin >> answer;
		switch (answer)
		{
		case 2:
			try {
				createGraphWithPowerSqhema();
			}
			catch(string message) {
				cout << message << endl;
			}
			break;
		case 1:
			try {
				writeGraphLikePower();
			}
			catch (string message) {
				cout << message << endl;
			}
			break;
		default:
			break;
		}
	} while (answer != 0);
}

void Interface::writeGraphLikePower()
{
	ifstream file("C:/Games/DM/heap/graph.txt");
	ofstream filePowers("C:/Games/DM/heap/myPowers.txt");
	vector<vector<int>> matrix = ProcessFile::GetBipGraph(file);
	vector<int> powers = ProcessGraph::GetPowers(matrix);
	cout << "powers: ";
	for (int i : powers) {
		cout << i << " ";
		filePowers << i << " ";
	}
	cout << endl;
	file.close();
	filePowers.close();
}

void Interface::createGraphWithPowerSqhema()
{
	ifstream file("C:/Games/DM/heap/powersSqhema2.txt");
	ofstream fileGraph("C:/Games/DM/heap/myEdges.txt");
	string line;
	getline(file, line);
	int power;
	vector<int> powers;
	stringstream ss(line);
	while (ss >> power)
		powers.push_back(power);
	vector<pair<int, int>> edges = ProcessGraph::GetEdge(powers);
	cout << "edges:\n";
	for (pair<int, int> edge : edges) {
		cout << "(" << edge.first << ", " << edge.second << ")" << endl;
		fileGraph << "(" << edge.first << ", " << edge.second << ")" << endl;
	}
	file.close();
	fileGraph.close();
}
