#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{


	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "\nMatrix1: \n";
	MyMatrix::PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2: \n";
	MyMatrix::PrintMatrix(Matrix2, 3, 3);



	cout << "Intersected Number are: \n";
	MyMatrix::PrintIntersectedNumber(Matrix1, Matrix2, 3, 3);


	system("pause>0");

}