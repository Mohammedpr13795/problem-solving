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

int RandomNumber(int From, int To)
{
	//Function to generate a random number

	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int arr[100],int& arrLength)
{



	for (int Counter = 0; Counter < arrLength; Counter++)
	{

		arr[Counter] = RandomNumber(1, 100);

	}
	cout << endl;
}

void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{


	for (int Counter = 0; Counter < arrLength; Counter++)
	{
		arrSum[Counter] = arr1[Counter] + arr2[Counter];
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int Counter = 0; Counter < arrLength; Counter++)

		cout << arr[Counter] << " ";
	cout << "\n";

}







int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arr2[100], arrSum[100];
	int arrLength = ReadPositiveNumber("How many elements ?\n");


	FillArrayWithRandomNumbers(arr1, arrLength);
	FillArrayWithRandomNumbers(arr2, arrLength);

	SumOf2Arrays(arr1, arr2, arrSum, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);



	cout << "\nArray 2 elements:\n";
	PrintArray(arr2, arrLength);

	cout << "\nSum Of Array 1 + Array 2 Elements :\n";
	PrintArray (arrSum, arrLength);

	return 0;
}
