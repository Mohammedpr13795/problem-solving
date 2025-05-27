#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
#include "MyVector.h"
using namespace std;

int main()
{

	string S1 = "    Mohammed Mukhir    ";

	cout << "\nString: " << S1;

	cout << "\n\nTrim Left: " << MyPrint::TrimLeft(S1);
	cout << "\nTrim Right: " << MyPrint::TrimRight(S1);
	cout << "\nTrim: " << MyPrint::Trim(S1);


	system("pause>0");

}

