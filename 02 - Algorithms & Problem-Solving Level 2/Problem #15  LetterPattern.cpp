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

void PrintLetterPattern(int Number)
{

	cout << "\n";
	for (int Counter = 65 ; Counter <= 65 + Number - 1; Counter++)
	{

		for (int j = 1; j <= Counter - 65 + 1; j++)
		{

			cout << char(Counter);

		}

		cout << "\n";
	}


}





int main()
{

	PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));



	return 0;

}
