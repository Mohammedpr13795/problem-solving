#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;

string MonthShortName(short MonthOfYearOrder)
{

	string arrDayNames[13] = { "","Jan","Feb","Mar","Apr","May","Jun"
						,"Jul" , "Aug" , "Sept" , "Oct" , "Nov" , "Dec" };
	return arrDayNames[MonthOfYearOrder];

}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

	return (Month == 2) ? (MyCalendar::IsLeapYear_OneLine(Year) ? 29 : 28) : NumberOfDays[Month];
}

void PrintCalendar(short Month, short Year)
{
	// Index of the day from 0 to 6
	short current = MyCalendar::DayOfWeekOrder(1, Month, Year);

	short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	// Print the current month name
	printf("\n  _______________%s_______________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces
	short i;
	for (i = 0; i < current; i++)
		printf("     ");


	for (short j = 1; j <= NumberOfDays; j++)
	{

		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}

	}

	printf("\n  _________________________________\n");

}



int main()
{
	short Year = MyRead::ReadYear();
	short Month = MyRead::ReadMonth();


	PrintCalendar(Month, Year);




	system("pause>0");

	return 0;

}

