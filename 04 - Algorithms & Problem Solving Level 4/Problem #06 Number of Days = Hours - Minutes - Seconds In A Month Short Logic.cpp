#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


short NumberOfDaysInAMonth_ShortLogic(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

	return (Month == 2) ? (MyCalendar::IsLeapYear_OneLine(Year) ? 29 : 28) : NumberOfDays[Month];
}


int main()
{
	short Year = MyRead::ReadYear();
	short Month = MyRead::ReadMonth();
	cout << "\nNumber of Days    in Month [" << Month << "] is "
		<< NumberOfDaysInAMonth_ShortLogic(Month, Year);

	cout << "\nNumber of Hours   in Month [" << Month << "] is "
		<< MyCalendar::NumberOfHoursInAMonth(Month, Year);

	cout << "\nNumber of Minutes in Month [" << Month << "] is "
		<< MyCalendar::NumberOfMinutesInAMonth(Month, Year);

	cout << "\nNumber of Seconds in Month [" << Month << "] is "
		<< MyCalendar::NumberOfSecondsInAMonth(Month, Year);



	system("pause>0");
	return 0;

}

