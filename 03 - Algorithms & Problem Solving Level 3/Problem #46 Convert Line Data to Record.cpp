#include <iostream>
#include "MyPrint.h"
#include "Client.h"
using namespace std;

int main()
{
	string stLine = "A150#//#1234#//#Mohammed Mukhir#//#0507275605#//#5000.000000";
	cout << "Link Record is: \n";
	cout << stLine;

	MyClient::sClient Client = MyClient::ConvertLineToRecord(stLine);
	MyClient::PrintClientRecord(Client);


	system("pause>0");

}

