#include "ComputerPlayer.h"

void BattleshipGame::ComputerPlayer::GetTurn()
{
	Random ^ random = gcnew Random();
	int x = 0;
	int y = 0;
	do 
	{
		x = random->Next(0, this->GetBoard()->GetMapSize());
		y = random->Next(0, this->GetBoard()->GetMapSize());
	} while (!this->GetBoard()->GetCell(x, y)->CanBeHit());
}
