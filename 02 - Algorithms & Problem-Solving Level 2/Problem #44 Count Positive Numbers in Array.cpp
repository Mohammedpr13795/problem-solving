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

		arr[Counter] = RandomNumber(-100, 100);

	}
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{


	for (int Counter = 0; Counter < arrLength; Counter++)

		cout << arr[Counter] << " ";
	cout << "\n";

}





int PositiveCount(int arrSource[100], int arrLength)
{

	int Count = 0;

	for (int Counter = 0; Counter < arrLength; Counter++)
	{

	

		

		if (arrSource[Counter] < 0)
		{
			
			Count++;
			
		}

	}
	return Count;

}





int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arrLength = 0;


	FillArrayWithRandomNumbers(arr1, arrLength);

	int arr2[100];


	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);



	cout << "\Positive Number Count is: ";
	cout << PositiveCount(arr1, arrLength) << endl;





	return 0;
}
