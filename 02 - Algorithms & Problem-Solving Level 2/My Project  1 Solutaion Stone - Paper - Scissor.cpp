#include <iostream>

using namespace std;

enum Choices{Stone = 1 , Paper = 2 , Scissor = 3 };



int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

int ReadRoundGame(int& RoundGame) // First stape
{
	cout << "How Many Rounds 1 to 10? \n";
	cin >> RoundGame;

	while (RoundGame < 1 || RoundGame > 10)
	{
		cout << "\nSorry!! , Choice Rounds 1 to 10 only.\n";
		cin >> RoundGame;
	}

	return RoundGame;
}


int ReadChoiceFromUser() // Second stape
{
	int Choice = 0;

	cin >> Choice;
	
	if (Choice == 1)

		return Choices::Stone;

	else if (Choice == 2)

		return Choices::Paper;

	else

		return Choices::Scissor;
}

int ReadChoiceFromComputer() // Third stape
{
	int Choice = 0;

	Choice = RandomNumber(1, 3);

	if (Choice == 1)

		return Choices::Stone;

	else if (Choice == 2)

		return Choices::Paper;

	else

		return Choices::Scissor;

}

string PrintChoice(int Choice)
{
	if (Choice == Choices::Stone)
		return "Stone";

	else if (Choice == Choices::Paper)
		return "Paper";

	else
		return "Scissor";
}

string WonPlayer(int User, int Computer)
{

	if (User == Choices::Stone && Computer == Choices::Scissor)

		return "[Player 1]";

	else if(User == Choices::Paper && Computer == Choices::Stone)

		return "[Player 1]";

	else if(User == Choices::Scissor && Computer == Choices::Paper)

		return "[Player 1]";


	else if (User == Choices::Stone && Computer == Choices::Paper)

		return "[Computer]";

	else if (User == Choices::Paper && Computer == Choices::Scissor)

		return "[Computer]";

	else if (User == Choices::Scissor && Computer == Choices::Stone)

		return "[Computer]";

	else if(User == Choices::Stone && Computer == Choices::Stone)

		return "[No Winner]";

	else if(User == Choices::Paper && Computer == Choices::Paper)

		return "[No Winner]";

	else if (User == Choices::Scissor && Computer == Choices::Scissor)

		return "[No Winner]";

}

void PrintResult(int User, int Computer)
{
	

	cout << "\n\n";
	cout << "Player 1 Choice: " << PrintChoice(User) << endl;
	cout << "Computer Choice: " << PrintChoice(Computer) << endl;
	cout << "Round Winner " << WonPlayer(User, Computer) << endl;
	cout << "_________________________________________________";
	cout << "\n\n";
}



void  CheckChoiceBetweenUserAndCom(int RoundGame , int User[10], int Computer[10])
{

	

	for (int i = 0; i < RoundGame; i++)
	{
		cout << "\nRound [" << i + 1 << "] begins: \n";
		cout << "Your Choice: [1]: Stone, [2]: Paper, [3]: Scissor? \n";
		User[i] = ReadChoiceFromUser();
		Computer[i] = ReadChoiceFromComputer();

	

		if (User[i] == Choices::Stone && Computer[i] == Choices::Scissor)
		{	
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 2f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Stone)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 2f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Paper)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 2f");
			PrintResult(User[i], Computer[i]);
		}


		else if (User[i] == Choices::Stone && Computer[i] == Choices::Paper)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			cout << '\a';
			system("Color 4f");
			PrintResult(User[i], Computer[i]);
			
		}

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Scissor)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			cout << '\a';
			system("Color 4f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Stone)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			cout << '\a';
			system("Color 4f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Stone && Computer[i] == Choices::Stone)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 6f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Paper)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 6f");
			PrintResult(User[i], Computer[i]);
		}

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Scissor)
		{
			cout << "____________________ Round[" << i + 1 << "] ____________________\n\n";
			system("Color 6f");
			PrintResult(User[i], Computer[i]);
		}

	}

}


int WonTimeToUser(int RoundGame , int User[10], int Computer[10])
{
	int UserCount = 0;

	for (int i = 0; i < RoundGame; i++)
	{
		if (User[i] == Choices::Stone && Computer[i] == Choices::Scissor)

			UserCount++;

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Stone)

			UserCount++;

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Paper)

			UserCount++;

	}

	return UserCount;
}

int WonTimeToComputer(int RoundGame, int User[10], int Computer[10])
{
	int ComputerCount = 0;

	for (int i = 0; i < RoundGame; i++)
	{
		if (User[i] == Choices::Stone && Computer[i] == Choices::Paper)

			ComputerCount++;

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Scissor)

			ComputerCount++;

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Stone)

			ComputerCount++;
	}


	return ComputerCount;

}

int DrawTime(int RoundGame, int User[10], int Computer[10])
{
	int DrawCount = 0;

	for (int i = 0; i < RoundGame; i++)
	{
		if (User[i] == Choices::Stone && Computer[i] == Choices::Stone)

			DrawCount++;

		else if (User[i] == Choices::Paper && Computer[i] == Choices::Paper)

			DrawCount++;

		else if (User[i] == Choices::Scissor && Computer[i] == Choices::Scissor)

			DrawCount++;
	}

	return DrawCount;

}

string PrintFinalWinner(int RoundGame , int User[10], int Computer[10])
{
	


		if (WonTimeToUser(RoundGame , User , Computer) > WonTimeToComputer(RoundGame , User , Computer))

			return "Player 1 ";

		else if (WonTimeToUser(RoundGame, User, Computer) < WonTimeToComputer(RoundGame, User, Computer))

			return "Computer ";

		else

			return "No Winner ";
	
}

bool RestartGame()
{
	char Restart;

	cin >> Restart;

	cout << endl;

	if (Restart == 'Y' || Restart == 'y')

		return 1;



	else if (Restart == 'N' || Restart == 'n')

		return 0;

	else

		return 0;

}



void PrintFinalGame(int RoundGame, int User[10], int Computer[10])
{
	system("Color 1f");
	cout << "\n        __________________________________________________________\n";
	cout << "\n\n			     +++ GAME OVER +++					\n";
	cout << "\n	__________________________________________________________\n\n";

	cout << "        ______________________ [Game Results] ____________________\n\n";
	cout << "        Game Round: " << RoundGame << endl;
	cout << "        Player 1 won times : " << WonTimeToUser(RoundGame , User , Computer) << endl;
	cout << "	Computer won times : " << WonTimeToComputer(RoundGame, User, Computer) << endl;
	cout << "	Draw times : " << DrawTime(RoundGame, User, Computer) << endl;
	cout << "	Final Winner : " << PrintFinalWinner(RoundGame , User , Computer) << endl;
	cout << "        ____________________________________________________________\n\n";
	cout << "        Do you want to play again> Y/N? : ";

		
}



void StartGame()
{

	int RoundGame = 0, User[10], Computer[10];

	ReadRoundGame(RoundGame);
	CheckChoiceBetweenUserAndCom(RoundGame, User, Computer);
	PrintFinalGame(RoundGame, User, Computer);
	while (RestartGame())
	{
		StartGame();
	}

	
	

}



int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	StartGame();




	return 0;

}
