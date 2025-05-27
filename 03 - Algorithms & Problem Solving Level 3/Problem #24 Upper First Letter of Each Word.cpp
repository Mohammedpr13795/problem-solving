#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;


int main()
{
	string S1 = MyRead::ReadString();
	cout << "\nString After Conversation: \n";

	S1 =  MyPrint::UpperFirstLetterOfEachWord(S1);
	cout << S1 << endl;

	system("pause>0");

}