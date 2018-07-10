#pragma once
#ifndef GhostsMoveInstructions
#define GhostsMoveInstructions
#include "PacManLogic.h"

void Ghosts::ChooseMove()
{
	for (int n = 0; n < 4; n++)
	{
		if (ghosts.isGhostGoOutFromHouse[n] == true)
		{
			ghosts.GoOutFromHouse(n);
		}
		else if (ghosts.isGhostChasePacMan[n] == true)
		{
			ghosts.ChasePacMan(n);
		}
		else if (ghosts.isGhostGoToHouse[n] == true)
		{
			ghosts.GoToHouse(n);
		}
		else if (ghosts.isGhostRunFromPacMan[n] == true)
		{
			ghosts.RunFromPacMan(n);
		}
	}
}

void Ghosts::Instructions()
{
	switch (countPacManMoves)
	{
	case 2:
		isDoorPrint = false;
		ghosts.isGhostGoOutFromHouse[1] = true;
		break;
	case 10:
		isDoorPrint = true;
		ghosts.isGhostChasePacMan[1] = true;
		ghosts.isGhostGoOutFromHouse[1] = false;
		break;
	case 20:
		isDoorPrint = false;
		ghosts.isGhostGoOutFromHouse[2] = true;
		break;
	case 30:
		isDoorPrint = true;
		ghosts.isGhostChasePacMan[2] = true;
		ghosts.isGhostGoOutFromHouse[2] = false;
		break;
	case 40:
		isDoorPrint = false;
		ghosts.isGhostGoOutFromHouse[0] = true;
		break;
	case 50:
		isDoorPrint = true;
		ghosts.isGhostChasePacMan[0] = true;
		ghosts.isGhostGoOutFromHouse[0] = false;
		break;
	case 60:
		isDoorPrint = false;
		ghosts.isGhostGoOutFromHouse[3] = true;
		break;
	case 70:
		isDoorPrint = true;
		ghosts.isGhostChasePacMan[3] = true;
		ghosts.isGhostGoOutFromHouse[3] = false;
		break;
	}
}

void Ghosts::GoOutFromHouse(int n)
{	
	if (19 > ghosts.y[n])
	{
		ghostsDirection[n] = Direction::rigth;
	}
	else if (19 < ghosts.y[n])
	{
		ghostsDirection[n] = Direction::left;
	}
	else if (ghosts.y[n] == 19)
	{
		ghostsDirection[n] = Direction::up;
	}
}

void Ghosts::Target(int n, int targetX, int targetY, int dir1, int dir2, int dir3, int dir4)//dir - direction
{
	if (targetX > ghosts.x[n])
	{
		CheckMove(n);
		ghostsDirection[n] = Direction(dir1);
	}
	else if (targetX < ghosts.x[n])
	{
		CheckMove(n);
		ghostsDirection[n] = Direction(dir2);
	}
	else if (targetY > ghosts.y[n])
	{
		CheckMove(n);
		ghostsDirection[n] = Direction(dir3);
	}
	else if (targetY < ghosts.y[n])
	{
		CheckMove(n);
		ghostsDirection[n] = Direction(dir4);
	}
}

void Ghosts::ChasePacMan(int n)
{
	Target(n, pacMan.x, pacMan.y, 3, 4, 2, 1);
}

void Ghosts::RunFromPacMan(int n)
{
	Target(n, pacMan.x, pacMan.y, 4, 3, 1, 2);
}

void Ghosts::GetInHouse(int n)
{
	if (ghosts.x[n] == 8)
	{
		ghostsDirection[n] = Direction::down;
	}
	else if (ghosts.x[n] == 10)
	{
		ghostsDirection[n] = Direction::rigth;
	}
}

void Ghosts::GoToHouse(int n)
{
	Target(n, 8, 19, 3, 4, 2, 1);
	if (ghosts.y[n] == 19 && ghosts.x[n] == 8)
	{
		GetInHouse(n);
	}
}

#endif // !GhostChasePacMan
