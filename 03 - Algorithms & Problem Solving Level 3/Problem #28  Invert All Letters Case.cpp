#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	string S1 = MyRead::ReadString();
	cout << "\nString after inverting All Letters case: \n";
	S1 = MyPrint::InvertingAllLettersCase(S1);

	cout << S1 << endl;


	system("pause>0");

}