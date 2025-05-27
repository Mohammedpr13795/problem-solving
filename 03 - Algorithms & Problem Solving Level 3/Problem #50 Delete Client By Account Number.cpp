#include <iostream>
#include "MyPrint.h"
#include "Client.h"

using namespace std;

int main()
{
	vector <MyClient::sClient> vClient = MyClient::LoadClientsDataFromFile(ClientsFileName);

	MyClient::sClient Client;
	string AccountNumber =  MyClient::ReadAccountNumber();

	 MyClient::DeleteClientByAccountNumber(AccountNumber, vClient);

	system("pause>0");

}

