#include <iostream>
#include <string>
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

void PrintPerfectNumbrFrom1ToN(int Number)
{


	for (int Counter = 1; Counter <= Number; Counter++)
	{
		if (isPerfectNumber(Counter))
		{
			cout << Counter << endl;
		}
	}
}

int main()
{
	PrintPerfectNumbrFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));
	return 0;

}