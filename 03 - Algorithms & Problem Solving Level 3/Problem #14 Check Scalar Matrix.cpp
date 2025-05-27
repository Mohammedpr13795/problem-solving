#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{


	int Matrix[3][3] = { {9, 0 , 0} , {0 , 9 , 0} , {0 , 0 , 9} };

	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);

	if (MyMatrix::IsScalarMatrix(Matrix, 3, 3))
	{
		cout << "\nYes: Matrix is Scalar.";
	}
	else
	{
		cout << "\nNO: Matrix is not Scalar.";
	}


	system("pause>0");


}