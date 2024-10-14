#include "./Coding.h"
#include "./ProcessFile.h"
#include <bitset>
#include <iostream>

Decoding::Decoding(ifstream& codesFile) {
	ProcessFileCodes processFileCodes;
	codes = processFileCodes.GetCodes(codesFile);
	originalText = processFileCodes.originalText;
}

char* Decoding::FindSymbol(string code) {
	char* result = nullptr;
	for (auto&& codeChar : (*codes)) {
		if (code == codeChar.code) {
			result = new char;
			(*result) = codeChar.key;
			break;
		}
	}
	return result;
}

void Decoding::ProcessLine(string line) {
	string code;
	for (int i = 0; i < line.size(); i++) {
		code += line[i];
		char* symbol = FindSymbol(code);
		if (symbol != nullptr) {
			result += *symbol;
			code.clear();
		}
	}
}

string Decoding::ProcessDecoding(ifstream& encodeFile) {
	string line;
	result.clear();
	while (getline(encodeFile, line)) {
		ProcessLine(line);
	}
	return result;
}

string Decoding::ProcessDecodingBy(ifstream& encodeFile) {
	string line;
	string str;
	int fakeBits = -1;
	bool flagNumberLine = false;
	while (getline(encodeFile, line)) {
		if (fakeBits == -1)
			fakeBits = line[0];
		if (flagNumberLine) {
			str += "1010";
			flagNumberLine = false;
		}
		for (int i = 0; i < line.length(); i++) {
			bitset<8> code(line[i]);
			str += code.to_string();
		}
		flagNumberLine = true;
	}
	str = str.substr(8 + fakeBits);
	result.clear();
	ProcessLine(str);
	return result;
}

Decoding::~Decoding() {
	delete codes;
}