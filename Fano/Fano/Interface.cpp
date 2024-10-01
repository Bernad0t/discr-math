#include "./interface.h"
#include <iostream>
#include <fstream>

void Interface::ProcessEncoding() {
	ifstream codesFile("C:/Games/DM/CODES.txt");
	Decoding encoding(codesFile);
	codesFile.close();
	ifstream encodeFile("C:/Games/DM/CODED_FILE.txt");
	string result = encoding.ProcessDecoding(encodeFile);
	encodeFile.close();
	cout << result << endl;
}

void Interface::ProcessCoding() {
	ifstream file("C:/Games/DM/FANO_DEC.txt");
	Coding coding(file);
	file.close();
	coding.Fano();
	coding.PrintConsole();
	ofstream fileCodes("C:/Games/DM/CODES.txt");
	coding.PrintCodesInFile(fileCodes);
	fileCodes.close();
	ofstream fileCoded("C:/Games/DM/CODED_FILE.txt");
	coding.PrintInFile(fileCoded);
	fileCoded.close();
	ofstream fileCodedBy("C:/Games/DM/CODED_FILE_BY.txt");
	coding.PrintBynaryFile(fileCodedBy);
	fileCodedBy.close();
}

void Interface::ProcessEncodingBy() {
	ifstream codesFile("C:/Games/DM/CODES.txt");
	Decoding encoding(codesFile);
	codesFile.close();
	ifstream encodeFile("C:/Games/DM/CODED_FILE_BY.txt");
	string result = encoding.ProcessDecodingBy(encodeFile);
	encodeFile.close();
	cout << result << endl;
}

void Interface::ProcessUser() {
	int point = -1;
	while (point != 4) {
		cout << "Enter number:\n1: coding file\n2: encoding file\n3: encoding bynary\n4: exit\n";
		cin >> point;
		switch (point) {
		case 1:
			ProcessCoding();
			break;
		case 2:
			ProcessEncoding();
			break;
		case 3:
			ProcessEncodingBy();
			break;
		case 4:
			break;
		default:
			cout << "uncorrect number\n";
			break;
		}
	}
}