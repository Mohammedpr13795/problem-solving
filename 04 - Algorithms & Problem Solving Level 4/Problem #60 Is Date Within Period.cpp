#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	cout << "Enter Period :\n";
	MyCalendar::sPeriod Period = MyCalendar::ReadPeriod();

	cout << "\nEnter Date to check: \n";
	MyCalendar::sDate Date = MyCalendar::ReadFullDate();

	if (MyCalendar::isDateInPeriod(Date, Period))
		cout << "\nYes, Date is within period.";

	else
		cout << "\nNo, Date is Not within period.";

	

	

	system("pause>0");
	return 0;

}


