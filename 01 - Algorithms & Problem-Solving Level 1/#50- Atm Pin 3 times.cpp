#include <iostream>

using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Please enter the Pin Code: \n";
	cin >> PinCode;
	return PinCode;
}

bool Login()
{
	string PinCode;
	int Counter = 3;
	do
	{
		Counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else
		{
			cout << "Wrong Pin, you have " << Counter << " more Tries.\n";
			system("Color 4f");
		}
	} while (Counter >= 1 && PinCode !="1234");

	return 0; // when you reach here means login faild
}

int main()
{
	if (Login())
	{
		system("Color 2f");
		cout << "\nYour account balance is = " << 7500;
	}
	else
	{
		cout << "\n****************\n";
		cout << "Your Card blocked call the bank fir help. \n";
	}

	return 0;
}