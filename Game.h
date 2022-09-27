#pragma once
#include <string>
#include "FileRead.h"

using namespace std;

class Game
{
public:
	string hideWord(FileRead& other);
	void TitleGame();
	string getLetter();
	void checkLetter(FileRead& other);
	void creatGallows();	
	void Statistics(FileRead& other)const;
private:
	string line;		
	string letter_Word;
	string lettersUse;	
};
