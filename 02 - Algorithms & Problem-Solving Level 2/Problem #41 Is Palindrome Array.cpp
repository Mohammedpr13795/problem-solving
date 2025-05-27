#include <iostream>
#include <string>
using namespace std;


void FillArray(int arr[100], int& arrLength)
{

	arrLength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 4;
	arr[4] = 20;
	arr[5] = 10;

}

void PrintArray(int arr[100], int arrLength)
{


	for (int Counter = 0; Counter < arrLength; Counter++)

		cout << arr[Counter] << " ";
	cout << "\n";

}




bool IsPalindromeNumber(int arr[100], int Length)
{
	
	for (int Counter = 0; Counter < Length; Counter++)
	{
		if (arr[Counter] != (arr[Length - Counter - 1]))
		
			return false;
		
	}
	return true;

}



int main()
{

	int arr[100], Length = 0;

	FillArray(arr, Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, Length);



	if(IsPalindromeNumber(arr,Length))

		cout << "\nYes array is Palindrome\n";

	else

		cout << "\No array is not Palindrome\n";



	return 0;

}
