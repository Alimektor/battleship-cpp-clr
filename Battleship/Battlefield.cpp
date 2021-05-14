#include "Battlefield.h"

void BattleshipGame::Battlefield::SetAShip(int x, int y, Ship^ ship, bool vertical)
{
	int length = ship->GetSize() - 1;
	CellState state = ShipState;
	for (int p = 0; p <= length; p++)
	{
		this->GetCell(x, y)->SetState(state);
		if (vertical)
		{
			y++;
		}
		else
		{
			x++;
		}
	}
}

BattleshipGame::Battlefield::Battlefield()
{
	for (int i = 0; i < this->GetMapSize(); i++)
	{
		for (int j = 0; j < this->GetMapSize(); j++)
		{
			this->Field[i, j] = gcnew CellButton(i, j);
		}
	}
}

void BattleshipGame::Battlefield::SetHidden()
{
	ShipState = CellState::Hidden;
}

int BattleshipGame::Battlefield::GetCellSize()
{
	return this->CellSize;
}

BattleshipGame::CellButton^ BattleshipGame::Battlefield::GetCell(int x, int y)
{
	return this->Field[x, y];
}

int BattleshipGame::Battlefield::GetMapSize()
{
	return this->MapSize;
}

bool BattleshipGame::Battlefield::CheckLose()
{
	return this->GetShipCount() == 0;
}

int BattleshipGame::Battlefield::GetShipCount()
{
	int count = 0;

	for (int i = 0; i < this->GetMapSize(); i++)
	{
		for (int j = 0; j < this->GetMapSize(); j++)
		{
			if (this->GetCell(i, j)->GetState() == ShipState)
			{
				count++;
			}
		}
	}

	return count;
}

bool BattleshipGame::Battlefield::InsertShip(int x, int y, Ship^ ship, bool vertical)
{
	if (ship->GetSize() >= 0 && ship->GetSize() < this->GetMapSize())
	{
		int testX = x;
		int testY = y;
		for (int p = 0; p < ship->GetSize(); p++)
		{
			if (!TestEnvironment(testX, testY))
			{
				return false;
			}
			if (vertical)
			{
				testY++;
			}
			else
			{
				testX++;
			}
		}
		this->SetAShip(x, y, ship, vertical);
		return true;
	}
	return false;
}

bool BattleshipGame::Battlefield::TestEnvironment(int indexX, int indexY)
{
	if (indexX < 0 || indexX >= this->GetMapSize())
		return false;
	if (indexY < 0 || indexY >= this->GetMapSize())
		return false;
	int x = 0;
	int y = 1;
	array<int, 2>^ testArray = gcnew array<int, 2>(9, 2);
	testArray[0, x] = indexX - 1;	testArray[0, y] = indexY - 1;
	testArray[1, x] = indexX;		testArray[1, y] = indexY - 1;
	testArray[2, x] = indexX + 1;	testArray[2, y] = indexY - 1;
	testArray[3, x] = indexX - 1;	testArray[3, y] = indexY;
	testArray[4, x] = indexX;		testArray[4, y] = indexY;
	testArray[5, x] = indexX + 1;	testArray[5, y] = indexY;
	testArray[6, x] = indexX - 1;	testArray[6, y] = indexY + 1;
	testArray[7, x] = indexX;		testArray[7, y] = indexY + 1;
	testArray[8, x] = indexX + 1;	testArray[8, y] = indexY + 1;

	bool result = false;
	for (int p = 0; p < 9; p++)
	{
		result = TestMap(testArray[p, x], testArray [p, y]);
		if (result == 0)
		{
			return false;
		}
	}
	return true;
}

bool BattleshipGame::Battlefield::TestMap(int indexX, int indexY)
{
	if (indexX >= 0 && indexX < this->GetMapSize()
		&& indexY >= 0 && indexY < this->GetMapSize())
	{
		if (this->GetCell(indexX, indexY)->IsEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void BattleshipGame::Battlefield::SetRandomShip(Ship^ ship, int salt)
{
	Random^ rand = gcnew Random(salt);
	bool isNotSettled = true;
	int x = 0;
	int y = 0;
	while (isNotSettled)
	{
		bool vertical = (bool)rand->Next(0, 1);
		x = rand->Next(0, this->GetMapSize());
		y = rand->Next(0, this->GetMapSize());
		if (this->InsertShip(x, y, ship, vertical))
		{
			isNotSettled = false;
		}
	}
}

void BattleshipGame::Battlefield::SetBoard(int salt)
{
	this->ClearBoard();
	for (int size = 4, count = 1; size > 0; size--, count++)
	{
		for (int j = 0; j < count; j++)
		{
			SetRandomShip(gcnew Ship(size), salt);
		}
	}
}

void BattleshipGame::Battlefield::ClearBoard()
{
	for (int i = 0; i < this->GetMapSize(); i++)
	{
		for (int j = 0; j < this->GetMapSize(); j++)
		{
			this->GetCell(i, j)->SetState(CellState::Empty);
		}
	}
}

void BattleshipGame::Battlefield::SetEnabled()
{
	for (int i = 0; i < this->GetMapSize(); i++)
	{
		for (int j = 0; j < this->GetMapSize(); j++)
		{
			this->GetCell(i, j)->SetEnabled();
		}
	}
}

void BattleshipGame::Battlefield::SetDisabled()
{
	for (int i = 0; i < this->GetMapSize(); i++)
	{
		for (int j = 0; j < this->GetMapSize(); j++)
		{
			this->GetCell(i, j)->SetDisabled();
		}
	}
}