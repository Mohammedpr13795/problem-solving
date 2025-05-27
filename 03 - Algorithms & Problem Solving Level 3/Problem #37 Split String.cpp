#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
#include <vector>
#include "MyVector.h"
using namespace std;

int main()
{

	vector <string> vString = MyVector::SplitString(MyRead::ReadString(), " ");

	cout << "Tokens = " << vString.size() << endl;

	for (string& Word : vString)
	{
		cout << Word << endl;
	}


	system("pause>0");

}
