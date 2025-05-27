#include <iostream>
#include <string>
#include "MyRead.h"
using namespace std;


bool IsLeapYear_OneLine(short Year)
{
	// If the year is divisible by 4 and not divisible by 100
	// OR if the year is divisible by 400
	// then it is considered a leap year

	return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

int main()
{
	short Year = MyRead::ReadYear();

	if (IsLeapYear_OneLine(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else
	{
		cout << "\nNo, Year [" << Year << "] is  NOT a leap year.\n";
	}

	system("pause>0");
	return 0;


}