/*
Problem: Write a program to read a Total Bill and CashPaid and
calculate the remainder to be Paid Back
*/
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float CalculateRemainder(float TotalBill, float TotalCashPaid)
{

 return TotalCashPaid - TotalBill;

}

void PrintResult()
{
	float TotalBill = ReadPositiveNumber("Please enter the total bill: ");
	float TotalCashPaid = ReadPositiveNumber("Please enter the cash paid: ");

	cout <<  "The total bill is = " << TotalBill << endl;
	cout << "The cash paid is =  " << TotalCashPaid << endl;
	cout << "**********************\n";
	cout << "The remainder is = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;
}

int main() {

	PrintResult();

	return 0;
}

Problem 39 - Pay remainder(2)

/*
Problem: Write a program to read a Total Bill and CashPaid and
calculate the remainder to be Paid Back
*/
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float CalculateRemainder(float TotalBill, float TotalCashPaid)
{

	return TotalCashPaid - TotalBill;

}




int main() {


	float TotalBill = ReadPositiveNumber("Please enter the total bill: ");
	float TotalCashPaid = ReadPositiveNumber("Please enter the cash paid: ");

	cout << "The Total Bill is = " << TotalBill << endl;
	cout << "The Cash Paid is =  " << TotalCashPaid << endl;
	cout << "**********************\n";
	cout << "The Remainder is = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

	return 0;
}



