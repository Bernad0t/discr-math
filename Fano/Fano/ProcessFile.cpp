#include "./ProcessFile.h"
#include <iostream>
#include <string>
#include <algorithm>

bool compare(const FreqSymbol left, const FreqSymbol right)
{
	return left.freq > right.freq;
}

ProcessFileOriginal::ProcessFileOriginal() {
	frequency = new vector<FreqSymbol>;
	(*frequency).resize(256);
	for (int i = 0; i < 256; i++) {
		(*frequency)[i].freq = 0;
	}
}

void ProcessFileOriginal::SortFreq() {
	sort((*frequency).begin(), (*frequency).end(), compare);
	int count = 0;
	while ((*frequency)[count].freq > 0) {
		count++;
	}
	(*frequency).resize(count);
}

vector<FreqSymbol>* ProcessFileOriginal::GetFreq(ifstream& file) {
	string line;
	while (getline(file, line)) {
		originalText += line;
		for (int i = 0; i < line.length(); i++) {
			(*frequency)[(int)line[i]].key = line[i];
			(*frequency)[(int)line[i]].freq += 1;
		}
	}
	SortFreq();
	return frequency;
}


ProcessFileCodes::ProcessFileCodes() {
	codes = new vector<CodeSymbol>;
}

vector<CodeSymbol>* ProcessFileCodes::GetCodes(ifstream& file) {
	string line;
	while (getline(file, line)) {
		string code;
		originalText += line;
		for (int i = 2; i < line.length(); i++) {
			code += line[i];
		}
		codes->push_back(CodeSymbol(line[0], code));
	}
	return codes;
}