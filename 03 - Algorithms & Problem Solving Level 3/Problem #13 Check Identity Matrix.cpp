#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{

	int Matrix[3][3] = { {1, 0 , 0} , {0 , 1 , 0} , {0 , 0 , 1} };
	//int Matrix[3][3] = { {1 , 2 , 3} , {4 , 5 , 6} , {7 , 8 , 9} };

	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);

	if (MyMatrix::IsIdentityMatrix(Matrix, 3, 3))
	{
		cout << "\nYes: Matrix is identity.";
	}
	else
	{
		cout << "\nNO: Matrix is not identity.";
	}


	system("pause>0");


}