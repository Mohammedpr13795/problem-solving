#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


short NumberOfDaysInAYear(short Year)
{
	return MyCalendar::IsLeapYear_OneLine(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
}


int main()
{
	short Year = MyRead::ReadYear();

	cout << "\nNumber of Days    in [" << Year << "] is "
		<< NumberOfDaysInAYear(Year);

	cout << "\nNumber of Hours   in [" << Year << "] is "
		<< NumberOfHoursInAYear(Year);

	cout << "\nNumber of Minutes in [" << Year << "] is "
		<< NumberOfMinutesInAYear(Year);

	cout << "\nNumber of Seconds in [" << Year << "] is "
		<< NumberOfSecondsInAYear(Year);



	system("pause>0");
	return 0;

}