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

	for (int Counter = 1; Counter <= N; Counter++)
	{

		cout << Counter << endl;
	}

	cout << "----------------------" << endl << endl;

}


void PrintRangeFrom1ToN_UsingWhile(int N)
{
	int Counter = 0;

	cout << "Range printed using while statement: : \n";


	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}
	cout << "----------------------" << endl << endl;

}


void PrintRangeFrom1ToN_UsingDoWhile(int N)
{
	int Counter = 0;

	cout << "Range printed using Do.while statement: : \n";

	do
	{
		Counter++;
		cout << Counter << endl;
	} while (Counter < N);
	cout << "----------------------" << endl << endl;

}


int main()
{
	int N = ReadNumber();

	PrintRangeFrom1ToN_UsingFor(N);
	PrintRangeFrom1ToN_UsingWhile(N);
	PrintRangeFrom1ToN_UsingDoWhile(N);

	return 0;


}