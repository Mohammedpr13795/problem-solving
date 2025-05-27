#include <iostream>

using namespace std;


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

bool isPerfectNumber(int Number)
{
	int Sum = 0;
	for (int Counter = 1; Counter < Number; Counter++)
	{
		if (Number % Counter == 0)

			Sum += Counter;
	}
	return Number == Sum;

}

void PrintPerfectNumber(int Number)
{


	if (isPerfectNumber(Number))
		cout << Number << " Is perfect Number. \n";
	else
		cout << Number << " Is Not Perfect Number. \n";

}

int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number: "));

	return 0;
}