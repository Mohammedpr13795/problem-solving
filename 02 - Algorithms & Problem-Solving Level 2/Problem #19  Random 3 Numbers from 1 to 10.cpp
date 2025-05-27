#include<iostream>
#include<cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

int main()
{
	//Function to generate a random number
	srand((unsigned)time(NULL));

	cout << RandomNumber(1,10) << endl;
	cout << RandomNumber(1,10) << endl;
	cout << RandomNumber(1,10) << endl;

	return 0;

}