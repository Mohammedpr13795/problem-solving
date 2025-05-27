/*
Problem: Write a program to calculate rectangle area through diagonal and side area
of rectangle and print it on the screen
*/
#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float& A, float& D)
{
	cout << "Please enter A: " << endl;
	cin >> A;

	cout << "Please enrer D: " << endl;
	cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
float Area = A * sqrt(pow(D, 2) - pow(A, 2));
return Area;

}

void PrintResults(float Area)
{
	cout << "\nrectangle Area = " << Area << endl;

}
int main() {

	float A, D;

	ReadNumbers(A, D);
	PrintResults(RectangleAreaBySideAndDiagonal(A, D));


	return 0;
}