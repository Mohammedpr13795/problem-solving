#include <iostream>
#include "MyPrint.h"

using namespace std;

int main()
{
	string S1 = "Welcome To, Jeddah, Jeddah, is a nice city; Jeddah it's a nice amazing.";


	cout << "Original String\n" << S1;

	cout << "\n\n\Punctuation removed: \n" << MyPrint::RemovePunctuationsFromString(S1);



	system("pause>0");

}

