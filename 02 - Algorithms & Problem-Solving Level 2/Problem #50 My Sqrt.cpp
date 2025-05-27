#include <iostream>

using namespace std;

float ReadNumber()
{
	float Number;


	cout << "Please enter a number: \n";
	cin >> Number;

	return Number;
}



int  MySqrt(float Number)
{


	return pow(Number, 0.5);


		
}


int main()
{
	float Number = ReadNumber();


	cout << "My My Sqrt Result " << MySqrt(Number) << endl;
	cout << "C++ Sqrt Result " << sqrt(Number);



	return 0;
}
