#include "./DictSymbol.h"

FreqSymbol::FreqSymbol(){}

FreqSymbol::FreqSymbol(char key, int freq) {
	this->key = key;
	this->freq = freq;
}

CodeSymbol::CodeSymbol() {}

CodeSymbol::CodeSymbol(char key, string code) {
	this->key = key;
	this->code = code;
}