#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	string S1 = MyRead::ReadString();
	char Ch1 = MyRead::ReadChar();
	cout << "\nLetter \'" << Ch1 << "\' Count= "
		<< MyPrint::CountLetters(S1, Ch1);
	cout << "\nLetter \'" << Ch1 << "\' ";
	cout << "or\'" << MyPrint::InvertLetterCase(Ch1) << "\' ";
	cout << "Count= " << MyPrint::CountMatchCaseLetters(S1, Ch1, false);


	system("pause>0");

}
