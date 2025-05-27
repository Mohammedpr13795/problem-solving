/*
Problem: Write a program to calculate circle area insicrbed in a square
then print it on the screan
*/
#include <iostream>
#include <cmath>
using namespace std;

float ReadSquareSide()
{
	float A;

	cout << "Please enter Square Side A: " << endl;
	cin >> A;

	return A;
}

float CircleAreaScribedInSquare(float A) {

	const float PI = 3.141592653589793238;

	float Area = (PI * pow(A, 2)) / 4;

	return Area;
}

void PrintResults(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main() {



	PrintResults(CircleAreaScribedInSquare(ReadSquareSide()));


	return 0;


}