/*
Problem: Write a program to read a loan amount and monthly payment
and caculate how many months you need to sattle the loan
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



float TotalMonths(float LoanAmount , float MonthlyInstallment)
{


	 return  (float) LoanAmount / MonthlyInstallment;
}



int main() {

	float LoanAmount = ReadPositiveNumber("Please Enter The Loan Amount: ");
	float MonthlyInstallment = ReadPositiveNumber("Please Enter The Monthly Instalment: ");

	cout << "\nTotal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallment);


	return 0;

}