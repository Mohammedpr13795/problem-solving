#include <iostream>

using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float HoursToDays(float NumberOfHours)
{
	return (float)NumberOfHours / 24;
}

float HoursToWeek(float NumberOfHours)
{
	return (float)NumberOfHours / 24 / 7;
}


float DaysToWeeks(float NumberOfDays)
{
	return (float)NumberOfDays / 7;
}



int main()
{
	float NumberOfHours = ReadPositiveNumber("Please enter Number of Hours: ");
	float NumberOfDays = HoursToDays(NumberOfHours);
	float NumberOfWeek = DaysToWeeks(NumberOfDays);

	cout << endl;
	cout << "Total Hours = " << NumberOfHours << endl;
	cout << "Total Days = " << NumberOfDays << endl;
	cout << "Total Weeks = " << NumberOfWeek << endl; // 1
	cout << "Total Weeks = " << HoursToWeek(NumberOfHours) << endl; // 2

	return 0;
}
