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

void PrintInvertedLetterPattern(int Number)
{

	cout << "\n";
	for (int Counter = 65 + Number - 1; Counter >= 65; Counter--)
	{
		
		for (int j = 1; j <= Number - (65 + Number - 1 - Counter); j++)
		{
			
			 cout << char(Counter);
			 
		}

		cout << "\n";
	}


}





int main()
{

	PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));



	return 0;

}
