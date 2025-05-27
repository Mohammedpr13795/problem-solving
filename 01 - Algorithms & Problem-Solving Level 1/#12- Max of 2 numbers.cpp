#include <iostream>

using namespace std;

int MaxOf2Numbers(int num[2])
{


	if (num[0] > num[1])
		return num[0];
	else
		return num[1];

}

int ReadNubmer()
{
	int number[2];

	cout << "Please enter a first number: " << endl;
	cin >> number[0];

	cout << "Please enter a second number: " << endl;
	cin >> number[1];

	return MaxOf2Numbers(number);
}



void PrintResult(int Max)
{

	cout << "\n The maximum is: " << Max << endl;

}
int main()
{

	PrintResult(ReadNubmer());

	return 0;
}