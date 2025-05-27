#include <iostream>

using namespace std;

enum enQuizLevel { Easy = 1, Med = 2, Hard = 3 , Mix = 4};
enum enOnType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix2 = 5 };
enum enAnswer {Right = 1 , Wrong = 2};


struct stRoundQuiz
{
	short NumberOfQuiz = 0;
	short TotalQuestion = 0;
	enQuizLevel QuizLevel;
	enOnType OnType;
	int Number1 = 0;
	char PrintOnType = '+';
	int Number2 = 0;
	int ReadAnswer = 0;
	int Equals = 0;
	enAnswer CheckOp;
	string FinalEquals = "";
	string PrintAnswer;
};

struct stQuizResult
{
	string PassOrFail = "";
	short NumberOfQuestion = 0;
	string QuestionLevel = "";
	string OpType = "";
	short NumberOfRightAnswer = 0;
	short NumberOfWrongAnswer = 0;
};

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

short ReadHowManyQuiz()
{
	short Questions = 1;

	do
	{
		cout << "How Many Question do you want to answer ? \n";
		cin >> Questions;
	} while (Questions < 1);

	return Questions;
}

enQuizLevel quizLevel()
{
	short Choice = 1;

	do
	{
		cout << "Enter Question Level [1]: Easy , [2]: Med , [3]: Hard , [4]: Mix? ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 4);

	return (enQuizLevel)Choice;
}

enOnType OnType()
{
	short Choice = 1;

	do
	{
		cout << "Operation Type [1]: Add , [2]: Sub , [3]: Mul , [4]: Div , [5] Mix ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 5);

	return (enOnType)Choice;
}

int RandomNumberOfQuestion(stRoundQuiz RoundQuiz)
{
	int Number = 1;

	switch (RoundQuiz.QuizLevel)
	{
	case enQuizLevel::Easy:
		return Number = RandomNumber(1, 10);
		break;

	case enQuizLevel::Med:
		return Number = RandomNumber(10, 50);
		break;

	case enQuizLevel::Hard:
		return Number = RandomNumber(50, 100);
		break;
	
	case enQuizLevel::Mix:
		return Number = RandomNumber(1, 100);
		break;
	}

}

char ChoiceOnType(enOnType Choice)
{
	char arrChoiceOnType[4] = { '+' , '-', '*' , '/' };

	if (Choice >= 1 && Choice <= 4)
		return arrChoiceOnType[Choice - 1];

	else 

		return arrChoiceOnType[RandomNumber(0,3)];
	
}


int EqualsOp(stRoundQuiz RoundQuiz)
{
	int Equals = 1;;

	

	switch (RoundQuiz.PrintOnType)
	{
	case '+':
		
		return Equals = RoundQuiz.Number1  + RoundQuiz.Number2;
		break;		    					
					    					
	case '-':
		if (RoundQuiz.Number1 > RoundQuiz.Number2)
		return Equals = RoundQuiz.Number1  - RoundQuiz.Number2;
		else
		return Equals = RoundQuiz.Number2 - RoundQuiz.Number1;
		break;		    					
					    					
	case '*':
		return Equals = RoundQuiz.Number1  * RoundQuiz.Number2;
		break;		    					
					    					
	case '/':
		return Equals = RoundQuiz.Number1  / RoundQuiz.Number2;
		break;

	}
}

int AnswerFromUser()
{
	int Answer = 1;
	do
	{
		cin >> Answer;
	} while (Answer <  1);
	return Answer;
}




void ShowQuestion(stRoundQuiz RoundQuiz)
{
	cout << endl;
	cout << "\nQuestion [" << RoundQuiz.NumberOfQuiz << "/" << RoundQuiz.TotalQuestion << "]" << endl << endl;

	if (RoundQuiz.Number1 > RoundQuiz.Number2)
	{
		cout << RoundQuiz.Number1 << endl;
		cout << RoundQuiz.PrintOnType << endl;
		cout << RoundQuiz.Number2 << endl;
		cout << "___________________________\n";
	}
	else

	{
		cout << RoundQuiz.Number2 << endl;
		cout << RoundQuiz.PrintOnType << endl;
		cout << RoundQuiz.Number1 << endl;
		cout << "___________________________\n";
	}
	
}

enAnswer CheckAnswer(stRoundQuiz RoundQuiz)
{

	if (RoundQuiz.ReadAnswer == RoundQuiz.Equals)

		return enAnswer::Right;

	else

		return enAnswer::Wrong;
}

void FinalAnswer(stRoundQuiz RoundQuiz)
{
	switch (RoundQuiz.CheckOp)
	{
	case enAnswer::Right:
		cout <<  "Right Answer :)\n";
		break;

	case enAnswer::Wrong:
		cout <<  "Wrong Answer :(\n";
		cout <<  "The right answer is: " << RoundQuiz.Equals << endl;
		break;
	}
}

void SetWinnerScreenColor(stRoundQuiz RoundQuiz)
{
	switch (RoundQuiz.CheckOp)
	{
	case enAnswer::Right:
		system("Color 2F"); //turn screen to Green
		break;
	case enAnswer::Wrong:
		cout << "\a";
		system("Color 4F"); //turn screen to Red
		break;


	}
}



string ChoiceQuestionLevel(enQuizLevel Choice)
{
	string arrQuestionLevel[4] = { "Easy" , "Med" , "Hard" , "Mix"};

	if (Choice >= 1 || Choice <= 4)

		return arrQuestionLevel[Choice - 1];

}

string PrintOnType(enOnType Choice)
{
	string arrQuestionLevel[5] = { "Add ", "Sub" , "Mul" , "Div" , "Mix" };

	if (Choice >= 1 || Choice <= 5)

		return arrQuestionLevel[Choice - 1];

	else


}

string PassOrFail(stQuizResult QuizResult)
{
	if (QuizResult.NumberOfRightAnswer > QuizResult.NumberOfWrongAnswer)
	{
		return "Pass :)";
	}
	else if (QuizResult.NumberOfWrongAnswer > QuizResult.NumberOfRightAnswer)
	{
		return "Fail :(";
	}
}

stQuizResult FillQuizResult(stRoundQuiz RoundQuiz , short RightAnswer , short WrongAnswer)
{
	stQuizResult FillQuizResult;

	FillQuizResult.NumberOfQuestion = RoundQuiz.NumberOfQuiz;
	FillQuizResult.QuestionLevel = ChoiceQuestionLevel(RoundQuiz.QuizLevel);
	FillQuizResult.OpType = PrintOnType(RoundQuiz.OnType);
	FillQuizResult.NumberOfRightAnswer = RightAnswer;
	FillQuizResult.NumberOfWrongAnswer = WrongAnswer;
	FillQuizResult.PassOrFail = PassOrFail(FillQuizResult);

	return FillQuizResult;
}

stQuizResult PlayGame(short HowManyQuestion)
{
	stRoundQuiz RoundQuiz;
	RoundQuiz.QuizLevel = quizLevel();
	RoundQuiz.OnType = OnType();
	RoundQuiz.TotalQuestion = HowManyQuestion;
	
	short NumberOfRightAnswer = 0, NumberOfWrongAnswer = 0;

	for (int GameRound = 1; GameRound <= HowManyQuestion; GameRound++)
	{
		RoundQuiz.NumberOfQuiz = GameRound;
		RoundQuiz.Number1 = RandomNumberOfQuestion(RoundQuiz);
		RoundQuiz.Number2 = RandomNumberOfQuestion(RoundQuiz);
		RoundQuiz.PrintOnType = ChoiceOnType(RoundQuiz.OnType);
		ShowQuestion(RoundQuiz);
		RoundQuiz.Equals = EqualsOp(RoundQuiz);
		RoundQuiz.ReadAnswer = AnswerFromUser();
		RoundQuiz.CheckOp = CheckAnswer(RoundQuiz);
		FinalAnswer(RoundQuiz);
		SetWinnerScreenColor(RoundQuiz);
		if (RoundQuiz.CheckOp == enAnswer::Right)
			NumberOfRightAnswer++;

		else
			NumberOfWrongAnswer++;

		
	}
	return FillQuizResult(RoundQuiz, NumberOfRightAnswer, NumberOfWrongAnswer);
}



void ShowFinalResultScreen(stQuizResult PassOrFail)
{
	cout << "__________________________________________________________\n\n";
	cout << "                  Final Result is :" << PassOrFail.PassOrFail << endl;
	cout << "__________________________________________________________\n\n";

}

void PrintFinalResult(stQuizResult QuizResult)
{
	cout << "Number of Question: " << QuizResult.NumberOfQuestion << endl;
	cout << "Question Level: " << QuizResult.QuestionLevel << endl;
	cout << "OnType: " << QuizResult.OpType << endl;
	cout << "Number of right answer: " << QuizResult.NumberOfRightAnswer << endl;
	cout << "Number of wrong answer: " << QuizResult.NumberOfWrongAnswer << endl;
}

void ResetScreen()
{
	system("cls");
	system("Color 0F");
}

void StartGame()
{

	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stQuizResult QuizResult = PlayGame(ReadHowManyQuiz());
		ShowFinalResultScreen(QuizResult);
		PrintFinalResult(QuizResult);
		cout << endl << "Do you want to play again? Y/N? ";

		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	StartGame();
	
	return 0;

}