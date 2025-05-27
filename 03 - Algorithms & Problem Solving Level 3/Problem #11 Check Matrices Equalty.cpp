#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;


int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	MyMatrix::FillMatrixWithRandomFrom1To10Number(Matrix1, 3, 3);
	cout << "\nMatrix1: \n";
	MyMatrix::PrintfMatrix(Matrix1, 3, 3);

	MyMatrix::FillMatrixWithRandomFrom1To10Number(Matrix2, 3, 3);
	cout << "\nMatrix2: \n";
	MyMatrix::PrintfMatrix(Matrix2, 3, 3);


	if (MyMatrix::AreEqualMatrices(Matrix1, Matrix2, 3, 3))
	{
		cout << "\nYes: Both Matrices are equal.";
	}
	else
	{
		cout << "\nNO: Matrices are NOT equal.";
	}


	system("pause>0");


}