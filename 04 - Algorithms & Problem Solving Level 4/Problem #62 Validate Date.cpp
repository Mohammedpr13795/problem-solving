#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();

	if (MyCalendar::IsValidDate(Date))
		cout << "\nYes, Date is a valid date.";

	else
		cout << "\nNo, Date is NOT a valid Date.";

	system("pause>0");
	return 0;

}


