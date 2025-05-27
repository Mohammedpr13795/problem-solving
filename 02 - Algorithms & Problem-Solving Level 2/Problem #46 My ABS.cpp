#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;

	
	cout << "Please enter a number: \n";
	cin >> Number;

	return Number;
}


int MyABS(float Number)
{
	if (Number > 0)

		return	Number;

	else

		return Number * - 1;
}












int main()
{
	float Number = ReadNumber();
	
	
	cout << "My Abs Result " << MyABS(Number) << endl;
	cout << "C++ Abs Result " << abs(Number);



	return 0;
}
