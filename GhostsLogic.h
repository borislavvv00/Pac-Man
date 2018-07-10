#pragma once
#ifndef GhostsLogic
#define GhostsLogic
#include "GameMovement.h"

void Ghosts::ReachWall(int wallX, int wallY)
{
	for (int n = 0; n < 4; n++)
	{
		switch (ghostsDirection[n])
		{
		case Direction::left:
			CheckDirection(wallX, wallY + 1, ghosts.x[n], ghosts.y[n], isGhostTurnLeftAllow, ghostsDirection[n], 4);
			break;
		case Direction::rigth:
			CheckDirection(wallX, wallY - 1, ghosts.x[n], ghosts.y[n], isGhostTurnRigthAllow, ghostsDirection[n], 3);
			break;
		case Direction::down:
			CheckDirection(wallX - 1, wallY, ghosts.x[n], ghosts.y[n], isGhostTurnDownAllow, ghostsDirection[n], 1);
			break;
		case Direction::up:
			CheckDirection(wallX + 1, wallY, ghosts.x[n], ghosts.y[n], isGhostTurnUpAllow, ghostsDirection[n], 2);
			break;
		}
	}
}

void Ghosts::TouchGhost(int n)
{
	//n is used for current ghost
	//m is used for the rest 3 ghosts
	for (int m = 0; m < 4; m++)
	{
		if (m != n)
		{
			switch (ghostsDirection[n])
			{
			case Direction::left:
				CheckDirection(ghosts.x[m], ghosts.y[m] + 1, ghosts.x[n], ghosts.y[n], isGhostTurnLeftAllow, ghostsDirection[n], 2);
				break;
			case Direction::rigth:
				CheckDirection(ghosts.x[m], ghosts.y[m] - 1, ghosts.x[n], ghosts.y[n], isGhostTurnRigthAllow, ghostsDirection[n], 1);
				break;
			case Direction::down:
				CheckDirection(ghosts.x[m] - 1, ghosts.y[m], ghosts.x[n], ghosts.y[n], isGhostTurnDownAllow, ghostsDirection[n], 4);
				break;
			case Direction::up:
				CheckDirection(ghosts.x[m] + 1, ghosts.y[m], ghosts.x[n], ghosts.y[n], isGhostTurnUpAllow, ghostsDirection[n], 3);
				break;
			}
		}
	}
}

void Ghosts::CheckMove(int currentGhost)
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
	for (int n = 0; n < 4; n++)
	{
		if (isDoorPrint == true)
		{
			ReachWall(9, 19);
		}
	}
	TouchGhost(currentGhost);
}

void Ghosts::StepOver(int x, int y, bool &isPrint)
{
	for (int n = 0; n < 4; n++)
	{
		if (ghosts.x[n] != x || ghosts.y[n] != y)
		{
			isPrint = true;
		}
		for (int m = 0; m < 4; m++)
		{
			if (n != m)
			{
				if (ghosts.x[m] == x && ghosts.y[m] == y)
				{
					isPrint = false;
					isCharecterDraw = false;
				}
			}
		}
	}
}

#endif // !GhostsMoveLogic
