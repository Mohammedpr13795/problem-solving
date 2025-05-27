#include <iostream>
#include "MyPrint.h"
#include "Client.h"
using namespace std;

int main()
{
	cout << "\nPlease Enter Client Data: \n\n";

	 MyClient::sClient Client;
	Client =  MyClient::ReadNewClient();

	cout << "\n\nClient Record for Saving is: \n";
	cout << MyClient::ConvertRecordToLine(Client);


	system("pause>0");

}

