/*
Problem: Write a program to calculate circle area inscribed in an isoscles traingle
then print it on the screen
*/
#include <iostream>
#include <cmath>
using namespace std;

void ReadTriagleData(float& A, float& B)
{
	cout << "Please enter A: " << endl;
	cin >> A;

	cout << "Please enter B: ";
	cin >> B;
}

float CircleAreaByITriangle(float A, float B) {

	const float PI = 3.141592653589793238;
	float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main() {

	float A, B;

	ReadTriagleData(A, B);
	PrintResult(CircleAreaByITriangle(A, B));

	return 0;
}