#include <iostream>
#include "MyCalendar.h"
using namespace std;



int main()
{

	MyCalendar::sDate Date = MyCalendar:: GetSystemDate();
	string NameOfDay = MyCalendar::DayShortName(DayOfWeekOrder(Date));

	// 01 DayOfWeekOrder
	cout << "\nToday is " << NameOfDay << " , ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	// 02 IsEndOfWeek
	cout << "\nIs it end of week? \n";
	if (MyCalendar::IsEndOfWeek(Date))
	{
		cout << "Yes it's " << NameOfDay << ",It's of week.";
	}
	else
	{
		cout << "No it's NOT of week.";
	}

	// 03 IsWeekEnd

	cout << "\n\nIs it Weekend? \n";
	if (MyCalendar::IsWeekEnd(Date))
	{
		cout << "Yes,It's a Week end.";
	}
	else
	{
		cout << "No today is " << NameOfDay << ", NOT a week end.";
	}

	// 04 IsBusinessDay 

	cout << "\n\nIs it Business Day? ";
	if (MyCalendar::IsBusinessDay(Date))
	{
		cout << "\nYes,It's a Business Day.\n";
	}
	else
	{
		cout << "\nNo ,It's NOT a Business Day.\n";
	}


	// 05 DaysUntilTheEndOfWeek

	cout << "\n\nDays until end of week: " <<
		MyCalendar::DaysUntilTheEndOfWeek(Date) << " Day(s)";

	// 06 DaysUntilTheEndOfMonth

	cout << "\n\nDays until end of month: " <<
		MyCalendar::DaysUntilTheEndOfMonth(Date) << " Day(s)";

	// 07 DaysUntilTheEndOfYear

	cout << "\n\nDays until end of year: " <<
		MyCalendar::DaysUntilTheEndOfYear(Date) << " Day(s)";



	system("pause>0");
	return 0;

}

