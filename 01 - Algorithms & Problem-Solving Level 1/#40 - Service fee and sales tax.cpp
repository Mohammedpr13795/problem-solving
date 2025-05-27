/*
Problem: A restaurant chargh 10% service fee and 16% sales tax

write a program to read a billvalue and add service fee and sales tax to it
and print the total bill on the screen
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

float TotalBillAfterServiceAndTax(float TotalBill)
{


	TotalBill *= 1.1; // service fee
	TotalBill *= 1.16; // sales tax

	return TotalBill;
}



int main() {




	float TotalBill = ReadPositiveNumber("Please enter the total bill: \n");

	cout << "**********************\n";
	cout << "The Bill = " << TotalBill;
	cout << "The Bill after Service Fee and Sales Tax = "
		<< TotalBillAfterServiceAndTax(TotalBill) << endl; // after the service fee and sales tax



	return 0;
}