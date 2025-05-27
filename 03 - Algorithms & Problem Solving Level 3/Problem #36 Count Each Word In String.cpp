#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	string S1 = MyRead::ReadString();
	cout << "\nThe number of words in your string is: ";
	cout << MyPrint::CountWords(S1);


	system("pause>0");

}
