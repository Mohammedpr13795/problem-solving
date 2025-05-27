#include<iostream>
#include<cstdlib>
#include <string>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
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

void GenerateKeys(short NumberOfKeys)
{
	for (int Counter = 1; Counter <= NumberOfKeys; Counter++)
	{
		cout << "Key [" << Counter << "] : ";
		cout << GenerateKey() << endl;
	}
}

int main()
{
	//Seeds the random number generator in C++, called only once;

	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate? \n "));

	return 0;

}