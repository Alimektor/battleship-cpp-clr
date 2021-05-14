#include "Ship.h"

BattleshipGame::Ship::Ship(int size)
{
    this->Size = size;
    this->Current = 0;
    buttons = gcnew array<CellButton^>(Size);
}

int BattleshipGame::Ship::GetSize()
{
    return this->Size;
}

void BattleshipGame::Ship::AddCoordinate(CellButton^ button)
{
    buttons[Current] = button;
    Current++;
}

bool BattleshipGame::Ship::IsSunk()
{
    return Size == 0;
}

void BattleshipGame::Ship::Hit()
{
    Size--;
}
