#pragma once
#include <fstream>
class ReadFile
{
public:
	ReadFile();
	ReadFile( std::string );
	
	void close();
	~ReadFile();
private:
	std::ifstream inputFile;
};

