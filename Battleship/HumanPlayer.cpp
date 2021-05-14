#include "HumanPlayer.h"

void BattleshipGame::HumanPlayer::GetTurn()
{
	SetEnabled();
}

void BattleshipGame::HumanPlayer::SetEnabled()
{
	this->GetBoard()->SetEnabled();
}

void BattleshipGame::HumanPlayer::SetDisabled()
{
	this->GetBoard()->SetDisabled();
}