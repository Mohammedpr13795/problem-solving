#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	char Ch1 = MyRead::ReadChar();
	cout << "\nChar after inverting case: \n";

	Ch1 = MyPrint::invertingCharCase(Ch1);
	cout << Ch1 << endl;

	system("pause>0");

}