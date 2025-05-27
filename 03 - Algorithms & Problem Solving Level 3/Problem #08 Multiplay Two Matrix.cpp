#include <iostream>
#include <iomanip>
#include "MyMatrix.h"
using namespace std;

int main()
{


	int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

	MyMatrix::FillMatrixWithOrderNumber(Matrix1, 3, 3);
	cout << "\nMatrix1: \n";
	MyMatrix::PrintfMatrix(Matrix1, 3, 3);

	MyMatrix::FillMatrixWithOrderNumber(Matrix2, 3, 3);
	cout << "\nMatrix2: \n";
	MyMatrix::PrintfMatrix(Matrix2, 3, 3);


	MyMatrix::MultiplyMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);

	cout << "\nResults: \n";
	MyMatrix::PrintfMatrix(MatrixResult, 3, 3);

	system("pause>0");

}