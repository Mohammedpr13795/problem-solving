#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
	enPrimeNotPrime PrineNotPrime;

	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)

			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintNumbrtType(int Number)
{
	switch (CheckPrime(Number))
	{
	case enPrimeNotPrime::Prime:
		cout << "The number is prime\n";
		break;
	case enPrimeNotPrime::NotPrime:
		cout << "The number is Not Prime\n";
		break;
	}
}

int main()
{
	PrintNumbrtType(ReadPositiveNumber("Please enter a positive number: "));
	return 0;

}

Problem 38- Prime number (2)

#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
	enPrimeNotPrime PrineNotPrime;

	int Counter = 2;

	if (Number <= Counter)
	{
		return enPrimeNotPrime::Prime;
	}
	else
	{
		for (Counter ; Counter == Number-1 ; Counter++)
		{
			if (Number % Counter == 0)

				return enPrimeNotPrime::NotPrime;
		}
		}
	return enPrimeNotPrime::Prime;


}

void PrintNumbrtType(int Number)
{
	switch (CheckPrime(Number))
	{
	case enPrimeNotPrime::Prime:
		cout << "The number is prime\n";
		break;
	case enPrimeNotPrime::NotPrime:
		cout << "The number is Not Prime\n";
		break;
	}
}

int main()
{
	PrintNumbrtType(ReadPositiveNumber("Please enter a positive number: "));
	return 0;

}


