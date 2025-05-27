#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
#include "vector"
using namespace std;

int main()
{

	vector <string> vString = { "Mohammed" , "Ali" , "Said" , "Murad" };


	cout << "\n\nVector after join: \n";
	cout << MyPrint::JoinString(vString, ":") << endl;


	system("pause>0");

}

