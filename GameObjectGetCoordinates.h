#pragma once
#ifndef GameObjectGetCoordinates
#define GameObjectGetCoordinates
#include "ClassMap.h"

void Map::WallsGetCoordinates()
{
	ifstream getCoordinates;
	getCoordinates.open("WallsCoordinates.txt");

	for (int i = 0; i < NUMBER_OF_WALLS; i++)
	{
		getCoordinates >> wallX[i];
	}

	for (int i = 0; i < NUMBER_OF_WALLS; i++)
	{
		getCoordinates >> wallY[i];
	}

	getCoordinates.close();
}

void Map::FoodGetCoordinates(int i, int j)
{
	if (i == heigth && j == width - 1)
	{
		isFoodGetCoordinates = true;
	}
	if (i != 10 || j != 19)
	{
		foodX.push_back(i);
		foodY.push_back(j);
	}
}

void Map::CureGetCoordinates()
{
	cureX.push_back(0);
	cureX.push_back(0);
	cureX.push_back(20);
	cureX.push_back(20);
	cureY.push_back(1);
	cureY.push_back(38);
	cureY.push_back(1);
	cureY.push_back(38);
}

#endif // !GameObjectGetCoordinates
