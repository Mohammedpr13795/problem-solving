#include <iostream>

using namespace std;

int SumOf3Numbers(int mark[3])
{
	return mark[0] + mark[1] + mark[2];
}

float CalculateAverage(int mark[3])
{
	return (float)SumOf3Numbers(mark) / 3;
}

int ReadMarks()
{
	int mark[3];

	cout << "Please enter a first mark: " << endl;
	cin >> mark[0];
	cout << "Please enter a second mark: " << endl;
	cin >> mark[1];
	cout << "Please enter a third mark: " << endl;
	cin >> mark[2];

	return CalculateAverage(mark);
}



void PrintMArks(int Total)
{
	cout << "\nThe three marks = " << Total << endl;
}

int main()
{

	PrintMArks(ReadMarks());


	return 0;

}