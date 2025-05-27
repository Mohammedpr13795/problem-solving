#include <iostream>
using namespace std;

struct stInfo
{
	int Age;
	bool HasDrivingLicence;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please enter your age?" << endl;
	cin >> Info.Age;

	cout << "Do you have a driver licence?" << endl;
	cin >> Info.HasDrivingLicence;

	return Info;
}

bool IsAccepted(stInfo Info)
{

	return (Info.Age > 21 && Info.HasDrivingLicence);

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