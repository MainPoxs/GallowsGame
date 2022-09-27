#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "Game.h"
#include "FileRead.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	FileRead f;               //������ �����
	f.getReadFile();         //� ����� ����� � ������� rand
	
	Game game;
	game.hideWord(f);       //�������� �����
	game.checkLetter(f);    //������ ����� ��� �����
	game.Statistics(f);    //���������� ����
	
	return 0;
}