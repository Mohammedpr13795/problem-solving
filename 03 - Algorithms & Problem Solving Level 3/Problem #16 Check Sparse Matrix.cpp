#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{


	int Matrix[3][3] = { {0 , 5 , 7} , {0 , 0 , 0} , {0 , 0 , 0} };

	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);



	if (MyMatrix::IsSparseMatrix(Matrix, 3, 3))
	{
		cout << "\nYes: It's sparse.";
	}
	else
	{
		cout << "\nNo: It's NOT sparse.";
	}


	system("pause>0");

}