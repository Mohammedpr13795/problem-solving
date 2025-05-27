#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;

void SwapDates(MyCalendar::sDate& Date1, MyCalendar::sDate& Date2)
{
	MyCalendar::sDate TempDate;

	TempDate.Day = Date1.Day;
	TempDate.Month = Date1.Month;
	TempDate.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = TempDate.Day;
	Date2.Month = TempDate.Month;
	Date2.Year = TempDate.Year;
}

int main()
{

	MyCalendar::sDate Date1 = MyCalendar::ReadFullDate();
	MyCalendar::sDate Date2 = MyCalendar::ReadFullDate();

	cout << "\nDifference is : "
		<< MyCalendar::GetDifferenceInDays(Date1, Date2) << " Day(s)";


	cout << "\nDifference (Include End Day) is : "
		<< (MyCalendar::GetDifferenceInDays(Date1, Date2, true)) << " Day(s)";

	system("pause>0");
	return 0;

}

