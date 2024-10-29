#pragma once
#include <fstream>
#include <iostream>
#include "./ProcessFile.h"
#include "./BipartiteGraph.h"

using namespace std;

class Interface {
public:
	static void processUser() {
		ifstream file("C:/Games/DM/BipGraph/graph.txt");
		BipartiteGraph graph(ProcessFile::GetBipGraph(file));
		cout << "enter y for find matching and n for exite" << endl;
		char y;
		cin >> y;
		if (y == 'n')
			return;
		else if (y == 'y') {
			vector<int> matching = graph.GetMaxMatching();
			for (int i = 0; i < matching.size(); i++) {
				cout << "(" << i << ", " << matching[i] << ")" << endl;
			}
		}
	}
};