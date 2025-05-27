// Problem: Write a program to calculate triangle area then print it on the screan.

#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float& A, float& H)
{
	cout << "Please enter A: " << endl;
	cin >> A;

	cout << "Please enrer H: " << endl;
	cin >> H;
}

float TriangleArea(int A, int H)
{
	float Area = (A / 2) * H;
	return Area;
}

void PrintResults(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main() {

	float A, B;


	ReadNumbers(A, B);
	PrintResults(TriangleArea(A, B));

	return 0;

}