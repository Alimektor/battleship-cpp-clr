#include "BattleshipForm.h"


[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BattleshipGame::BattleshipForm form;
	Application::Run(% form);
}

void BattleshipGame::BattleshipForm::Init()
{
	InitMaps(human->GetBoard(), computer->GetBoard());
	human->GetBoard()->SetHidden();
}

void BattleshipGame::BattleshipForm::InitMaps(Battlefield ^ firstField, Battlefield ^ secondField)
{
	this->Width = firstField->GetMapSize() * 2 * firstField->GetCellSize() + firstField->GetCellSize() * 2;
	this->Height = (firstField->GetMapSize() + 3) * firstField->GetCellSize() + firstField->GetCellSize();
	
	this->PrintBattleField(firstField, 0, "Player Map");
	this->PrintBattleField(secondField, secondField->GetMapSize() * secondField->GetCellSize() + secondField->GetCellSize() * 2, "EnemyMap");

	// Start button
	startButton = gcnew Button();
	startButton->Text = "Start";
	startButton->Location = Point(
		firstField->GetMapSize() * firstField->GetCellSize() + firstField->GetCellSize() / 2,
		firstField->GetMapSize() * firstField->GetCellSize() + firstField->GetCellSize() + 20
	);
	startButton->Font = (gcnew System::Drawing::Font(L"Consolas", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	startButton->Size = System::Drawing::Size(100, 50);
	startButton->Click += gcnew System::EventHandler(this, &BattleshipGame::BattleshipForm::Start);
	this->Controls->Add(startButton);
}

void BattleshipGame::BattleshipForm::PrintBattleField(Battlefield^ field, int offset, String^ textMap)
{
	for (int i = 0; i < field->GetMapSize() + 1; i++)
	{
		for (int j = 0; j < field->GetMapSize() + 1; j++)
		{
			CellButton^ button;

			if (j == 0 || i == 0)
			{
				button = gcnew CellButton(-1, -1);
				button->BackColor = Color::Gray;
				if (j == 0 && i > 0)
				{
					button->Text = i.ToString();
				}

				if (i == 0 && j > 0)
				{
					button->Text = Alphabet[j - 1].ToString();
				}
			}
			else
			{
				button = field->GetCell(i - 1, j - 1);
				button->Click += gcnew System::EventHandler(&SetAHit);
				button->Click += gcnew System::EventHandler(this, &BattleshipGame::BattleshipForm::PlayerTurn);
			}

			button->Location = Point(j * field->GetCellSize() + offset, i * field->GetCellSize());
			button->Size = System::Drawing::Size(field->GetCellSize(), field->GetCellSize());
			button->Font = (gcnew System::Drawing::Font(L"Consolas", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Controls->Add(button);
		}
	}

	Label^ PlayerMapLabel = gcnew Label();
	PlayerMapLabel->Text = textMap;
	PlayerMapLabel->Location = Point(field->GetMapSize() * field->GetCellSize() / 2 - 10 + offset, field->GetMapSize() * field->GetCellSize() + field->GetCellSize() * 2);
	PlayerMapLabel->Font = (gcnew System::Drawing::Font(L"Consolas", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->Controls->Add(PlayerMapLabel);
}

void BattleshipGame::BattleshipForm::SetAHit(Object^ sender, EventArgs^ e)
{
	CellButton^ currentButton = (CellButton^)sender;
	currentButton->CanBeHit();
}

void BattleshipGame::BattleshipForm::PlayerTurn(Object^ sender, EventArgs^ e)
{
	this->human->SetDisabled();
	playerTurn = false;
	if (this->human->IsWin())
	{
		EndGame("You win!");
		return void();
	}
	ComputerTurn();
}

void BattleshipGame::BattleshipForm::ComputerTurn()
{
	this->computer->GetTurn();
	if (this->computer->IsWin())
	{
		EndGame("You lose!");
		return void();
	}
	this->human->GetTurn();
}

void BattleshipGame::BattleshipForm::Start(Object^ sender, EventArgs^ e)
{
	Button^ pressedButton = (Button^)sender;
	if (isPlaying)
	{
		InitialGame();
	}
	else
	{
		isPlaying = true;
		pressedButton->Text = L"Stop";
		Play();
	}

}

void BattleshipGame::BattleshipForm::Play()
{
	this->human->GetBoard()->SetBoard((gcnew Random)->Next());
	this->computer->GetBoard()->SetBoard((gcnew Random)->Next() + (gcnew Random)->Next());
	ComputerTurn();
}

void BattleshipGame::BattleshipForm::EndGame(String^ text)
{
	MessageBox::Show(text);
	InitialGame();
}

void BattleshipGame::BattleshipForm::InitialGame()
{
	isPlaying = false;
	this->human->GetBoard()->ClearBoard();
	this->computer->GetBoard()->ClearBoard();
	this->startButton->Text = L"Start";
}
