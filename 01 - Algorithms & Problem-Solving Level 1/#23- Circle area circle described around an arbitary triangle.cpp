/*
Problem: Write a program to calculate circle area circle described
around an arbitary triangle , Then orint it on the screen
*/
#include <iostream>
#include <cmath>
using namespace std;

void ReadTrinalgeleData(float& A, float& B, float& C)
{
	cout << "Please enter trianlge A:" << endl;
	cin >> A;

	cout << "Please enter trianlge B:" << endl;
	cin >> B;

	cout << "Please enter trianlge C:" << endl;
	cin >> C;
}

float CicleAreaByATraingle(float A, float B, float C) {

	const float PI = 3.141592653589793238;
	float P;
	P = (A + B + C) / 2;
	float T;
	T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	float Area = PI * pow(T, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main() {

	float A, B, C;

	ReadTrinalgeleData(A, B, C);
	PrintResult(CicleAreaByATraingle(A, B, C));


	return 0;
}