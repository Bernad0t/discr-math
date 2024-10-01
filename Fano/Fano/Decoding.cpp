#include "./Coding.h"
#include "./ProcessFile.h"
#include <bitset>

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
	string res;
	int fakeBits = -1;
	while (getline(encodeFile, line)) {
		if (fakeBits == -1)
			fakeBits = line[0];
		for (int i = 0; i < line.length(); i++) {
			bitset<8> code(line[i]);
			str += code.to_string();
		}
	}
	str = str.substr(8 + fakeBits);
	result.clear();
	ProcessLine(str);
	return result;
}