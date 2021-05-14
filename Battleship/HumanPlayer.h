#pragma once
#include "Player.h"

namespace BattleshipGame
{
	public ref class HumanPlayer : public Player
	{
	private:
		void SetEnabled();

	public:
		virtual void GetTurn() override;
		void SetDisabled();
	};
}
