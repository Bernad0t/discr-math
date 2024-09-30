#pragma once
#include <string>
#include <vector>
#include "./DictSymbol.h"

using namespace std;

class Coding {
public:
	void PrintConsole();
	void PrintInFile(ofstream& file);
	void PrintCodesInFile(ofstream& file);
	void PrintBynaryFile(ofstream& file);
	Coding(ifstream& file);
	void Fano();
private:
	string originalText;
	int Med(int startProcess, int endProcess);
	string FindCode(char key);
	vector<FreqSymbol>* enterArr;
	vector<CodeSymbol>* doneArr;
	string result;
};

class Encoding {
public:
	void PrintInFile();
	Encoding(ifstream& codesFile);
	string ProcessEncoding(ifstream& encodeFile);
	string ProcessEncodingBy(ifstream& encodeFile);
private:
	string originalText;
	char* FindSymbol(string code);
	void ProcessLine(string line);
	vector<CodeSymbol>* codes;
	string result;
};