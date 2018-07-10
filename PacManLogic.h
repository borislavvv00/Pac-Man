#pragma once
#ifndef PacManLogic
#define PacManLogic
#include "GameMovement.h"

void PacMan::TouchGhost()
{
	for (int n = 0; n < 4; n++)
	{
		if (ghosts.x[n] == pacMan.x && ghosts.y[n] == pacMan.y)
		{
			if (isCureEaten == true)
			{
				ghosts.isGhostEaten[n] = true;
				ghosts.isGhostRunFromPacMan[n] = false;
				ghosts.isGhostGoToHouse[n] = true;
				ghosts.color[n] = 8;
				score += 100;
			}
			else
			{
				isGameOver = true;
				isPacManCatched = true;
			}
		}
	}
}

void PacMan::EatFood(int &f)
{
	if (x == aMap.foodX[f] && y == aMap.foodY[f])
	{
		aMap.foodX.erase(aMap.foodX.begin() + f);
		aMap.foodY.erase(aMap.foodY.begin() + f);
		if (f == aMap.foodX.size())
		{
			f = 0;
		}
		score++;
	}
}

void PacMan::EatCure(int &c)
{
	if (x == aMap.cureX[c] && y == aMap.cureY[c])
	{
		aMap.cureX.erase(aMap.cureX.begin() + c);
		aMap.cureY.erase(aMap.cureY.begin() + c);
		if (c == aMap.cureX.size())
		{
			c = 0;
		}
		isCureEaten = true;
		for (int n = 0; n < 4; n++)
		{
			ghosts.isGhostRunFromPacMan[n] = true;
			ghosts.isGhostChasePacMan[n] = false;
			ghosts.isGhostGoOutFromHouse[n] = false;
			ghosts.isGhostGoToHouse[n] = false;
		}
	}
}

void PacMan::CheckMove()
{
	for (int n = 0; n < NUMBER_OF_WALLS; n++)
	{
		ReachWall(aMap.wallX[n], aMap.wallY[n]);
	}
	for (int n = 0; n < aMap.width; n++)
	{
		ReachWall(-1, n);
		ReachWall(aMap.heigth + 1, n);
	}
	for (int n = 0; n < aMap.heigth; n++)
	{
		ReachWall(n, -1);
		ReachWall(n, aMap.width);
	}
	if (isDoorPrint == true)
	{
		ReachWall(9, 19);
	}
}

void PacMan::ReachWall(int wallX, int wallY)
{
	switch (pacManDirection)
	{
	case Direction::left:
		CheckDirection(wallX, wallY + 1, x, y, isPacManTurnLeftAllow, pacManDirection, 0);
		break;
	case Direction::rigth:
		CheckDirection(wallX, wallY - 1, x, y, isPacManTurnRigthAllow, pacManDirection, 0);
		break;
	case Direction::down:
		CheckDirection(wallX - 1, wallY, x, y, isPacManTurnDownAllow, pacManDirection, 0);
		break;
	case Direction::up:
		CheckDirection(wallX + 1, wallY, x, y, isPacManTurnUpAllow, pacManDirection, 0);
		break;
	}
}

#endif // !GameLogic
