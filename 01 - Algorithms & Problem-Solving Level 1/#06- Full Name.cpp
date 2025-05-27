#include <iostream>

using namespace std;

struct StInfo
{
	string FirstName;
	string LastName;
};

StInfo ReadInfo() {

	StInfo Info;

	cout << "Please enter your first name: ";
	cin >> Info.FirstName;
	cout << "Please eneter your last name: ";
	cin >> Info.LastName;

	return Info;
}

string GetFullName(StInfo Info, bool Reversd)
{
	string  FullName = "";

	if (Reversd)
		FullName = Info.LastName + " " + Info.FirstName;
	else
		FullName = Info.FirstName + " " + Info.LastName;


	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "\n Your full name is: " << FullName << endl;



}
int main()
{
	PrintFullName(GetFullName(ReadInfo(), true));


	return 0;
}