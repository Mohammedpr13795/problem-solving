#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	string S1 = MyRead::ReadString();
	char Ch1 = MyRead::ReadChar();
	cout << "\nLetter \'" << Ch1 << "\' Count= " << MyPrint::CountLetters(S1, Ch1);


	system("pause>0");

}