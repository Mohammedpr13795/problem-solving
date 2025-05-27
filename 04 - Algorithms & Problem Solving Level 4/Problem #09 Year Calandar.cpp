#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


void PrintCalendar(short Month, short Year)
{
	// Index of the day from 0 to 6
	short current = MyCalendar::DayOfWeekOrder(1, Month, Year);

	short NumberOfDays =MyCalendar::NumberOfDaysInAMonth_ShortLogic(Month, Year);

	// Print the current month name
	printf("\n  _______________%s_______________\n\n",
	MyCalendar::MonthShortName(Month).c_str());

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

void PrintYearCalendar(short Year)
{
	printf("\n  _________________________________\n\n");
	printf("           Calendar - %d\n", Year);
	printf("  _________________________________\n");

	for (short i = 1; i <= 12; i++)
	{
		PrintCalendar(i, Year);
	}

}

int main()
{
	PrintYearCalendar(MyRead::ReadYear());

	system("pause>0");

	return 0;

}

