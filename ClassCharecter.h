#pragma once
#ifndef ClassCharecter
#define ClassCharecter
#include "GameSetUp.h"

class Charecter
{
protected:
	string sign;
	inline void CheckDirection(int wallX, int wallY, int x, int y, bool &isTurnAllow, Direction &dir, int direction);
};

void Charecter::CheckDirection(int wallX, int wallY, int x, int y, bool &isTurnAllow, Direction &dir, int direction)
{
	if (y == wallY && x == wallX)
	{
		isTurnAllow = false;
		dir = Direction(direction);
	}
	else
	{
		isTurnAllow = true;
	}
}

#endif // !CharecterClasses
