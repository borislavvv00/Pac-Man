#pragma once
#ifndef ClassMap
#define ClassMap
#include "GameSetUp.h"

class Map
{
private:
	int width, heigth;
	int wallX[NUMBER_OF_WALLS], wallY[NUMBER_OF_WALLS];
	vector<int>foodX;
	vector<int>foodY;
	vector<int>cureX;
	vector<int>cureY;
	string foodSign, wallSign, cureSign;
	void BuildHorizontalBorders(int n);
	void FoodGetCoordinates(int i, int j);
public:
	Map()
	{
		width = 40;
		heigth = 20;
		wallSign = "#";
		foodSign = ".";
		cureSign = "@";
	}
	void BuildMap();
	void WallsGetCoordinates();
	void CureGetCoordinates();
	void EndGame();
	friend class PacMan;
	friend class Ghosts;
};
Map aMap;

#endif // !ClassMap
