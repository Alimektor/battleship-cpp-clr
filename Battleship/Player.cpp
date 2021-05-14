#include "Player.h"

bool BattleshipGame::Player::IsWin()
{
	return this->Board->CheckLose();
}

BattleshipGame::Battlefield^ BattleshipGame::Player::GetBoard()
{
	return this->Board;
}