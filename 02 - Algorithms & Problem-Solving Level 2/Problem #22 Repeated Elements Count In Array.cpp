#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void ReadArray(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";     
	cin >> arrLength;

	cout << "\nEnter array elements: \n";

	for (int Counter = 0; Counter < arrLength; Counter++)
	{ 
	  cout << "Element [" << Counter + 1 << "] : ";
	  cin >> arr[Counter];
	}     
	cout << endl;
}

void PrintArray(int arr[100], int arrLength) 
{
	for (int Counter = 0; Counter < arrLength; Counter++)

	cout << arr[Counter] << " ";
	cout << "\n";

}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
	int count = 0; 
	for (int Counter = 0; Counter <= arrLength - 1; Counter++){
		if (Number == arr[Counter])
		{ 
			count++; 
		} 
	}
	return count;
}



int main()
{
	int arr[100], arrLength, NumberToCheck;


	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

	cout << "\nOriginal array: ";     
	PrintArray(arr, arrLength);

	cout << "\nNumber " << NumberToCheck;     
	cout << " is repeated ";

	cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";

	return 0;
}