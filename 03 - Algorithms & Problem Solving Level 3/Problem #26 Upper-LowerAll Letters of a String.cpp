#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	string S1 = MyRead::ReadString();

	cout << "\nString After Upper: \n";
	S1 = MyPrint::UpperAllString(S1);
	cout << S1 << endl;

	cout << "\nString After Lower: \n";
	S1 = MyPrint::LowerAllString(S1);
	cout << S1 << endl;

	system("pause>0");

}