
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

int randomNumber(int from, int to)
{
	//function to generate a random number

	int randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}

void FillArrayWith1toN(int arr[100], int arrLength)
{


	
	for (int Counter = 0; Counter < arrLength; Counter++)
	{

		arr[Counter] = Counter + 1;
	}
	cout << endl;
}



void shuffleArray(int arr[100], int arrLength)
{


	for (int Counter = 0; Counter < arrLength; Counter++)
	{

		
		Swap(arr[randomNumber( 1,arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
	}

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

	int arr[100], arrLength;
	arrLength = ReadPositiveNumber("\nEnter number of elements : \n");

	FillArrayWith1toN(arr, arrLength);


	cout << "\narray elements before shuffle:\n ";
	printArray(arr, arrLength);



	shuffleArray(arr, arrLength);


	cout << "\narray elements after shuffle:\n";
	printArray(arr, arrLength);


	return 0;
}