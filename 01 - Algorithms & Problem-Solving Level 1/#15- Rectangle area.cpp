// Problem: Write a program to calculate rectangle area and print it on the screan

#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float& num1, float& num2)
{
	cout << "Please enter a first number: " << endl;
	cin >> num1;

	cout << "Please enter a second number: " << endl;
	cin >> num2;
}

float CalculateRectangleArea(float A, float B) {

	return A * B;
}

void PrintResults(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;

}

int main() {

	float A, B;

	ReadNumbers(A, B);
	PrintResults(CalculateRectangleArea(A, B));


	return 0;

}