#include <iostream>

using namespace std;



void ReadNubmers(int& A, int& B, int& C)
{


	cout << "Please enter a first number: " << endl;
	cin >> A;

	cout << "Please enter a second number: " << endl;
	cin >> B;

	cout << "Please enter a second number: " << endl;
	cin >> C;
}

int MaxOf3Numbers(int A, int B, int C)
{

	if (A > B)
		if (A > C)
			return A;
		else
			return C;
	else
		if (B > C)
			return B;
		else
			return C;

}

void PrintResult(int Max)
{

	cout << "\nThe maximum is: " << Max << endl;

}
int main()
{
	int A, B, C;

	ReadNubmers(A, B, C);
	PrintResult(MaxOf3Numbers(A, B, C));

	return 0;
}