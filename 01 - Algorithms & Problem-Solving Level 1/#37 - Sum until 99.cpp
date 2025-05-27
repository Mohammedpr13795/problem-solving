#include <iostream>
#include <string>
using namespace std;

float ReadNumber()
{
	int Number = 0;
	cout << "Please enter the number 1: " << endl;
	cin >> Number;
	return Number;

}

float SumNumbers(float Number)
{

	int sum = 0;
	int Counter = 2;

	while (Number != -99)
	{
		sum += Number;

		cout << "Please enter the Number " + to_string(Counter) << ": " << endl;
		cin >> Number;
		Counter++;
	}


	return sum;
}

void PrintResults(float Total)
{
	cout << endl << "Result = " << SumNumbers(Total) << endl;
}

int main()
{
	PrintResults(ReadNumber());

	return 0;

}

Problem 37 - Sum until 99 (2)

#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string Message)
{
	float Number = 0;
	cout << Message << endl;
	cin >> Number;
	return Number;
}

float SumNumbers()
{

	int Number = 0, Sum = 0, Counter = 1;


	do
	{
		Number = ReadNumber("Please enter Number " + to_string(Counter));

		if (Number == -99)
		{
			break;
		}
		Sum += Number;
		Counter++;
	} while (Number != -99);


	return Sum;

}




int main()
{
	cout << endl << "Result = " << SumNumbers() << endl;
	return 0;

}



