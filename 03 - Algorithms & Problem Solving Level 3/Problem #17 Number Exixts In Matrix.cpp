#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;


int main()
{

	int Matrix[3][3] = { {7 , 5 , 7} , {2 , 6 , 1} , {3 , 2 , 8} };

	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);


	int Number = 0;
	cout << "Please Enter the number to look for matrix: ";
	cin >> Number;

	//Using Count is a slower method 
	if (MyMatrix::CountNumberInMatrix(Matrix, Number, 3, 3) > 0)
	{
		cout << "\nYes: It's There.";
	}
	else
	{
		cout << "\nNo: It's NOT There.";

	}

	//This is faster mthod
	if (MyMatrix::IsNumberInMatrix(Matrix, Number, 3, 3))
	{
		cout << "\nYes: It's There.";
	}
	else
	{
		cout << "\nNo: It's NOT There.";

	}


	system("pause>0");

}