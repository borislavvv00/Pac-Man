#pragma once
#ifndef GameSetUp
#define GameSetUp
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
#define NUMBER_OF_WALLS 354

using namespace std;

bool isCharecterDraw = false;//used for all characters in the game
bool isFoodGetCoordinates = false;
bool isGameOver = false;
bool isFoodPrint = true;
bool isCurePrint = true;
bool isDoorPrint = false;//door for ghost's house
bool isOpenDoorPrint = false;

bool isPacManTurnLeftAllow;
bool isPacManTurnRigthAllow;
bool isPacManTurnDownAllow;
bool isPacManTurnUpAllow;

bool isGhostTurnLeftAllow;
bool isGhostTurnRigthAllow;
bool isGhostTurnDownAllow;
bool isGhostTurnUpAllow;

bool isCureEaten = false;
bool isPacManCatched = false;

int countPacManMoves = 0;
int score = 0;
int countCureTime = 20;

enum class Direction
{
	stop, left, rigth, down, up
};
Direction pacManDirection;
Direction ghostsDirection[4];

void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

#endif // !SetUp
