#pragma once
#ifndef GameMovement
#define GameMovement
#include "ClassPacMan.h"
#include "ClassGhosts.h"

void PacMan::GetKeyboardCommands()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			pacManDirection = Direction::left;
			break;
		case 'd':
			pacManDirection = Direction::rigth;
			break;
		case 's':
			pacManDirection = Direction::down;
			break;
		case 'w':
			pacManDirection = Direction::up;
			break;
		}
	}
}

void PacMan::Movement()//describes the four directions
{
	switch (pacManDirection)
	{
	case Direction::left:
		CheckMove();
		if (isPacManTurnLeftAllow == true)
		{
			y--;
			countPacManMoves++;
		}
		break;
	case Direction::rigth:
		CheckMove();
		if (isPacManTurnRigthAllow == true)
		{
			y++;
			countPacManMoves++;
		}
		break;
	case Direction::down:
		CheckMove();
		if (isPacManTurnDownAllow == true)
		{
			x++;
			countPacManMoves++;
		}
		break;
	case Direction::up:
		CheckMove();
		if (isPacManTurnUpAllow == true)
		{
			x--;
			countPacManMoves++;
		}
		break;
	}
}

void Ghosts::Movement(int n)//describes the four directions
{
	switch (ghostsDirection[n])
	{
	case Direction::left:
		CheckMove(n);
		if (isGhostTurnLeftAllow == true)
		{
			y[n]--;
		}
		break;
	case Direction::rigth:
		CheckMove(n);
		if (isGhostTurnRigthAllow == true)
		{
			y[n]++;
		}
		break;
	case Direction::down:
		CheckMove(n);
		if (isGhostTurnDownAllow == true)
		{
			x[n]++;
		}
		break;
	case Direction::up:
		CheckMove(n);
		if (isGhostTurnUpAllow == true)
		{
			x[n]--;
		}
		break;
	}
}

#endif // !GameMovement
