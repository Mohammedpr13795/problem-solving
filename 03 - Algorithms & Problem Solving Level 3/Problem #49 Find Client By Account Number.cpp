#include <iostream>
#include "MyPrint.h"
#include "Client.h"

using namespace std;


int main()
{
	MyClient::sClient Client;
	string AccountNumber = MyClient::ReadAccountNumber();

	if ( MyClient::FindClientByAccountNumber(AccountNumber, Client))
	{
		MyClient::PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found.";
	}


	system("pause>0");

}

