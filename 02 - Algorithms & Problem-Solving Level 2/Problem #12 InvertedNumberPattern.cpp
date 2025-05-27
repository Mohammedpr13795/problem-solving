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

void PrintInvertedNumberPattern(int Number)
{
	cout << "\n";
	for (int Counter = Number; Counter >= 1; Counter--)
	{
		
		for (int j = 1; j <= Counter; j++)
		{
			cout << Counter;
		}
		cout << "\n";
	}
	cout << endl;

}





int main()
{

	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number?"));



	return 0;

}
