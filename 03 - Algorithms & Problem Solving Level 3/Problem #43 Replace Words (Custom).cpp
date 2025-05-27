#include <iostream>
#include "MyPrint.h"
#include <string>
#include <vector>
#include "MyVector.h"


using namespace std;


int main()
{
	string S1 = "Welcome To Jeddah , Jeddah is a nice City";
	string StringToReplace = "jeddah";
	string ReplaceTo = "Riyadh";

	cout << "\nOriginal String\n" << S1;

	cout << "\n\nReplace with match case:";
	cout << "\n" << MyPrint::ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

	cout << "\n\nReplace with don't match case:";
	cout << "\n" << MyPrint::ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);


	system("pause>0");

}

