#include <iostream>
#include "MyPrint.h"


using namespace std;



int main()
{

	string S1 = "Welcome To Jordan , Jordan is a nice Country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "Usa";

	cout << "\nOriginal String\n" << S1;
	cout << "\n\nString after Replace:";
	cout << "\n" <<  MyPrint::ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);



	system("pause>0");

}

