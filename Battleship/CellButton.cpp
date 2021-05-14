#include "CellButton.h"

BattleshipGame::CellButton::CellButton(int x, int y)
    : CellButton(CellState::Empty, x, y) {}

BattleshipGame::CellButton::CellButton(CellState state, int x, int y)
{
    this->State = state;
	this->X = x;
	this->Y = y;
	this->TabStop = false;
    this->UpdateCellButton();
}

CellState BattleshipGame::CellButton::GetState()
{
    return this->State;
}

void BattleshipGame::CellButton::SetState(CellState state)
{
    this->State = state;
	this->UpdateCellButton();
}

void BattleshipGame::CellButton::UpdateCellButton()
{
	switch (this->State)
	{
	case CellState::Empty:
	case CellState::Hidden:
		this->BackColor = Color::White;
		break;
	case CellState::Hit:
		this->BackColor = Color::Red;
		this->Enabled = false;
		break;
	case CellState::Ship:
		this->BackColor = Color::Green;
		break;
	case CellState::Missed:
		this->BackColor = Color::Aqua;
		this->Enabled = false;
		break;
	default:
		throw gcnew System::Exception("Unexpected State!");
		break;
	}
	String^ text = gcnew String((char)this->State, 1);
	if (this->GetState() == CellState::Hidden)
	{
		text = gcnew String((char)CellState::Empty, 1);
	}
	this->Enabled = false;
	this->Text = text;
}

int BattleshipGame::CellButton::GetX()
{
	return this->X;
}

int BattleshipGame::CellButton::GetY()
{
	return this->Y;
}

bool BattleshipGame::CellButton::IsEmpty()
{
	return this->GetState() == CellState::Empty;
}

void BattleshipGame::CellButton::SetEnabled()
{
	if (this->GetState() == CellState::Empty || this->GetState() == CellState::Hidden)
		this->Enabled = true;
}

void BattleshipGame::CellButton::SetDisabled()
{
	this->Enabled = false;
}

bool BattleshipGame::CellButton::CanBeHit()
{
	switch (this->GetState())
	{
	case CellState::Empty:
		this->SetState(CellState::Missed);
		return true;
		break;
	case CellState::Hit:
		return false;
		break;
	case CellState::Ship:
	case CellState::Hidden:
		this->SetState(CellState::Hit);
		return true;
		break;
	case CellState::Missed:
		return false;
		break;
	default:
		return false;
		break;
	}
}