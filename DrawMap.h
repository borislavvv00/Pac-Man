#pragma once
#ifndef DrawMap
#define DrawMap
#include "ClassMap.h"
#include "DrawCharecters.h"
#include "GameObjectGetCoordinates.h"
#include "PacManLogic.h"
#include "GhostsLogic.h"

void Map::EndGame()
{
	if (isPacManCatched == true)
	{
		cout << "GAME OVER" << endl;
	}
	else if (foodX.size() >= 100)
	{
		isGameOver = true;
		cout << "YOU WIN" << endl;
	}
}

void Map::BuildHorizontalBorders(int n)
{
	for (int i = - 1; i <= n; i++)
	{
		DrawCharecter(1, wallSign);
	}
	cout << endl;
}

void Map::BuildMap()
{
	BuildHorizontalBorders(width);
	
	int n = 0;//current wall
	int f = 0;//current food
	int c = 0;//current cure

	for (int i = 0; i <= heigth; i++)
	{
		for (int j = -1; j <= width; j++)
		{
			pacMan.DrawPacMan(i, j);
			ghosts.DrawGhosts(i, j);
			ghosts.StepOver(9, 19, isOpenDoorPrint);

			if (foodX.size() != 0)
			{
				pacMan.EatFood(f);
				ghosts.StepOver(foodX[f], foodY[f], isFoodPrint);
			}

			if (cureX.size() != 0)
			{
				pacMan.EatCure(c);
				ghosts.StepOver(cureX[c], cureY[c], isCurePrint);
			}

			if (i == wallX[n] && j == wallY[n])//draw walls
			{
				DrawCharecter(1, wallSign);
				n++;
			}
			else if (i == cureX[c] && j == cureY[c])//draw cure
			{
				if (isCurePrint == true)
				{
					DrawCharecter(15, cureSign);
				}
				if (c != cureX.size() - 1)
				{
					c++;
				}
			}
			else if (isFoodGetCoordinates == true && i == foodX[f] && j == foodY[f])//draw food
			{	
				if (isFoodPrint == true)
				{
					DrawCharecter(7, foodSign);
				}
				if (f != foodX.size() - 1)
				{
					f++;
				}
			}
			else if (i == 9 && j == 19)
			{
				if (isDoorPrint == true)
				{
					DrawCharecter(15, "_");
				}
				else if (isOpenDoorPrint == true && isDoorPrint == false)
				{
					DrawCharecter(0, " ");
				}
			}
			else if (j == -1 || j == width)//draw vertical borders
			{
				DrawCharecter(1, wallSign);
			}
			else if (isCharecterDraw == true)//prevent to be draw in the same position 2 symbols
			{
				isCharecterDraw = false;
				continue;
			}
			else
			{
				if (isFoodGetCoordinates == false)
				{
					FoodGetCoordinates(i, j);
				}
				cout << " ";
			}
		}
		cout << endl;
	}

	BuildHorizontalBorders(width);

	cout << "score = " << score << endl;
}

#endif // !DrawMap
