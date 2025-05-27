#include <iostream>
#include <iomanip>
#include "MyMatrix.h"
using namespace std;

int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int arrSum[3];

	MyMatrix::FillMatrixWithRandomFrom1To100Number(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 random matrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);

	MyMatrix::SumMatrixColsInArray(Matrix, arrSum, 3, 3);
	MyMatrix::PrintColsSumArray(arrSum, 3);

	system("pause>0");


}