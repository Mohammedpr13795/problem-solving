#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


int GetDifferenceInDays(MyCalendar::sDate Date1, MyCalendar::sDate Date2, bool boolIncludeEndDay = false)
{


	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return boolIncludeEndDay ? ++Days : Days;

}
int main()
{

	MyCalendar::sDate Date1 = MyCalendar:: ReadFullDate();
	MyCalendar::sDate Date2 = MyCalendar:: ReadFullDate();

	cout << "\nDifference is : "
		<< MyCalendar:: GetDifferenceInDays(Date1, Date2) << " Day(s)";




	cout << "\nDifference (Include End Day) is : "
		<< (MyCalendar:: GetDifferenceInDays(Date1, Date2, true)) << " Day(s)";

	system("pause>0");
	return 0;

}

