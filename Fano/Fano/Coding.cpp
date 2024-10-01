#include "./Coding.h"
#include <iostream>
#include <fstream>
#include "./Stack.h"
#include "./ProcessFile.h"
#include <bitset>
#include <sstream>

Coding::Coding(ifstream& file) {
	ProcessFileOriginal processFile;
	this->enterArr = processFile.GetFreq(file);
	originalText = processFile.originalText;
	doneArr = new vector<CodeSymbol>;
	(*doneArr).resize((*enterArr).size());
	for (int i = 0; i < (*enterArr).size(); i++) {
		(*doneArr)[i].key = (*enterArr)[i].key;
	}
}

int Coding::Med(int startProcess, int endProcess) {
	float firstSum = 0;
	for (int i = startProcess; i <= endProcess - 1; i++) {
		firstSum += (*enterArr)[i].freq;
	}
	float secondSum = (*enterArr)[endProcess].freq;
	int med = endProcess;
	float d;
	do {
		d = abs(firstSum - secondSum);
		med -= 1;
		firstSum -= (*enterArr)[med].freq;
		secondSum += (*enterArr)[med].freq;
	} while (abs(firstSum - secondSum) <= d);
	return med;
}

void Coding::Fano() {
	Stack stack;
	stack.push(new FanoParametrs(0, enterArr->size() - 1));
	while (!stack.empty()){
		FanoParametrs* topStack = stack.pop();
		int med = Med(topStack->startProcess, topStack->endProcess);
		for (int i = topStack->startProcess; i <= topStack->endProcess; i++) {
			(*doneArr)[i].code += i > med ? "1" : "0";
		}
		if (med > topStack->startProcess)
			stack.push(new FanoParametrs(topStack->startProcess, med));
		if (topStack->endProcess > med + 1)
			stack.push(new FanoParametrs(med + 1, topStack->endProcess));
		delete topStack;
	}
	for (auto&& element : originalText) {
		result += FindCode(element);
	}
}

void Coding::PrintConsole() {
	for (auto&& element : (*doneArr)) {
		cout << element.key << ": " << element.code << endl;
	}
}

void Coding::PrintCodesInFile(ofstream& file) {
	for (auto&& symbol : (*doneArr)) {
		file << symbol.key << " " << symbol.code << endl;
	}
}

string Coding::FindCode(char key) {
	for (auto&& element : (*doneArr)) {
		if (key == element.key)
			return element.code;
	}
}

void Coding::PrintBynaryFile(ofstream& file) {
	int countAddSymbols = 8 - result.length() % 8;
	bitset<8> byte = countAddSymbols;
	result = byte.to_string<char, char_traits<char>, allocator<char> >() + string(countAddSymbols, '0') + result;
	stringstream sstream(result);
	string codeBites;
	for (int i = 0; i < result.length() / 8; i++) {
		bitset<8> byte;
		sstream >> byte;
		file << char(byte.to_ulong());
	}
}

void Coding::PrintInFile(ofstream& file) {
	file << result;
}