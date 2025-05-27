
#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number of search for?\n";
	cin >> Number;

	return Number;
}

int randomNumber(int from, int to)
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

		arr[Counter] = randomNumber(1, 100);


	}
	cout << endl;
}




void printArray(int arr[100], int arrLength)
{
	for (int counter = 0; counter < arrLength; counter++)

		cout << arr[counter] << " ";
	cout << "\n";

}


short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	/*This function will search for a number in array and
	return its index, or return -1 if it does not exists*/

	for (int Counter = 0; Counter < arrLength; Counter++)
	{
		if (arr[Counter] == Number)
			return Counter; //and return the index
	}
	//if you reached here, this means the number is not foundreturn -1; } 
	return -1;
}


bool IsNumberInArray(int Number, int arr[100], int arrLength)
{

			return FindNumberPositionInArray(Number,arr,arrLength) != -1;

}





int main()
{
	//seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);


	cout << "\narray 1 elements:\n";
	printArray(arr, arrLength);

	int Number = ReadNumber();
	cout << "\nNumber you are looking for is: " << Number << endl;


	if (!IsNumberInArray(Number, arr, arrLength))

		cout << "The number is not found :-(\n";

	else
		
		cout << "The number is  found :-)\n";
		
		





	return 0;
}