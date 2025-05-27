#include <iostream>
#include <string>
using namespace std;

enum enReadMonthOfYear{January=1,February=2,March=3,April=4,May=5,June=6,
		  July=7,August=8,September=9,October=10,November=11,December=12};

void ShowMonthsYears()
{

	cout << "************************" << endl;
	cout << "       Months year        " << endl;
	cout << "************************" << endl;

	cout << "(1)January\n";
	cout << "(2)February\n";
	cout << "(3)March\n";
	cout << "(4)April\n";
	cout << "(5)May\n";
	cout << "(6)June\n";
	cout << "(7)July\n";
	cout << "(8)August\n";
	cout << "(9)September\n";
	cout << "(10)October\n";
	cout << "(11)November\n";
	cout << "(12)December\n";
	cout << "***********\n";


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


enReadMonthOfYear ReadMonthOfYear()
{
	
	return (enReadMonthOfYear)ReadNumberInRange("Please Enter The Month Between[1 To 12]\n", 1, 12);
}



string GetWMonthOfYear(enReadMonthOfYear MonthOfYear)
{
	switch (MonthOfYear)
	{
	case enReadMonthOfYear::January:
		return "January.";
	case enReadMonthOfYear::February:
		return "February.";
	case enReadMonthOfYear::March:
		return "March." ;
	case enReadMonthOfYear::April:
		return "April.";
	case enReadMonthOfYear::May:
		return "May.";
	case enReadMonthOfYear::June:
		return "June.";
	case enReadMonthOfYear::July:
		return "July.";
	case enReadMonthOfYear::August:
		return "August.";
		break;
	case enReadMonthOfYear::September:
		return "September.";
	case enReadMonthOfYear::October:
		return "October.";
	case enReadMonthOfYear::November:
		return "November.";

	case enReadMonthOfYear::December:
		return "December.";
	default:
		return "Not a valid Month.";
	}

}


int main()
{
	


	ShowMonthsYears();

	cout << "The month is: " << GetWMonthOfYear(ReadMonthOfYear()) << endl;

	return 0;
}

Problem 45 - Month of year (2)

#include <iostream>

using namespace std;

void ShowMonthsYears()
{

	cout << "************************" << endl;
	cout << "       Months year        " << endl;
	cout << "************************" << endl;

	cout << "(1)January\n";
	cout << "(2)February\n";
	cout << "(3)March\n";
	cout << "(4)April\n";
	cout << "(5)May\n";
	cout << "(6)June\n";
	cout << "(7)July\n";
	cout << "(8)August\n";
	cout << "(9)September\n";
	cout << "(10)October\n";
	cout << "(11)November\n";
	cout << "(12)December\n";
	cout << "***********\n";


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


int ReadMonthOfYear()
{

	return ReadNumberInRange("Please Enter The Month Between(1 To 12)\n", 1, 12);
}


void GetWMonthOfYear(int MonthOfYear)
{
	if (MonthOfYear >= 1 && MonthOfYear <= 12)
	{

		if (MonthOfYear == 1)
		{
			cout << "The month is: January." << endl;


		}
		else if (MonthOfYear == 2)
		{
			cout << "The month is: February." << endl;
		}

		else if (MonthOfYear == 3)
		{
			cout << "The month is: March." << endl;
		}

		else if (MonthOfYear == 4)
		{
			cout << "The month is: April." << endl;
		}

		else if (MonthOfYear == 5)
		{
			cout << "The month is: May." << endl;
		}

		else if (MonthOfYear == 6)
		{
			cout << "The month is: June." << endl;
		}

		else if (MonthOfYear == 7)
		{
			cout << "The month is: July." << endl;
		}

		else if (MonthOfYear == 8)
		{
			cout << "The month is: August." << endl;
		}

		else if (MonthOfYear == 9)
		{
			cout << "The month is: September." << endl;
		}

		else if (MonthOfYear == 10)
		{
			cout << "The month is: October." << endl;
		}

		else if (MonthOfYear == 11)
		{
			cout << "The month is: November." << endl;
		}

		else if (MonthOfYear == 12)
		{
			cout << "The month is: December." << endl;
		}

	}

	else {
		cout << "Not a valid Month." << endl;
	}
	

}


int main()
{


	ShowMonthsYears();

	GetWMonthOfYear(ReadMonthOfYear());

	return 0;
}



