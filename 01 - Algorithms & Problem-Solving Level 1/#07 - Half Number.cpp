#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a number: " << endl;
	cin >> Number;
	return Number;
}

float CalculateHalfNumber(int Number)
{
	return (float)Number / 2;
}

void PrintResult(int number)
{

	string Result = "Half of " + to_string(number) + " is " + to_string(CalculateHalfNumber(number));
	cout << Result << endl;
}

int main()
{
	PrintResult(ReadNumber());





	return 0;




}