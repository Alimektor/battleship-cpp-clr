#pragma once
#include <string.h>
#include "Battlefield.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

using namespace System;
using namespace System::Windows::Forms;

namespace BattleshipGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BattleshipForm : public System::Windows::Forms::Form
	{
	public:
		bool isPlaying = false;
		String^ Alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
		Button^ startButton;
		HumanPlayer^ human = gcnew HumanPlayer();
		ComputerPlayer^ computer = gcnew ComputerPlayer();

	public:
		bool playerTurn;

		BattleshipForm(void)
		{
			InitializeComponent();
			Init();
		}
		void Init();
		void InitMaps(Battlefield^ firstField, Battlefield^ secondField);
		void PrintBattleField(Battlefield^ field, int offset, String^ textMap);
		void Start(Object^ sender, EventArgs^ e);
		void PlayerTurn(Object^ sender, EventArgs^ e);
		void ComputerTurn();
		void Play();

		void EndGame(String ^ text);

		void InitialGame();

		static void SetAHit(Object^ sender, EventArgs^ e);

	protected:
		~BattleshipForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// BattleshipForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(189, 162);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BattleshipForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Battleship";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
