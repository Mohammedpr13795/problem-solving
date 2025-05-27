#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{

	int Matrix1[3][3] = { {44,5,44},{22,75,22},{1,3,1} };



	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix1, 3, 3);


	if (MyMatrix::IsPalindromeNumber(Matrix1, 3, 3))
	{
		cout << "\nYes: Matrix is Palindrome.\n";
	}
	else
	{
		cout << "\nNo: Matrix is NOT Palindrome.\n";
	}

	system("pause>0");

}