#include "./Coding.h"
#include "./ProcessFile.h"
#include <fstream>
#include <iostream>
#include "./interface.h"

int main() {
	/*ifstream file("C:/Games/DM/FANO_DEC.txt");
	Coding coding(file);
	file.close();
	coding.Fano();
	coding.PrintConsole();
	coding.PrintInFile();*/
	/*ifstream codesFile("C:/Games/DM/CODES.txt");
	Encoding encoding(codesFile);
	codesFile.close();
	ifstream encodeFile("C:/Games/DM/CODED_FILE.txt");
	string result = encoding.ProcessEncoding(encodeFile);
	cout << result << endl;*/
	Interface interface;
	interface.ProcessUser();
	return 0;
}