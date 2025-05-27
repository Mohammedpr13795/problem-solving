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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{

	

	for (int Counter = 0; Counter < arrLength; Counter++)

		arrDestination[Counter] = arrSource[Counter];

	
}





int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arrLength;
	

	FillArrayWithRandomNumbers(arr1, arrLength);

	int arr2[100];
	CopyArray(arr1, arr2, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);



	cout << "\nArray 2 elements after copy:\n";
	PrintArray(arr2, arrLength);




	return 0;
}
