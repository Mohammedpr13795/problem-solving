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

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a = 0, y = 0, m = 0;
	a = ((14 - Month) / 12);
	y = Year - a;
	m = Month + (12 * a) - 2;

	//for the Gregorian calendar:
	//// 0:Sun , 1:Mon , 2:Tue , etc....
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


}

string DayShortName(short DayOfWeekOrder)
{

	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];

}



int main()
{
	short Year = MyRead::ReadYear();
	short Month = MyRead::ReadMonth();
	short Day = ReadDay();

	short DayOrder = DayOfWeekOrder(Year, Month, Day);

	cout << "\nData      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOrder;
	cout << "\nDay Name  :" << DayShortName(DayOrder);

	system("pause>0");

	return 0;

}

