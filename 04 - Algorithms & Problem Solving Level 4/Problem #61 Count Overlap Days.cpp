#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	cout << "Enter Period 1 :\n";
	MyCalendar::sPeriod Period1 = MyCalendar::ReadPeriod();

	cout << "\nEnter Period 2 :\n";
	MyCalendar::sPeriod Period2 = MyCalendar::ReadPeriod();


	cout << "\nOverLap Days Count: " << MyCalendar::CountOverLapDays(Period1, Period2);

	system("pause>0");
	return 0;

}


