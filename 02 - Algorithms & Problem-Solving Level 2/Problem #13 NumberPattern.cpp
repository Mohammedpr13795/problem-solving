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

void PrintNumberPattern(int Number)
{
	cout << "\n";
	for (int Counter = 1; Counter <= Number; Counter++)
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

	PrintNumberPattern(ReadPositiveNumber("Please enter a positive number?"));



	return 0;

}
