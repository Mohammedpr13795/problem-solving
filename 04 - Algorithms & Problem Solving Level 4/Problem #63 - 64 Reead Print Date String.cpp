#include <iostream>
#include "MyCalendar.h"
#include "MyRead.h"
using namespace std;

int main()
{

	string StringDate = MyRead::ReadStringDate("Please Enter Date dd/mm/yyyy? ");

	MyCalendar::sDate Date = MyCalendar::StringToDate(StringDate);
	cout << endl;

	cout << "Day: " << Date.Day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year: " << Date.Year << endl;

	cout << "\nYou Entered: " << MyCalendar::DateToString(Date);

	system("pause>0");
	return 0;

}


