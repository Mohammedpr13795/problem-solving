#include <iostream>
#include "MyRead.h"
#include "MyCalendar.h"
using namespace std;


short ReadDay()
{
	short Day = 0;

	cout << "\nPlease enter a Day: ";
	cin >> Day;
	return Day;
}


short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{

	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += MyCalendar::NumberOfDaysInAMonth_ShortLogic(i, Year);
	}
	TotalDays += Day;

	return TotalDays;

}



int main()
{
	short Day = ReadDay();
	short Month = MyRead::ReadMonth();
	short Year = MyRead::ReadYear();



	cout << "\nNumber of Days from the beginning of the year is "
		<< NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);

	system("pause>0");

	return 0;

}

