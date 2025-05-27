/*
Problem : Write a program to caclulate circle area then
print it on the screen
*/
#include <iostream>
#include <cmath>
using namespace std;

float ReadRedious()
{
	float R;

	cout << "Please enter redious R: " << endl;
	cin >> R;

	return R;
}

float CircleArea(float R) {

	float const PI = 3.141592653589793238;

	float Area = pow(R, 2) * PI;
	return  Area;
}

void PrintResults(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main() {



	PrintResults(CircleArea(ReadRedious()));

	return 0;
}