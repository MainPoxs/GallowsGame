#include "FileRead.h"
#include <cstdlib>
#include <ctime>

void FileRead::getReadFile()
{
	srand(unsigned(time(NULL)));

	cout << "¬ведите путь до файла: "; //ListWords.txt
	getline(cin, line);
	
	fileWords.open(line, ios::in);
	if (fileWords.is_open())
		while (getline(fileWords, line))
			arr.push_back(line);
	else
		getReadFile();
	
	fileWords.close();

	int i = rand() % arr.size();
	line = arr[i];
}