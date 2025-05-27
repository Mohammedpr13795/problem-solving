#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;

int main()
{
	MyPrint::PrintFirstLetterOfEachWord(MyRead::ReadString());

	system("pause>0");

}