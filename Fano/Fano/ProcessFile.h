#pragma once
#include <vector>
#include <fstream>
#include "./DictSymbol.h"

using namespace std;


class ProcessFileOriginal {
	vector<FreqSymbol>* frequency;
	void SortFreq(); //  по убыванию
public:
	string originalText;
	ProcessFileOriginal();
	vector<FreqSymbol>* GetFreq(ifstream& file);
};

class ProcessFileCodes {
	vector<CodeSymbol>* codes;
public:
	string originalText;
	ProcessFileCodes();
	vector<CodeSymbol>* GetCodes(ifstream& file);
};