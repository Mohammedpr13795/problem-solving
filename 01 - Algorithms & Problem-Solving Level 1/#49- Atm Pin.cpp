#include <iostream>

using namespace std;


string ReadPinCode()
{
	string PinCode;

	cout << "Please enter  PIN code: \n";
	cin >> PinCode;

	return PinCode;

}


bool Login()
{
	string PinCode;
	do
	{
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1; // this will exit the function  and return true login
		}
		else
		{
			cout << "Wrong PIN\n";
			system("Color 4f"); // turn screen to Red
		}
	} while (PinCode != "1234");

	return 0; // when you reach here means login faild


}

int main()
{

	if (Login())
	{
		system("Color 2f"); // turn screen to Green
		cout << "\nYour account balance is " << 7500 << '\n';

	};

	return 0;
}