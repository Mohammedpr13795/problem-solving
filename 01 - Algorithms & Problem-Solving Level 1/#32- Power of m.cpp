/*
Problem : Write a program to ask the user to enter :
num , m Then  print the number , m
*/
#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter the number: " << endl;
	cin >> Number;
	return Number;

}

int ReadPower()
{
	int M;
	cout << "Please enter the power: " << endl;
	cin >> M;
	return M;
}

int PowerOfM(int M, int Number)
{
	if (M == 0)
	{
		return 1;
	}


	int P = 1;


	for (int Counter = 1; Counter <= M; Counter++)
	{
		P = P * Number;
	}
	return P;
}



int main()
{


	cout << "The result = " << PowerOfM(ReadPower(), ReadNumber());


	return 0;
}

