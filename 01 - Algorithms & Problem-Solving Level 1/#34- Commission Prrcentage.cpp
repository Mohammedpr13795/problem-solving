
#include <iostream>

using namespace std;

float ReadTotalSales()
{
    float TotalSales;

    cout << " Please enter the Total Sales: ";
    cin >> TotalSales;

    return TotalSales;
}

float GetCommissionPercentage(float  TotalSales)
{
    float P;

    if (TotalSales >= 1000000)
        return P = 0.01;

    else if (TotalSales >= 750000)
        return P = 0.02;

    else if (TotalSales >= 100000)
        return P = 0.03;

    else if (TotalSales >= 50000)
        return P = 0.05;

    else
        return P = 0.00;
}

float CalculateTotalCommisssion(float TotalSales)
{


    return GetCommissionPercentage(TotalSales) * TotalSales;

}

int main()
{
	float TotalSales = ReadTotalSales();

	cout << "\nCommission percentage: " << GetCommissionPercentage(TotalSales) << endl << endl;
	cout << "Totatl Commission: " << CalculateTotalCommisssion(TotalSales);
}