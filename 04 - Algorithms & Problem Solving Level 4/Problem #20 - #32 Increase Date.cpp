#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();

	// 01 IncreaseDateByOneDay
	cout << "\nDate After: \n";
	Date = MyCalendar::IncreaseDateByOneDay(Date);
	cout << "\n 01-Adding one Day is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 02 IncreaseDateByXDays
	Date = MyCalendar::IncreaseDateByXDays(10 , Date);
	cout << "\n 02-Adding 10 Days is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 03 IncreaseDateByOneWeek

		Date = MyCalendar::IncreaseDateByOneWeek(Date);
	cout << "\n 03-Adding one Week is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 04 IncreaseDateByXWeeks

	Date = MyCalendar::IncreaseDateByXWeeks(10 ,Date);
	cout << "\n 04-Adding 10 Weeks is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 05 IncreaseDateByOneMonth

	Date = MyCalendar::IncreaseDateByOneMonth(Date);
	cout << "\n 05-Adding one Month is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 06 IncreaseDateByOneMonth

	Date = MyCalendar::IncreaseDateByXMonths(5 , Date);
	cout << "\n 06-Adding 5 Months is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 07 IncreaseDateByOneYear

	Date = MyCalendar::IncreaseDateByOneYear(Date);
	cout << "\n 07-Adding one Year is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 08 IncreaseDateByXYears

	Date = MyCalendar::IncreaseDateByXYears(10 , Date);
	cout << "\n 08-Adding 10 Years is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 09 IncreaseDateByXYearsFaster

	Date = MyCalendar::IncreaseDateByXYearsFaster(10, Date);
	cout << "\n 09-Adding 10 Years (faster) is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 10 IncreaseDateByOneDecade

	Date = MyCalendar::IncreaseDateByOneDecade(Date);
	cout << "\n 10-Adding one Decade is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 11 IncreaseDateByXDecades

	Date = MyCalendar::IncreaseDateByXDecades(10 , Date);
	cout << "\n 11-Adding 10 Decades is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 12 IncreaseDateByXDecadesFaster

	Date = MyCalendar::IncreaseDateByXDecadesFaster(10, Date);
	cout << "\n 12-Adding 10 Decades (faster) is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 13 IncreaseDateByOneCentury

	Date = MyCalendar::IncreaseDateByOneCentury(Date);
	cout << "\n 13-Adding one Century is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 14 IncreaseDateByOneMillennium 

	Date = MyCalendar::IncreaseDateByOneMillennium(Date);
	cout << "\n 14-Adding one Millennium is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}

