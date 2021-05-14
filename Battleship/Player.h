#pragma once
#include "Battlefield.h"

namespace BattleshipGame
{
	public ref class Player
	{
	private:
		Battlefield^ Board = gcnew Battlefield();
	public:
		bool IsWin();
		Battlefield^ GetBoard();
		virtual void GetTurn() = 0;
	};
}
