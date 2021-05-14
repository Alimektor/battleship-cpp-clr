#pragma once
#include "CellState.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace BattleshipGame
{
	ref class CellButton :
		public Button
	{
	private:
		CellState State;
		int X;
		int Y;
	public:
		CellButton(int x, int y);
		CellButton(CellState state, int x, int y);
		CellState GetState();
		void SetState(CellState state);
		void UpdateCellButton();
		int GetX();
		int GetY();
		bool IsEmpty();
		void SetEnabled();
		void SetDisabled();
		bool CanBeHit();
	};
}

