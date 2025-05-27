#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;



short ReadDaysToAdd()
{
	short NewDate = 0;

	cout << "\nHow many days to add: ";
	cin >> NewDate;
	return NewDate;
}


int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();
	short Days = ReadDaysToAdd();
	Date = MyCalendar::DateAddDays(Days, Date);
	cout << "\nDate after adding [" << Days << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}

