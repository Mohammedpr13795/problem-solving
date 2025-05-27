#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{

	int Matrix1[3][3] = { {44,5,12},{22,75,1},{1,3,9} };


	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix1, 3, 3);


	cout << "\nMinimum Number is: ";
	cout << MyMatrix::MinNumberInMatrix(Matrix1, 3, 3);

	cout << "\nMax Number is: ";
	cout << MyMatrix::MaxNumberInMatrix(Matrix1, 3, 3);

	system("pause>0");

}