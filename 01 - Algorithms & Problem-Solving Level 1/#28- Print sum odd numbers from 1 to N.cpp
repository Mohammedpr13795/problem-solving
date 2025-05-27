#include <iostream>

using namespace std;

enum enOddEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please enter a number: " << endl;
	cin >> Number;

	return Number;

}

enOddEven CheckOddEven(int Number)
{
	if (Number % 2 != 0)
		return enOddEven::Odd;
	else
		return enOddEven::Even;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{
	int Sum = 0;

	cout << "Sum odd numbers using for statement:\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddEven(Counter) == enOddEven::Odd)
		{
			Sum += Counter;
		}

	}

	return Sum;

}


int SumOddNumbersFrom1ToN_UsingWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "Sum odd numbers using while statement:\n";


	while (Counter < N)
	{
		Counter++;
		if (CheckOddEven(Counter) == enOddEven::Odd)
		{
			Sum += Counter;
		}
	}

	return Sum;

}


int SumOddNumbersFrom1ToN_UsingDoWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "Sum odd numbers using Do..while statement:\n";

	do
	{
		Counter++;
		if (CheckOddEven(Counter) == enOddEven::Odd)
		{
			Sum += Counter;
		}
	} while (Counter < N);

	return Sum;

}

int main()
{
	int N = ReadNumber();

	cout << SumOddNumbersFrom1ToN_UsingFor(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingWhile(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingDoWhile(N) << endl;

	return 0;
}