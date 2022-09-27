#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileRead
{
public:
	void getReadFile();	
	string getLine()const { return line; }
private:
	fstream fileWords;
	string line;
	vector<string> arr;
};
