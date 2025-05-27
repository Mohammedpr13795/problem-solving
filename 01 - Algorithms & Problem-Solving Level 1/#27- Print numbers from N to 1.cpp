#include <iostream>

using namespace std;

int ReadNumber()
{
	int N;

	cout << "Please enter the number: " << endl;
	cin >> N;
	return N;

}

void PrintRangeFrom1ToN_UsingFor(int N)
{

	cout << "Range printed using for statement: : \n";

	for (int Counter = N; Counter >= 1; Counter--)
	{

		cout << Counter << endl;
	}

	cout << "----------------------" << endl << endl;

}


void PrintRangeFrom1ToN_UsingWhile(int N)
{
	int Counter = N + 1;

	cout << "Range printed using while statement: : \n";


	while (Counter > 1)
	{
		Counter--;
		cout << Counter << endl;
	}
	cout << "----------------------" << endl << endl;

}


void PrintRangeFrom1ToN_UsingDoWhile(int N)
{
	int Counter = N + 1;

	cout << "Range printed using Do.while statement: : \n";

	do
	{
		Counter--;
		cout << Counter << endl;
	} while (Counter > 1);
	cout << "----------------------" << endl << endl;

}


int main()
{
	int N = ReadNumber();

	PrintRangeFromNTo1_UsingFor(N);
	PrintRangeFromNTo1_UsingWhile(N);
	PrintRangeFromNTo1_UsingDoWhile(N);

	return 0;


}