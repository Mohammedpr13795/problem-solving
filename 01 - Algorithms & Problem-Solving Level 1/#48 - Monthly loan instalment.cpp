/*
Probelm: Write a program to read a loan amount and ask
you how many months you need to sattle the loan than calcualte
the monthly installment amount
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

float MonthlyInstalment(float LoanAmount, float HowManyMonths)
{


	return  (float) LoanAmount / HowManyMonths;
}

int main() {


	float LoanAmount = ReadPositiveNumber("Please Enter The Loan Amount: ");
	float HowManyMonths = ReadPositiveNumber("How Many Months: ");

	cout << "\nThe monthly instalment is = " << MonthlyInstalment(LoanAmount, HowManyMonths);


	return 0;
}