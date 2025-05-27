#include <iostream>

using namespace std;
int ReadAge()
{
	int Age;

	cout << "Pleas enter your age between 18 and 45: ";
	cin >> Age;

	return Age;
}


bool ValidateNumberInRange(int number, int From, int To)
{
	return number >= From && number <= To;

}

int ReadUntilAgeBetwwen(int From, int To)
{
	int Age = 0;
	do
	{
		Age = ReadAge();
	} while (!ValidateNumberInRange(Age, 18, 45));

	return Age;
}

void PrintResult(int Age)
{
	cout << "Your age is: " << Age << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetwwen(18, 45));

	return 0;
}