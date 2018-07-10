#pragma once
#ifndef DrawCharecters
#define DrawCharecters
#include "ClassPacMan.h"
#include "ClassGhosts.h"

inline void DrawCharecter(int color, string sign)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << sign;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void PacMan::DrawPacMan(int i, int j)
{
	if (i == x && j == y)
	{
		DrawCharecter(14, sign);
		isCharecterDraw = true;
	}
}

void Ghosts::DrawGhosts(int i, int j)
{
	for (int n = 0; n < 4; n++)
	{
		if (i == x[n] && j == y[n])
		{
			if (isGhostEaten[n] == false && isCureEaten == false)
			{
				DrawCharecter(color[n], sign);
				isCharecterDraw = true;
			}
			else if (isCureEaten == true && isGhostEaten[n] == false)
			{
				DrawCharecter(9, sign);
				isCharecterDraw = true;
			}
			else if (isGhostEaten[n] == true)
			{
				DrawCharecter(color[n], sign);
				isCharecterDraw = true;
			}
		}
	}
}

#endif // !DrawCharecters
