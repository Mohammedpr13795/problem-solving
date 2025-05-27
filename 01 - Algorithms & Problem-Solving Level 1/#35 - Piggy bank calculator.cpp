#include <iostream>

using namespace std;

struct stPiggyBankContenet
{
	int Pennies, Nickels, Dimes, Quarters, Dollors;

};

stPiggyBankContenet ReadPiggyBankContenet()
{
	stPiggyBankContenet PiggyBankContenet;

	cout << "Please enter the Pennies: " << endl;
	cin >> PiggyBankContenet.Pennies;

	cout << "Please enter the Nickels: " << endl;
	cin >> PiggyBankContenet.Nickels;

	cout << "Please enter the Dimes: " << endl;
	cin >> PiggyBankContenet.Dimes;

	cout << "Please enter the Quarters: " << endl;
	cin >> PiggyBankContenet.Quarters;

	cout << "Please enter the Dollors: " << endl;
	cin >> PiggyBankContenet.Dollors;

	return PiggyBankContenet;
}

int CalculateTotalPennies(stPiggyBankContenet PiggyBankContenet)
{
	int Total_Pennies = 0;

	Total_Pennies = (PiggyBankContenet.Pennies * 1) + (PiggyBankContenet.Nickels * 5) + (PiggyBankContenet.Dimes * 10) + (PiggyBankContenet.Quarters * 25) + (PiggyBankContenet.Dollors * 100);

	return Total_Pennies;
}





int main()
{
	int TotalPennies = CalculateTotalPennies(ReadPiggyBankContenet());

	cout << "The total pennies are: " << TotalPennies << " Pennies" << endl;
	cout << "The total dollors are: " << (float)TotalPennies / 100 << " Dollors" << endl;





	return 0;
}