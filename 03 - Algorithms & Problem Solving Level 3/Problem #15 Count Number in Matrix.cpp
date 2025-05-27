#include <iostream>
#include <iomanip>
#include "MyMatrix.h"

using namespace std;


int main()
{


	int Matrix[3][3] = { {1 , 5 , 7} , {5 , 1 , 2} , {7 , 2 , 3} };

	cout << "\nMatrix: \n";
	MyMatrix::PrintMatrix(Matrix, 3, 3);

	int Number = 0;
	cout << "Enter the number to count in matrix: ";
	cin >> Number;

	cout << "\nNumber " << Number << " count in matrix is "
		<< MyMatrix::CountNumberInMatrix(Matrix, 3, 3, Number);


	system("pause>0");


}