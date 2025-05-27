#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	cout << "Enter Period 1 :\n";
	MyCalendar::sPeriod Period1 = MyCalendar::ReadPeriod();

	cout << "\nEnter Period 2 :\n";
	MyCalendar::sPeriod Period2 = MyCalendar::ReadPeriod();


	if (MyCalendar::IsOverLapPeriods(Period1, Period2))
		cout << "\nYes, Periods Overlap.";
	else
		cout << "\nNo, Periods do NOT Overlap.";

	system("pause>0");
	return 0;

}


