#pragma once
#include "Player.h"

namespace BattleshipGame
{
	public ref class ComputerPlayer : public Player
	{
	public:
		virtual void GetTurn() override;
	};
}
