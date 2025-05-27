#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a number: " << endl;
	cin >> Number;
	return Number;
}

void PowerOf2_3_4(int Number)
{
	int Pow2, Pow3, Pow4;

	Pow2 = Number * Number;
	Pow3 = Number * Number * Number;
	Pow4 = Number * Number * Number * Number;

	cout << "The power of 2 = " << Pow2 << endl;
	cout << "The power of 3 = " << Pow3 << endl;
	cout << "The power of 4 = " << Pow4 << endl;

}


int main()
{

	PowerOf2_3_4(ReadNumber());



	return 0;
}