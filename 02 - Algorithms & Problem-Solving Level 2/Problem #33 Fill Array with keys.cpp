#include<iostream>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}


char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
		break;
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;
	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;
	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;
	}

}

string GenerateWord(enCharType CharType, short Length)
{
	string Word;

	for (int Counter = 1; Counter <= Length; Counter++)
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}



string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}


int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{



	for (int Counter = 0; Counter < arrLength; Counter++)
	{

		arr[Counter] = GenerateKey();

	}
	cout << endl;
}

void PrintStringArray(string arr[100], int arrLength)
{
	cout << "\nArray elements:\n\n";
	for (int Counter = 0; Counter < arrLength; Counter++)
	{
		cout << "Array [" << Counter << "] : ";
		cout << arr[Counter] << "\n";
	}
	cout << "\n";
}




int main()
{
	//Seeds the random number generator in C++, called only once;

	srand((unsigned)time(NULL));


	string arr[100];
	int arrLength = ReadPositiveNumber("How many keys do you want to generate?\n");

	FillArrayWithKeys(arr, arrLength);


	PrintStringArray(arr, arrLength);

	return 0;

}