#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
#include "vector"

using namespace std;

int main()
{

	string S1 = MyRead::ReadString();


	cout << "\n\String after reversing words: \n";
	cout << MyPrint::ReverseWordsInString(S1);



	system("pause>0");

}

