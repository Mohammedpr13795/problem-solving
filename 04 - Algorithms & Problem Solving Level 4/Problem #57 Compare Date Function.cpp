#include <iostream>
#include "MyCalendar.h"
using namespace std;


int main()
{

	cout << "\nEnter Date1:\n";
	MyCalendar::sDate Date1 = MyCalendar::ReadFullDate();
	cout << endl;
	cout << "\nEnter Date2:\n";
	MyCalendar::sDate Date2 = MyCalendar::ReadFullDate();


	cout << "\nCompare Result: " << MyCalendar::CompareDates(Date1, Date2);

	system("pause>0");
	return 0;

}


