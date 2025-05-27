#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
#include "vector"
using namespace std;


int main()
{

	vector <string> vString = { "Mohammed" , "Ali" , "Said" , "Murad" };

	string arr[] = { "Mohammed" , "Ali" , "Said" , "Murad" };


	cout << "\n\nVector after join: \n";
	cout << MyPrint::JoinString(vString, " ") << endl;

	cout << "\n\Array after join: \n";
	cout << MyPrint::JoinString(arr, 4, " ") << endl;

	system("pause>0");

}

