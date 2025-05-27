#include <iostream>
using namespace std;

struct stInfo
{
	int Age;
	bool HasDrivingLicence;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please enter your age?" << endl;
	cin >> Info.Age;

	cout << "Do you have a driver licence?" << endl;
	cin >> Info.HasDrivingLicence;

	cout << "Do you have Recommendation?" << endl;
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (Info.Age > 21 && Info.HasDrivingLicence);
	}


};

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\nHired" << endl;
	else
		cout << "\nRejected" << endl;
}

int main()
{

	PrintResult(ReadInfo());


	return 0;
}