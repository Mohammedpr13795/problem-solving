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

int CountDigitFrequency(short CheckDigit, int Number)
{
	int Remainder = 0, FreqCount = 0;



	while (Number > 0)
	{


		Remainder = Number % 10;
		Number /= 10;
		if (CheckDigit == Remainder)
		{
			FreqCount++;
		}

	}
	return FreqCount;
}

void PrintAllDigitsFrequencey(int Number)
{

	for (int Counter = 0; Counter <= 10; Counter++)
	{
		short DigitFrequency = 0;
		DigitFrequency = CountDigitFrequency(Counter, Number);
			if (DigitFrequency > 0)
			{
					cout << "\nDigit " << Counter << " Frequency is "
			<< DigitFrequency << " Time(s).\n";
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number?");
	PrintAllDigitsFrequencey(Number);

	return 0;

}