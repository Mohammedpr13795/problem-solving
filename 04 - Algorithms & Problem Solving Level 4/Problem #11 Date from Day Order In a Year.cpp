#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
	sDate Date;


	short RemainingDays = DaysOrderInYear;
	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = MyCalendar::NumberOfDaysInAMonth_ShortLogic(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

int main()
{
	short Day = MyRead::ReadDay();
	short Month = MyRead::ReadMonth();
	short Year = MyRead::ReadYear();
	short DaysOrderInYear = MyCalendar::NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);



	cout << "\nNumber of Days from the beginning of the year is "
		<< DaysOrderInYear << "\n\n";

	sDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
	cout << "Date for [" << DaysOrderInYear << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}

