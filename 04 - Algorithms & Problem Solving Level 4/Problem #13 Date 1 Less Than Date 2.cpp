#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;

bool IsDate1BeforeDate2(MyCalendar::sDate Date1, MyCalendar::sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{


	MyCalendar::sDate Date1 = MyCalendar::ReadFullDate();
	MyCalendar::sDate Date2 = MyCalendar::ReadFullDate();


	if (MyCalendar::IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is less than Date2";
	}
	else
	{
		cout << "\nNo, Date1 is NOT less than Date2";
	}

	system("pause>0");
	return 0;

}

