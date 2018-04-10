#pragma once
#include <fstream>
class ImplementFILE
{
public:
	ImplementFILE();
	ImplementFILE(std::ofstream);
	ImplementFILE(std::ifstream);
	ImplementFILE(std::fstream,int );
	void close();
	~ImplementFILE();
	
private:
	std::string fileName;
	std::ofstream outfile;
	std::ifstream inputfile;
	std::fstream file;
};

