/*
Problem: Write a program to ask the user to enter:
num , num 3
then print the two numbers , then swap the two numbers and print them
*/
#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B)
{
	cout << "Please enter number A : ";
	cin >> A;
	cout << "Please enter number B : ";
	cin >> B;
}
void SwapNumers(int& A, int& B) {

	int Temp;

	Temp = A;
	A = B;
	B = Temp;

}

void PrintSwapNumers(int Num1, int Num2)
{
	cout << "\nNumber1 = " << Num1;
	cout << "\nNumber2 = " << Num2 << endl;

}

int main() {

	int Num1, Num2;


	ReadNumbers(Num1, Num2);
	PrintSwapNumers(Num1, Num2);
	SwapNumers(Num1, Num2);
	PrintSwapNumers(Num1, Num2);







	return 0;


}/*
Problem: Write a program to ask the user to enter:
num , num 3
then print the two numbers , then swap the two numbers and print them
*/
#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B)
{
	cout << "Please enter number A : ";
	cin >> A;
	cout << "Please enter number B : ";
	cin >> B;
}
void SwapNumers(int& A, int& B) {

	int Temp;

	Temp = A;
	A = B;
	B = Temp;

}

void PrintSwapNumers(int Num1, int Num2)
{
	cout << "\nNumber1 = " << Num1;
	cout << "\nNumber2 = " << Num2 << endl;

}

int main() {

	int Num1, Num2;


	ReadNumbers(Num1, Num2);
	PrintSwapNumers(Num1, Num2);
	SwapNumers(Num1, Num2);
	PrintSwapNumers(Num1, Num2);







	return 0;


}