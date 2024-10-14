#include "./interface.h"
#include <iostream>
#include <fstream>

void Interface::ProcessDecoding() {
	ifstream codesFile("C:/Games/DM/CODES.txt", ifstream::binary);
	Decoding decoding(codesFile);
	codesFile.close();
	ifstream encodeFile("C:/Games/DM/CODED_FILE.txt");
	string result = decoding.ProcessDecoding(encodeFile);
	encodeFile.close();
	cout << result << endl;
}

void Interface::ProcessCoding() {
	ifstream file("C:/Games/DM/FANO_DEC.txt");
	Coding coding(file);
	file.close();
	coding.Fano();
	coding.PrintConsole();
	ofstream fileCodes("C:/Games/DM/CODES.txt", ofstream::binary);
	coding.PrintCodesInFile(fileCodes);
	fileCodes.close();
	ofstream fileCoded("C:/Games/DM/CODED_FILE.txt");
	coding.PrintInFile(fileCoded);
	fileCoded.close();
	ofstream fileCodedBy("C:/Games/DM/CODED_FILE_BY.txt");
	coding.PrintBynaryFile(fileCodedBy);
	fileCodedBy.close();
}

void Interface::ProcessDecodingBy() {
	ifstream codesFile("C:/Games/DM/CODES.txt", ifstream::binary);
	Decoding decoding(codesFile);
	codesFile.close();
	ifstream encodeFile1("C:/Games/DM/CODED_FILE.txt");
	string res = decoding.ProcessDecoding(encodeFile1);
	encodeFile1.close();
	ifstream encodeFile("C:/Games/DM/CODED_FILE_BY.txt", ifstream::binary);
	string result = decoding.ProcessDecodingBy(encodeFile);
	encodeFile.close();
	cout << res << endl;
}

void Interface::ProcessUser() {
	int point = -1;
	while (point != 4) {
		cout << "Enter number:\n1: coding file\n2: decoding file\n3: decoding bynary\n4: exit\n";
		cin >> point;
		switch (point) {
		case 1:
			ProcessCoding();
			break;
		case 2:
			ProcessDecoding();
			break;
		case 3:
			ProcessDecodingBy();
			break;
		case 4:
			break;
		default:
			cout << "uncorrect number\n";
			break;
		}
	}
}