#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";     
	cin >> arrLength;


	for (int Counter = 0; Counter < arrLength; Counter++)
	{ 
 
		arr[Counter] = RandomNumber(1, 100);
	   
	}     
	cout << endl;
}

void PrintArray(int arr[100], int arrLength) 
{
	for (int Counter = 0; Counter < arrLength; Counter++)

	cout << arr[Counter] << " ";
	cout << "\n";

}

int MinNumberInArray(int arr[100], int arrLength)
{
	int Min = 0;
	Min = arr[0];
	for (int Counter = 0; Counter < arrLength; Counter++)
	{
		if (arr[Counter] < Min)
		{
			Min = arr[Counter];
		}
	}
	return Min;
}



int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);

	

	cout << "\nArray Elements: ";     
	PrintArray(arr, arrLength);

	
	cout << "\nMin Number is: ";
	cout << MinNumberInArray(arr, arrLength);


	return 0;
}
