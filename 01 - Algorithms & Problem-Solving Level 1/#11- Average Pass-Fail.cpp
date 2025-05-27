#include <iostream>

using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

int SumOf3Numbers(int mark[3])
{
	return mark[0] + mark[1] + mark[2];
}

float CalculateAverage(int mark[3])
{
	return (float)SumOf3Numbers(mark) / 3;
}

int ReadMark()
{
	int mark[3];

	cout << "Please enter the mark 1: ";
	cin >> mark[0];

	cout << "Please enter the mark 2: ";
	cin >> mark[1];

	cout << "Please enter the mark 3: ";
	cin >> mark[2];

	return CalculateAverage(mark);
}



enPassFail CheckAverage(int Average)
{
	if (Average >= 50)

		return enPassFail::Pass;
	else
		return enPassFail::Fail;

}
void PrintMark(int Average)
{
	cout << "your average is: " << Average << endl;

	if (CheckAverage(Average) == enPassFail::Pass)
		cout << "\nYou Passed";
	else
		cout << "\nYou Faild.";

}


int main()
{
	PrintMark(ReadMark());

	return 0;
}#inc