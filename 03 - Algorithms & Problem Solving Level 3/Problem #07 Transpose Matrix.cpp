#include <iostream>
#include <iomanip>
#include "MyMatrix.h"
using namespace std;

int main()
{


	int Matrix[3][3], arrTransposed[3][3];

	MyMatrix::FillMatrixWithOrderNumber(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);

	MyMatrix::TransposeMatrix(Matrix, arrTransposed, 3, 3);

	cout << "\nThe following is the transposed matrix: \n";
	MyMatrix::PrintMatrix(arrTransposed, 3, 3);
	system("pause>0");


}