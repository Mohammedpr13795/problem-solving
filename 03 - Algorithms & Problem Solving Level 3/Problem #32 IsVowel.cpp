#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{

	char Ch1 = MyRead::ReadChar();

	if (MyPrint::IsVowel(Ch1))
	{
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel.";
	}
	else
	{
		cout << "\nNO Letter '" << Ch1 << "' is NOT vowel.";
	}

	system("pause>0");

}
