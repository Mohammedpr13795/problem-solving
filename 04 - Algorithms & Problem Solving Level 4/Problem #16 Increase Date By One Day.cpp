#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


bool IsLastDaysInMonth(MyCalendar::sDate Date)
{
	return (Date.Day == MyCalendar::NumberOfDaysInAMonth_ShortLogic(Date.Month, Date.Year));
}

MyCalendar::sDate IncreaseDateByOneDay(MyCalendar::sDate Date)
{

	if (MyCalendar::IsLastDaysInMonth(Date))
	{
		if (MyCalendar::IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}

	}
	else
	{
		Date.Day++;
	}

	return Date;
}

int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();
	Date = MyCalendar::IncreaseDateByOneDay(Date);

	cout << "\nDay after adding one day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}

