#include <iostream>
#include <Windows.h>
#include <string>
#include "Game.h"

using namespace std;

int countError = 1; // количество ошибок
int attempt = 0; // количество попыток

string Game::hideWord(FileRead& other)
{		
	return line = other.getLine().assign(other.getLine().size()-1, '*');	
}

void Game::TitleGame()
{
	system("cls");
	cout << "\n\tИгра: Виселица";
	cout << "\n--------------------------------\n\n";
	cout << "\t" << line << endl;
	creatGallows();
}

string Game::getLetter()
{
	cout << R"("Тема "ЦВЕТЫ")";
	cout << "\nВведите букву или слово: ";
	getline(cin, letter_Word);
	attempt++;
	return lettersUse.append(letter_Word);	
}

void Game::checkLetter(FileRead& other)
{	
	TitleGame();
	
	if ((line.find('*') != string::npos) && (countError < 7))
	{		
		getLetter();

		for (int i = 0, pos = 0; i < other.getLine().size(); i++)
		{
			pos = other.getLine().find(letter_Word, i);
			if (pos != string::npos)
			{
				line.replace(pos, letter_Word.size(), letter_Word);
				i = pos;
			}
			else if (pos < 0 && i != 0)
			{
				checkLetter(other);
				return;
			}
			else
			{
				countError++;
				creatGallows();
			}
		}		
	}
	else if (line.find('*') == string::npos)
	{				
		cout << "\nВы выиграли!!!\n";
	}
	else
		cout << "\nВы проиграли!!!\n";
}

void Game::creatGallows()
{
	string Symb;
	switch (countError)
	{
	case 1:
		Symb = { "\t\t  ______\n"
		      "\t\t |      |\n"
		      "\t\t        |\n"
		      "\t\t        |\n"
		      "\t\t        |\n"
		      "\t\t        |\n"
		      "\t\t        |\n"
		      "\t\t _______|__\n" };
		cout << Symb;
		break;
	case 2:
		Symb = { "\t\t  ______\n"
			  "\t\t |      |\n"
			  "\t\t O      |\n"
			  "\t\t        |\n"
			  "\t\t        |\n"
			  "\t\t        |\n"
			  "\t\t        |\n"
			  "\t\t _______|__\n" };
		cout << Symb;
		break;
	case 3:
		Symb = { "\t\t  ______\n"
		      "\t\t |      |\n"
		      "\t\t O      |\n"
		      "\t\t |      |\n"
		      "\t\t |      |\n"
		      "\t\t        |\n"
		      "\t\t        |\n"
		      "\t\t _______|__\n" };
		cout << Symb;
		break;
	case 4:
		Symb = { "\t\t  ______\n"
			  "\t\t |      |\n"
			  "\t\t O      |\n"
			  "\t\t\\|      |\n"
			  "\t\t |      |\n"
			  "\t\t        |\n"
			  "\t\t        |\n"
			  "\t\t _______|__\n" };
		cout << Symb;
		break;
	case 5:
		Symb = { "\t\t  ______\n"
			  "\t\t |      |\n"
			  "\t\t O      |\n"
			  "\t\t\\|/     |\n"
			  "\t\t |      |\n"
			  "\t\t        |\n"
			  "\t\t        |\n"
			  "\t\t _______|__\n" };
		cout << Symb;
		break;	
	case 6:
		Symb = { "\t\t  ______\n"
			  "\t\t |      |\n"
			  "\t\t O      |\n"
			  "\t\t\\|/     |\n"
			  "\t\t |      |\n"
			  "\t\t/       |\n"
			  "\t\t        |\n"
			  "\t\t _______|__\n" };		
		cout << Symb;
		break;
	case 7:
		Symb = { "\t\t  ______\n"
		      "\t\t |      |\n"
	          "\t\t O      |\n"
		      "\t\t\\|/     |\n"
		      "\t\t |      |\n"
		      "\t\t/ \\     |\n"
	          "\t\t        |\n"
		      "\t\t _______|__\n" };		
		cout << Symb;
		break;
	default:		
		cout << endl;
		break;
	}
}

void Game::Statistics(FileRead& other)const
{	
	cout << "\n--------------------------------\n";
	cout << "Статистика игры:\n\n";	
	cout << " -количество попыток: ";
	cout << attempt;
	cout << "\n -искомое слово: ";
	cout << other.getLine();
	cout << "\n -использованные буквы: ";
	cout << lettersUse;
	cout << "\n\n--------------------------------\n\n";
}


