#include <iostream>

using namespace std;

float ReadNumber()
{
	float Number;

	
	cout << "Please enter a number: \n";
	cin >> Number;

	return Number;
}



int MyFloor(float Number)
{


		if (Number > 0)

			return int(Number);

		else

			return int(Number) - 1;
	


}


int main()
{
	float Number = ReadNumber();
	
	
	cout << "My FloorResult " << MyFloor(Number) << endl;
	cout << "C++ Floor Result " << floor(Number);



	return 0;
}
