/*
Problem: Write a program to calculate circle area along the circufernce
then print it on the screan
*/
#include <iostream>
#include <cmath>
using namespace std;

float ReadCircumference()
{
	float L;
	cout << "Please eneter the Circumference L: " << endl;
	cin >> L;
	return L;
}


float CircleAreaByCircumference(int L) {

	const float PI = 3.141592653589793238;

	float Area = pow(L, 2) / (4 * PI);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main() {



	PrintResult(CircleAreaByCircumference(ReadCircumference()));

	return 0;


}