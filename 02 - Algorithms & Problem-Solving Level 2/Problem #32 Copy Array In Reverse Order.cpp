
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



void Swap(int& A, int& B) {

	int Temp;

	Temp = A;
	A = B;
	B = Temp;

}

int RandomNumber(int from, int to)
{
	//function to generate a random number

	int randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
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



void printArray(int arr[100], int arrLength)
{
	for (int counter = 0; counter < arrLength; counter++)

		cout << arr[counter] << " ";
	cout << "\n";

}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
	
	for (int Counter = 0; Counter < arrLength; Counter++)
	
		arrDestination[Counter] = arrSource[arrLength - 1 - Counter];
	
}



int main()
{
	//seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arrLength;
	;

	FillArrayWithRandomNumbers(arr1, arrLength);



	cout << "\narray elements before shuffle:\n";
	printArray(arr1, arrLength);

	int arr2[100];
	CopyArrayInReverseOrder(arr1, arr2, arrLength);


	cout << "\nArray 2 elements after copy:\n";
	printArray(arr2, arrLength);


	return 0;
}