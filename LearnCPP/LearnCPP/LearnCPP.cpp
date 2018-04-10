// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void test_outputFile( string name) {
	ofstream outfile;
	outfile.open(name);
	

	if (outfile.is_open()) {
		outfile << "This is the example to test output file!" << endl;
		outfile.close();
	}
}

void test_inputFile(string name) {
	ifstream inputfile;
	inputfile.open(name);
	if (!inputfile.is_open())
		return;

	while (inputfile) {
		string line;
		//getline(inputfile, line);
		inputfile >> line;
		inputfile >> ws;
		if (!inputfile)
			break;
		cout << line << endl;
	}
}

#pragma pack(push, 1)

struct Person
{
	char name[50]; //
	int age; //4bytes
	double weight;//8bytes
};
#pragma pack(pop)

int main()
{
	//test_outputFile("test");
	//test_inputFile("test");

	Person someone = { "Jacal", 16, 52.2 };

	///Write binary file
	string fileName = "test.bin";
	ofstream outfile;
	//need to specify the format of data
	//when using fstream, also need to specify ios::out|ios::binary

	outfile.open(fileName, ios::binary);
	if (outfile.is_open())
	{
		//casting??
		outfile.write(reinterpret_cast<char *>(&someone), sizeof(Person) );
		outfile.close();
	}
	else {
		cout << "can't create the file :" + fileName << endl;
	}
	
	Person someelse = {};
	///read binary file
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someelse), sizeof(Person));
		inputFile.close();
	} 	else {
		cout << "can't read the file :" + fileName << endl;
	}

	cout << someelse.name<<" "<<someelse.age<<" "<<someelse.weight << endl;
    return 0;
}

