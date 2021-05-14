#pragma once
#include "CellButton.h"

namespace BattleshipGame
{
	ref class Ship
	{
	private:
		int Size;
		int Current;
		array<CellButton^>^ buttons;
	public:
		Ship(int size);
		int GetSize();
		void AddCoordinate(CellButton^ button);
		bool IsSunk();
		void Hit();
	};
}


