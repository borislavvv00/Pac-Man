#pragma once
#ifndef ClassGhosts
#define ClassGhosts
#include "ClassCharecter.h"

class Ghosts : private Charecter
{
private:
	int x[4], y[4];
	int color[4];
	bool isGhostEaten[4];
	void TouchGhost(int n);
	void GetInHouse(int n);
	void Target(int n, int targetX, int targetY, int dir1, int dir2, int dir3, int dir4);
	inline void CheckMove(int currentGhost);
	inline void ReachWall(int wallX, int wallY);
public:
	bool isGhostChasePacMan[4];
	bool isGhostRunFromPacMan[4];
	bool isGhostGoOutFromHouse[4];
	bool isGhostGoToHouse[4];
	Ghosts()
	{
		sign = "A";
		y[0] = 17;
		y[1] = 18;
		y[2] = 20;
		y[3] = 21;
		for (int n = 0; n < 4; n++)
		{
			x[n] = 10;
			isGhostEaten[n] = false;
			isGhostChasePacMan[n] = false;
			isGhostRunFromPacMan[n] = false;
			isGhostGoOutFromHouse[n] = false;
			isGhostGoToHouse[n] = false;
			color[n] = 10 + n;
		}
	}
	void DrawGhosts(int i, int j);
	void ChooseMove();
	void Instructions();
	void ChasePacMan(int n);
	void RunFromPacMan(int n);
	void GoOutFromHouse(int n);
	void GoToHouse(int n);
	void StepOver(int x, int y, bool &isPrint);
	inline void Movement(int n);
	friend class PacMan;
};
Ghosts ghosts;

#endif // !ClassGhosts
