#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{

	string S1 = MyRead::ReadString();

	cout << "\nNumber of vowels is: " << MyPrint::CountVowels(S1);
	system("pause>0");

}
