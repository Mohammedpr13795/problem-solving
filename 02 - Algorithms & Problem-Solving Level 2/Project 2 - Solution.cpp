#include <iostream>

using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, MixLevel = 4 };
enum enOpertionType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOpertionType OpertionType;
	enQuestionLevel QuestionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestion = 0;
	enQuestionLevel QuestionLevel;
	enOpertionType OpType;
	short NumberOfWrongAnswer = 0;
	short NumberOfRightAnser = 0;
	bool isPass = false;
};

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

short ReadHowManyQuestion()
{
	short NumberOfQuestion = 0;

	do
	{
		cout << "How Many Question do you want to answer ? ";
		cin >> NumberOfQuestion;
	} while (NumberOfQuestion < 1 || NumberOfQuestion > 100);

	return NumberOfQuestion;
}

enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;

	do
	{
		cout << "Enter Question Level [1] Easy , [2] Med , [3] Hard , [4] Mix ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionLevel)QuestionLevel;
}

enOpertionType ReadOpType()
{
	short OpType = 0;

	do
	{
		cout << "Enter Opertion Type [1] Add , [2] Sub , [3] Mul , [4] Div , [5] Mix ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);
	return (enOpertionType)OpType;
}

enOpertionType GetRandomOperationType()
{
	short Op = RandomNumber(1, 4);
	return (enOpertionType)Op;
}

int  SimpleCalculator(int Number1, int Number2, enOpertionType OpType)
{
	switch (OpType)
	{
	case enOpertionType::Add:
		return Number1 + Number2;
	case enOpertionType::Sub:
		return Number1 - Number2;
	case enOpertionType::Mult:
		return Number1 * Number2;
	case enOpertionType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpertionType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::MixLevel)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}
	if (OpType == enOpertionType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OpertionType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertionType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertionType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpertionType);
		Question.QuestionLevel = QuestionLevel;

		return Question;

	}
	return Question;
}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);
	}
}

string GetOpTypeSymbol(enOpertionType OpType)
{
	switch (OpType)
	{
	case enOpertionType::Add:
		return "+";
	case enOpertionType::Sub:
		return "-";
	case enOpertionType::Mult:
		return "*";
	case enOpertionType::Div:
		return "/";
	default:
		return "Mix";
	}
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OpertionType);
	cout << "\n_________" << endl;
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("Color 2F"); // turb screen to Green
	else
	{
		system("Color 4F"); // turn screen to Red
		cout << '\a';
	}
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswer++;

		cout << "Wrong Answer :( \n";
		cout << "The Right Answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnser++;

		cout << "Right Amswer :) \n";

	}
	cout << endl;

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}
	Quizz.isPass = (Quizz.NumberOfRightAnser >= Quizz.NumberOfWrongAnswer);
}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "PASS :)";
	else
		return "FAIL :(";
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevel[4] = { "Easy" , "Med" , "Hard" , "Mix" };
	return arrQuestionLevel[QuestionLevel - 1];
}

void PrintQuizzResult(stQuizz Quizz)
{
	cout << "\n";
	cout << "______________________________\n\n";

	cout << " Final Result is " << GetFinalResultsText(Quizz.isPass);
	cout << "\n______________________________\n\n";
	cout << "Number of Question: " << Quizz.NumberOfQuestion << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuestionLevel) << endl;
	cout << "OpType             : " << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnser << endl;
	cout << "Number of Wrong Anserts: " << Quizz.NumberOfWrongAnswer << endl;
	cout << "______________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestion = ReadHowManyQuestion();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOpType();

	GenerateQuizzQuestion(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResult(Quizz);

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
		PlayMathGame();

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