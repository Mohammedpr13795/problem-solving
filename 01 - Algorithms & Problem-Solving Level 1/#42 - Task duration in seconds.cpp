/*
Problem: Write a program to calculate the task duration in seconds and
ptint it on the screen
*/
#include <iostream>
#include <string>

using namespace std;

struct stTaskDuration {
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;

};

int ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;

	TaskDuration.NumberOfDays = ReadPositiveNumber("Please enter Number Of Days: \n");
	TaskDuration.NumberOfHours = ReadPositiveNumber("Please enter Number Of Hours: \n");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please enter Number Of Minutes: \n");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please enter Number Of Seconds: \n");

	return TaskDuration;
}

int TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	int DurationInSeconds = 0;

	DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;

	return DurationInSeconds;

}


int main()
{

	cout << "\n Task Duration In Seconds = " << TaskDurationInSeconds(ReadTaskDuration());
	cout << endl;


	return 0;


}