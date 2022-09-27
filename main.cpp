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
	
	FileRead f;               //Чтение файла
	f.getReadFile();         //и выбор слова с помощью rand
	
	Game game;
	game.hideWord(f);       //Скрываем слово
	game.checkLetter(f);    //Вводим букву или слово
	game.Statistics(f);    //Статистика игры
	
	return 0;
}