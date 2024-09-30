#pragma once
#include <string>

using namespace std;


class FreqSymbol {
public:
	FreqSymbol();
	FreqSymbol(char key, int freq);
	char key;
	int freq;
};

class CodeSymbol {
public:
	CodeSymbol();
	CodeSymbol(char key, string code);
	char key;
	string code;
};