#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

void PrintPrimeNumbrFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Prime Numbers from " << 1 << " To " << Number;
	cout << " are : " << endl;
	for (int Counter = 1; Counter <= Number; Counter++)
	{
		if (CheckPrime(Counter) == enPrimeNotPrime::Prime)
		{
			cout << Counter << endl;
		}
	}
}

int main()
{
	PrintPrimeNumbrFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));
	return 0;

}