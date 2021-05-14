#pragma once
#include "CellButton.h"
#include "Ship.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace BattleshipGame {

	ref class Battlefield
	{
	private:
		int MapSize = 10;
		int CellSize = 50;
		array<CellButton^, 2>^ Field = gcnew array<CellButton^, 2>(MapSize, MapSize);
		CellState ShipState = CellState::Ship;

		bool TestEnvironment(int indexX, int indexY);
		bool TestMap(int indexX, int indexY);
		void SetRandomShip(Ship^ ship, int salt);
		void SetAShip(int x, int y, Ship^ ship, bool vertical);
		int GetShipCount();
		bool InsertShip(int x, int y, Ship^ ship, bool vertical);
	public:
		Battlefield();
		void SetHidden();
		CellButton^ GetCell(int x, int y);
		int GetMapSize();
		int GetCellSize();
		bool CheckLose();
		void SetEnabled();
		void SetDisabled();
		void SetBoard(int salt);
		void ClearBoard();
	};
}
