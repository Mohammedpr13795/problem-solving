
#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number ?\n";
	cin >> Number;

	return Number;
}

int randomNumber(int from, int to)
{
	//function to generate a random number

	int randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	//its a new element so we need to add the length by 1
	arrLength++;
	arr[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;
	do
	{
		AddArrayElement(ReadNumber(), arr, arrLength);
		cout << "\nDo you want to read more numbers? [0]:No , [1]:yes? ";
		
		cin >> AddMore;
	} while (AddMore);
	
	




}


void printArray(int arr[100], int arrLength)
{
	for (int counter = 0; counter < arrLength; counter++)

		cout << arr[counter] << " ";
	cout << "\n";

}











int main()
{
	//seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0; 
	
	InputUserNumbersInArray(arr, arrLength);

	cout << "\nArray length: " << arrLength << endl;
	cout << "Array elements: ";
	printArray(arr, arrLength);

	






	return 0;
}