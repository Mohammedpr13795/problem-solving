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


	if (MyCalendar::IsDate1AfterDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is After than Date2";
	}
	else
	{
		cout << "\nNo, Date1 is NOT After than Date2";
	}

	system("pause>0");
	return 0;

}


