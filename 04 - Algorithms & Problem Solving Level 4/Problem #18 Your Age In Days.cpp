#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;

#pragma warning(disable : 4996)

MyCalendar::sDate GetSystemDate()
{
	MyCalendar::sDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}


int main()
{
	

	cout << "\nPlease Enter Your Date of Birth:\n";
	MyCalendar::sDate Date1 = MyCalendar::ReadFullDate();

	MyCalendar::sDate Date2 = GetSystemDate();

	cout << "\nYour age is: "
		<< MyCalendar::GetDifferenceInDays(Date1, Date2, true) << " Day(s)";


	system("pause>0");
	return 0;

}

