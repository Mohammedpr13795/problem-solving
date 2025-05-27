#include <iostream>
#include "Read.h"
#include "Math.h"
using namespace std;


int main()
{

	int Page = 1, TotalPages = 10;

	cout << "The page number = " << Page << endl; // Before

	//Print string and int variable
	printf("The page number = %d \n", Page);
	printf("Your are in Page %d of %d \n", Page, TotalPages);

	//Width specification
	printf("The page number = %0*d \n", 2, Page);
	printf("The page number = %0*d \n", 3, Page);
	printf("The page number = %0*d \n", 4, Page);
	printf("The page number = %0*d \n", 5, Page);

	int Number1 = 20, Number2 = 30;
	printf("The Result of %d + %d = %d \n", Number1, Number2, Number1 + Number2);

	return 0;
}



