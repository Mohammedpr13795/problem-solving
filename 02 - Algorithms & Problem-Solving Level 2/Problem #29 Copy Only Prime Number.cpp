#include <iostream>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{

	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)

			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

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

void CopyOnlyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{

	int Counter = 0;
	for (int Counter2 = 0; Counter2 < arrLength; Counter2++)
	{
		if (CheckPrime(arrSource[Counter2]) == enPrimeNotPrime::Prime)
		{
			arrDestination[Counter] = arrSource[Counter2];
			Counter++;
		}

	}

	arr2Length = --Counter;
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

	int arr1[100], arrLength;
	FillArrayWithRandomNumbers(arr1, arrLength);

	int arr2[100],  arr2Length = 0;
	CopyOnlyPrimeNumber(arr1, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);



	cout << "\nPrime Number in Array 2:\n";
	PrintArray(arr2, arr2Length);




	return 0;
}
