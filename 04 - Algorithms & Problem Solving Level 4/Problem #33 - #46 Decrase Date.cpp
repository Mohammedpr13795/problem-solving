#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{

	MyCalendar::sDate Date = MyCalendar::ReadFullDate();

	// 01 DecreaseDateByOneDay
	cout << "\nDate After: \n";
	Date = MyCalendar::DecreaseDateByOneDay(Date);
	cout << "\n 01-Subtracting one Day is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 02 DecreaseDateByOneDay
	Date = MyCalendar::DecreaseDateByXDays(10 , Date);
	cout << "\n 02-Subtracting 10 Days is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 03 DecreaseDateByOneWeek

		Date = MyCalendar::DecreaseDateByOneWeek(Date);
	cout << "\n 03-Subtracting one Week is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 04 DecreaseDateByXWeeks 

	Date = MyCalendar::DecreaseDateByXWeeks(10 ,Date);
	cout << "\n 04-Subtracting 10 Weeks is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 05 DecreaseDateByOneMonth

	Date = MyCalendar::DecreaseDateByOneMonth(Date);
	cout << "\n 05-Subtracting one Month is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	//// 06 DecreaseDateByXMonths

	Date = MyCalendar::DecreaseDateByXMonths(5 , Date);
	cout << "\n 06-Subtracting 5 Months is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 07 DecreaseDateByOneYear

	Date = MyCalendar::DecreaseDateByOneYear(Date);
	cout << "\n 07-Subtracting one Year is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 08 DecreaseDateByXYears

	Date = MyCalendar::DecreaseDateByXYears(10 , Date);
	cout << "\n 08-Subtracting 10 Years is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 09 DecreaseDateByXYearsFaster

	Date = MyCalendar::DecreaseDateByXYearsFaster(10, Date);
	cout << "\n 09-Subtracting 10 Years (faster) is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 10 DecreaseDateByOneDecade

	Date = MyCalendar::DecreaseDateByOneDecade(Date);
	cout << "\n 10-Subtracting one Decade is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 11 DecreaseDateByXDecades

	Date = MyCalendar::DecreaseDateByXDecades(10 , Date);
	cout << "\n 11-Subtracting 10 Decades is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 12 DecreaseDateByXDecadesFaster

	Date = MyCalendar::DecreaseDateByXDecadesFaster(10, Date);
	cout << "\n 12-Subtracting 10 Decades (faster) is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 13 DecreaseDateByOneCentury

	Date = MyCalendar::DecreaseDateByOneCentury(Date);
	cout << "\n 13-Subtracting one Century is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	// 14 DecreaseDateByOneMillennium 

	Date = MyCalendar::DecreaseDateByOneMillennium(Date);
	cout << "\n 14-Subtracting one Millennium is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}

