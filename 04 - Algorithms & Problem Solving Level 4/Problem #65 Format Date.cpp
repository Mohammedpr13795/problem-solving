#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	string StringDate = MyRead::ReadStringDate("Please Enter Date dd/mm/yyyy? ");

	MyCalendar::sDate Date = MyCalendar::StringToDate(StringDate);
	cout << endl;

	cout << "\n" << MyCalendar::FormatDate(Date) << "\n";
	cout << "\n" << MyCalendar::FormatDate(Date , "yyyy/dd/mm") << "\n";
	cout << "\n" << MyCalendar::FormatDate(Date , "mm/dd/yyyy") << "\n";
	cout << "\n" << MyCalendar::FormatDate(Date , "mm-dd-yyyy") << "\n";
	cout << "\n" << MyCalendar::FormatDate(Date , "dd-mm-yyyy") << "\n";
	
	cout << "\n" << MyCalendar::FormatDate(Date , "Day:dd , Month:mm , Year:yyyy") << "\n";

	

	system("pause>0");
	return 0;

}


