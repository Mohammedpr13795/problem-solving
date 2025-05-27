#include <iostream>
#include "MyPrint.h"
#include "Client.h"

using namespace std;

int main()
{
	vector <MyClient::sClient> vClients = MyClient::LoadClientsDataFromFile(ClientsFileName);
	MyClient::PrintAllClientsData(vClients);


	system("pause>0");

}

