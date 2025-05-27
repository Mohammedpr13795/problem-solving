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
	cout << endl;
	short VacationDays = MyCalendar::ReadVacationDays();

	DateTo = MyCalendar::CalculateVacationReturnDate(DateFrom, VacationDays);
	NameOfDay = MyCalendar::DayShortName(DayOfWeekOrder(DateTo));

	cout << "\nReturn date: " << NameOfDay << " , "
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;


	system("pause>0");
	return 0;

}

