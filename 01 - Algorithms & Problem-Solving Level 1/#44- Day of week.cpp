#include <iostream>
#include <string>
using namespace std;

enum enDayOfWeek { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };

void ShowWeekDayMenue()
{
	cout << "************************" << endl;
	cout << "       Week Days        " << endl;
	cout << "************************" << endl;
	cout << "1: Sunday" << endl;
	cout << "2: Monday" << endl;
	cout << "3: Tuesday" << endl;
	cout << "4: Wednesday" << endl;
	cout << "5: Thursday" << endl;
	cout << "6: Friday" << endl;
	cout << "7: Saturday" << endl;
	cout << "************************" << endl;

}

int ReadNumberInRange(string Message, int From, int To)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < From || Number > To);

	return Number;
}


enDayOfWeek ReadWDayOfweekDay()
{
	return (enDayOfWeek)ReadNumberInRange("Please enter the number of day between (1 To 7): \n", 1, 7);



}

string GetWeekDayName(enDayOfWeek Day)
{

	switch (Day)
	{
	case enDayOfWeek::Sun:
		return "Sunday";
	case enDayOfWeek::Mon:
		return "Monday";
	case enDayOfWeek::Tue:
		return "Tuesday";
	case enDayOfWeek::Wed:
		return "Wednesday";
	case enDayOfWeek::Thu:
		return "Thursday";
	case enDayOfWeek::Fri:
		return "Friday";
	case enDayOfWeek::Sat:
		return "Saturday";
	default:
		return "Not a valid day\n";
	}
}

int main()
{



	ShowWeekDayMenue();

	cout << "Today is: " << GetWeekDayName(ReadWDayOfweekDay()) << endl;

	return 0;

}

Problem 44- Day of week (2)

#include <iostream>
#include <string>
using namespace std;

void ShowWeekDayMenue()
{
	cout << "************************" << endl;
	cout << "       Week Days        " << endl;
	cout << "************************" << endl;
	cout << "1: Sunday" << endl;
	cout << "2: Monday" << endl;
	cout << "3: Tuesday" << endl;
	cout << "4: Wednesday" << endl;
	cout << "5: Thursday" << endl;
	cout << "6: Friday" << endl;
	cout << "7: Saturday" << endl;
	cout << "************************" << endl;

}

int ReadNumberInRange(string Message, int From, int To)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < From || Number > To);

	return Number;
}


int ReadNumberOfDay()
{
	 return ReadNumberInRange("Please enter the number of day between (1 To 7): \n", 1 , 7);

}


void GetWeekDayName(int Day)
{
	if (Day >= 1 && Day <= 7)
	{
		if (Day == 1)
		{
			cout << "It.s Sunday." << endl;
		}

		else if (Day == 2)
		{
			cout << "It.s Monday." << endl;
		}

		else if (Day == 3)
		{
			cout << "It.s Tuesday." << endl;
		}

		else if (Day == 4)
		{
			cout << "It.s Wednesday." << endl;
		}

		else if (Day == 5)
		{
			cout << "It.s Thursday." << endl;
		}

		else if (Day == 6)
		{
			cout << "It.s Friday." << endl;
		}

		else if (Day == 7)
		{
			cout << "It.s Saturday." << endl;
		}

		else {
			cout << "Not a valid day." << endl;
		}

	}
}
int main()
{

	ShowWeekDayMenue();

	GetWeekDayName(ReadNumberOfDay());

	return 0;
}




