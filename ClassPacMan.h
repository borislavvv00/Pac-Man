#pragma once
#ifndef ClassPacMan
#define ClassPacMan
#include "ClassCharecter.h"

class PacMan : private Charecter
{
private:
	int x, y;
	inline void CheckMove();
	inline void ReachWall(int wallX, int wallY);
public:
	PacMan()
	{
		y = 19;
		x = 12;
		sign = "C";
	}
	void DrawPacMan(int i, int j);
	void GetKeyboardCommands();
	void Movement();
	void EatFood(int &f);
	void EatCure(int &c);
	void TouchGhost();
	friend class Ghosts;
};
PacMan pacMan;

#endif // !ClassPacMan
