#include "Interface.h"
#include <iostream>
#include <fstream>
#include "./GetMatrixFromFile.h"
#include "./Gamilton.h"

using namespace std;

void Interface::processInputUser()
{
	int answer;
	do {
		cout << "1 - get cycle\n0 - exit" << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
			processCycle();
			break;
		default:
			break;
		}
	} while (answer != 0);
}

void Interface::processCycle()
{
	ifstream file("C:/Games/DM/gamilton/gr4.txt");
	vector<vector<int>> matrix = ProcessFile::GetMatrix(file);
	try {
		vector<int> res = Gamilton::getCycle(matrix);
		for (int i : res)
			cout << i << " ";
		cout << res[0] << endl << endl;
	}
	catch (string message) {
		cout << message << endl << endl;
	}
}
