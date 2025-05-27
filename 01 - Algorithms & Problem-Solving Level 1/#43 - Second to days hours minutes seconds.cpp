/*
Problem: Write a program that inputs the number of seconds and change it to
days , hours , minutes , and seconds
*/
#include <iostream>
#include <string>
using namespace std;

struct stTaskDuration{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;

};

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


stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;
	const int SecondPerDay = (24 * 60 * 60); // 86.400
	const int SecondPerHour = (60 * 60); // 3600
	const int SecondPerMinute = 60;


	int Remainder = 0;
	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondPerDay);
	Remainder = TotalSeconds % SecondPerDay;
	TaskDuration.NumberOfHours = floor(Remainder / SecondPerHour);
	Remainder = Remainder % SecondPerHour;
	TaskDuration.NumberOfMinutes = floor(Remainder / SecondPerMinute);
	Remainder = Remainder % SecondPerMinute;
	TaskDuration.NumberOfSeconds = Remainder;

	return TaskDuration;

}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{

	cout << "\n";
	cout << "Number Of days: " << TaskDuration.NumberOfDays << " \n";
	cout << "Number Of Hours: " << TaskDuration.NumberOfHours << " \n";
	cout << "Number Of Minutes: " << TaskDuration.NumberOfMinutes << " \n";
	cout << "Number Of Seconds: " << TaskDuration.NumberOfSeconds << " \n";

	
}											


int main()
{
	int TotalSeconds = ReadPositiveNumber("Please Enter Total Seconds: \n");

	PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));
	 return 0;
}