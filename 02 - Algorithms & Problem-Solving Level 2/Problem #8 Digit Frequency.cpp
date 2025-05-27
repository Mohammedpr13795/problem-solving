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

int CountDigitFrequency(short CheckDigit,int Number)
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

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number?");
	short DigitToCheck = ReadPositiveNumber("Enter the digit?");
	cout << "\nDigit " << DigitToCheck << " Frequency is "
		 << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";
	return 0;

}