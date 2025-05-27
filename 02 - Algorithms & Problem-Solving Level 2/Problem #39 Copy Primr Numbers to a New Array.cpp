#include <iostream>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };


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

void AddArrayElement(int Number, int arr2[100], int& arrLength)
{
	//its a new element so we need to add the length by 1
	arrLength++;
	arr2[arrLength - 1] = Number;
}

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

void CopyPrimeNumbers( int arrSource[100], int arrDestination[100], int arrLength,int & arrDestinationLength)
{


	for (int Counter = 0; Counter < arrLength; Counter++)
	{

		if (CheckPrime(arrSource[Counter]) == enPrimeNotPrime::Prime)
		{
			AddArrayElement(arrSource[Counter], arrDestination, arrDestinationLength);
		}

	}


}





int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arrLength = 0, arr2Length = 0;


	FillArrayWithRandomNumbers(arr1, arrLength);

	int arr2[100];

	CopyPrimeNumbers(arr1, arr2, arrLength,arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);



	cout << "\nArray 2 Prime numbers:\n";
	PrintArray(arr2, arr2Length);






	return 0;
}
