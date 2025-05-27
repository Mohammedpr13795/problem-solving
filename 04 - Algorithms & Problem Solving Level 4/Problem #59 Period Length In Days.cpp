#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	cout << "Enter Period 1 :\n";
	MyCalendar::sPeriod Period1 = MyCalendar::ReadPeriod();

	cout << "\nPeriod Length is: " << MyCalendar::PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Date) is: " << MyCalendar::PeriodLengthInDays(Period1 ,true);

	system("pause>0");
	return 0;

}


