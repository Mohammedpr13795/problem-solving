#include <iostream>

using namespace std;

int ReadPositveNumber(string Message)
{
	int N;
	do
	{
		cout << Message;
		cin >> N;
	} while (N < 0);

	return N;
}

int FactorialFor(int N)
{
	int Factorial = 1;

	cout << "The factorial of using for statement:\n";

	for (int Counter = N; Counter >= 1; Counter--)
	{
		Factorial *=Counter;
	}
	return Factorial;
}

int FactorialWhile(int N)
{
	int Factorial = 1;
	int Counter = N + 1;
	cout << "The factorial of using While statement:\n";

	while ( Counter > 1)
	{
		Counter--;
		Factorial *= Counter;
	}
	return Factorial;
}

int FactorialDoWhile(int N)
{
	int Factorial = 1;
	int Counter = N + 1;
	cout << "The factorial of using do...While statement:\n";

	do
	{
		Counter--;
		Factorial *= Counter;
	} while (Counter > 1);

	return Factorial;
}

int main()
{
	cout << FactorialFor(ReadPositveNumber("Please enter the positve eneter: \n")) << endl;
	cout << FactorialWhile(ReadPositveNumber("Please enter the positve eneter: \n")) << endl;
	cout << FactorialDoWhile(ReadPositveNumber("Please enter the positve eneter: \n")) << endl;

	return 0;
}