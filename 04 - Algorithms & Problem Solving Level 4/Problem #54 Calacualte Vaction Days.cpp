#include <iostream>
#include "MyCalendar.h"
using namespace std;



int main()
{

	MyCalendar::sDate DateFrom;
	MyCalendar::sDate DateTo;
	string NameOfDay = "";

	cout << "Vacation Starts: \n";
	DateFrom = MyCalendar::ReadFullDate();
	NameOfDay = MyCalendar::DayShortName(DayOfWeekOrder(DateFrom));
	
	cout << "\nVacation Ends: \n";
	DateTo = MyCalendar::ReadFullDate();

	
	cout << "\nVacation From " << NameOfDay << " , ";
	cout << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	NameOfDay = MyCalendar::DayShortName(DayOfWeekOrder(DateTo));

	cout << "Vacation To " << NameOfDay << " , ";
	cout << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\nActual Vacation Days is : " 
		<< MyCalendar::CalculateVacationDays(DateFrom, DateTo);

	system("pause>0");
	return 0;

}

