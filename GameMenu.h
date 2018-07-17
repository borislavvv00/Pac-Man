#pragma once
#ifndef GameMenu
#define GameMenu
#include "GameSetUp.h"

int choice = 0;//player choice
vector<int>FullLines;//line without spaces

void Write(string word, int startPosition, int line, int unnecessarySpaces)
{
	string spacesBeforeWord = "";
	while (word.length() < 40 - startPosition - unnecessarySpaces)
	{
		word += " ";
	}
	while (spacesBeforeWord.length() < startPosition - 2)
	{
		spacesBeforeWord += " ";
	}
	cout << spacesBeforeWord + word;
	FullLines.push_back(line);
}

void DrawMenu()
{
	FullLines.push_back(-1);
	int n = 0; //count FullLines elements

	for (int i = -1; i < 21; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (j == 0 || j == 39)
			{
				cout << "*";
			}
			else if (i == 1 && j == 1)
			{
				Write("Pac-Man", 16, i, 0);
				n++;
			}
			else if (i == 3 || i == -1 || i == 20)
			{
				cout << "*";
			}
			else if (i == 5 && j == 1)
			{
				Write("Menu", 18, i, 0);
				n++;
			}
			else if (i == 8 && j == 1)
			{
				Write("1.Start", 16, i, 0);
				n++;
			}
			else if (i == 10 && j == 1)
			{
				Write("2.Rules", 16, i, 0);
				n++;
			}
			else if (i == 12 && j == 1)
			{
				Write("3.Credits", 16, i, 0);
				n++;
			}
			else if (i != FullLines[n])
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	while (choice < 1 || choice > 3)
	{
		cout << "\n Choose option <1 - 3> : ";
		cin >> choice;
	}
	FullLines.erase(FullLines.begin(), FullLines.begin() + FullLines.size());
}

void Rules()
{
	FullLines.push_back(-1);
	int n = 0; //count FullLines elements

	for (int i = -1; i < 21; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (j == 0 || j == 39)
			{
				cout << "*";
			}
			else if (i == -1 || i == 20)
			{
				cout << "*";
			}
			else if (i == 1 && j == 1)
			{
				DrawCharecter(14, " C");
				Write(" - pac-man",2, i, 2);
				n++;
			}
			else if (i == 2 && j == 1)
			{
				DrawCharecter(1, " #");
				Write(" - wall", 2, i, 2);
				n++;
			}
			else if (i == 3 && j == 1)
			{
				DrawCharecter(15, " _");
				Write(" - door", 2, i, 2);
				n++;
			}
			else if (i == 4 && j == 1)
			{
				DrawCharecter(7, " .");
				Write(" - food", 2, i, 2);
				n++;
			}
			else if (i == 5 && j == 1)
			{
				DrawCharecter(15, " @");
				Write(" - cure", 2, i, 2);
				n++;
			}
			else if (i == 6 && j == 1)
			{
				DrawCharecter(9, " A");
				Write(" - ghost after cure was eaten", 2, i, 2);
				n++;
			}
			else if (i == 7 && j == 1)
			{
				DrawCharecter(8, " A");
				Write(" - eaten ghost by pac-man", 2, i, 2);
				n++;
			}
			else if (i == 8 && j == 1)
			{
				DrawCharecter(10, " A");
				cout << ", ";
				DrawCharecter(11, "A");
				cout << ", ";
				DrawCharecter(12, "A");
				cout << ", ";
				DrawCharecter(13, "A");
				Write(" - ghosts", 2, i, 11);
				n++;
			}
			else if (i == 9 && j == 1)
			{
				Write(" To move use : a - left, d - rigth,", 2, i, 0);
				n++;
			}
			else if (i == 10 && j == 1)
			{
				Write(" w - up, s - down.", 2, i, 0);
				n++;
			}
			else if (i == 15 && j == 1)
			{
				Write(" 0.Back to Manu", 2, i, 0);
				n++;
			}
			else if (i != FullLines[n])
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	while (choice != 0)
	{
		cout << "\n Choose option <0> : ";
		cin >> choice;
	}
	FullLines.erase(FullLines.begin(), FullLines.begin() + FullLines.size());
}

void Credits()
{
	FullLines.push_back(-1);
	int n = 0; //count FullLines elements

	for (int i = -1; i < 21; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (j == 0 || j == 39)
			{
				cout << "*";
			}
			else if (i == -1 || i == 20)
			{
				cout << "*";
			}
			else if (i == 10 && j == 1)
			{
				Write("Create by : ", 10, i, 20);
				DrawCharecter(4, "b");
				DrawCharecter(5, "o");
				DrawCharecter(6, "r");
				DrawCharecter(7, "i");
				DrawCharecter(8, "s");
				DrawCharecter(9, "l");
				DrawCharecter(10, "a");
				DrawCharecter(11, "v");
				DrawCharecter(12, "v");
				DrawCharecter(13, "v");
				Write("", 10, i, 30);
				n++;
			}
			else if (i != FullLines[n])
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	while (choice != 0)
	{
		cout << "\n Choose option <0> : ";
		cin >> choice;
	}
	FullLines.erase(FullLines.begin(), FullLines.begin() + FullLines.size());
}

#endif // !GameMenu
