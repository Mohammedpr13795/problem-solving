#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;

int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	MyMatrix::FillMatrixWithRandomFrom1To10Number(Matrix, 3, 3);


	cout << "\nMatrix: \n";
	MyMatrix::PrintfMatrix(Matrix, 3, 3);

	cout << "\nSum of Matrix1 is: " << MyMatrix::SumOfMatrix(Matrix, 3, 3);
	system("pause>0");


}