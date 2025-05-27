#include <iostream>

using namespace std;

int SumOf3Number(int num[3])
{
	return num[0] + num[1] + num[2];
}

int ReadNumber()
{
	int num[3];

	cout << "Please enter a first number: " << endl;
	cin >> num[0];
	cout << "Please enter a second number: " << endl;
	cin >> num[1];
	cout << "Please enter a third number: " << endl;
	cin >> num[2];

	return SumOf3Number(num);
}



void PrintResults(int Total)
{
	cout << "\nThe sum of 3 numbers are = " << Total << endl;
}
int main()
{

	PrintResults(ReadNumber());

	return 0;
}