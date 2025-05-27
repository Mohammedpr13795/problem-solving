#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();


	if (MyCalendar::IsLastDaysInMonth(Date))
	{
		cout << "\nYes,Day is Last Day in Month.";
	}
	else
	{
		cout << "\nNo,Day is Not Last Day in Month.";
	}

	if (MyCalendar::IsLastMonthInYear(Date.Month))
	{
		cout << "\nYes,Month is Last Month in Year.";
	}
	else
	{
		cout << "\nNo,Month is Not Last Month in Year.";
	}

	system("pause>0");
	return 0;

}