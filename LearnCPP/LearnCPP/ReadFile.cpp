#include "stdafx.h"
#include "ReadFile.h"


ReadFile::ReadFile()
{
}

ReadFile::ReadFile(std::string name) {
	inputFile.open(name);
}

void ReadFile::close() {
	if (inputFile)
		inputFile.close();
}

ReadFile::~ReadFile()
{
}
