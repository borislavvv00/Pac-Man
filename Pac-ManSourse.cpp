#include "DrawMap.h"
#include "GameMovement.h"
#include "GhostsMoveInstructions.h"
#include "GameMenu.h"

void GameLogic()
{
	if (isCureEaten == true)
	{
		countCureTime--;
	}
	if (countCureTime == 0)
	{
		countCureTime = 20;
		isCureEaten = false;
		for (int n = 0; n < 4; n++)
		{
			ghosts.isGhostChasePacMan[n] = true;
			ghosts.isGhostRunFromPacMan[n] = false;
		}
	}
	if (isDoorPrint == true)
	{
		isOpenDoorPrint = false;
	}
	else
	{
		isOpenDoorPrint = true;
	}
}

int main()
{
	aMap.WallsGetCoordinates();
	aMap.CureGetCoordinates();
	while (!isGameOver)
	{
		if (choice == 0)
		{
			DrawMenu();
			system("cls");
		}
		else if (choice == 1)
		{
			GameLogic();
			pacMan.GetKeyboardCommands();
			pacMan.Movement();
			ghosts.Movement(0);
			ghosts.Movement(1);
			ghosts.Movement(2);
			ghosts.Movement(3);
			ghosts.ChooseMove();
			ghosts.Instructions();
			pacMan.TouchGhost();
			aMap.BuildMap();
		}
		else if (choice == 2)
		{
			Rules();
			system("cls");
		}
		else if (choice == 3)
		{
			Credits();
			system("cls");
		}
		ClearScreen();
		Sleep(100);
	}
	system("cls");
	aMap.EndGame();
	return 0;
}
