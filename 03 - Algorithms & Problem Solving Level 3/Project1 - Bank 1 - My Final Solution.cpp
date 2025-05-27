#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "ClientsRecord.txt";


void ShowMainMenu();

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string  Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;

};



vector <string> SplitString(string S1, string Delim)
{
	vector <string> vEachWord;

	short pos = 0;
	string sWord; // define a string variable


	// use find() function to get the position of the delimiter
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vEachWord.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); /*erase() until
		position and move to next word.*/
	}

	if (S1 != "")
	{
		vEachWord.push_back(S1);
	}
	return vEachWord;
}

string ConvertRecordToLine(sClient Client, string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Separator;
	stClientRecord += Client.PinCode + Separator;
	stClientRecord += Client.Name + Separator;
	stClientRecord += Client.Phone + Separator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;

}

sClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	sClient sClient;
	vector <string> vClientData;
	vClientData = SplitString(Line, Separator);

	sClient.AccountNumber = vClientData[0];
	sClient.PinCode = vClientData[1];
	sClient.Name = vClientData[2];
	sClient.Phone = vClientData[3];
	sClient.AccountBalance = stod(vClientData[4]); // cast string to double


	return sClient;

}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return false;
}

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number: ";

	// Usage of std::ws will extract all the whitespace character
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists , Enter another Account Number: ";
		getline(cin >> ws, Client.AccountNumber);
	}
	
	cout << "Please enter PinCode: ";
	getline(cin , Client.PinCode);

	cout << "Please enter Name: ";
	getline(cin, Client.Name);

	cout << "Please enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Please enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{

	vector <sClient> vClients;

	fstream MyFile;


	MyFile.open(ClientsFileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	
	cout << "\n\t\t\t\t\t" << "Client List " << "(" << vClients.size() << ")" << " Client(s).";
	cout << "\n______________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________________________________________________\n\n";

	if(vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
	{
		for (sClient& Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";

	}

}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPhin Code     : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "-----------------------------------";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nPlease enter PinCode: ";
	getline(cin >> ws, Client.PinCode);

	cout << "Please enter Name: ";
	getline(cin, Client.Name);

	cout << "Please enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Please enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

bool MarkClientDataForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
		return	true;
		}
	}
	return false;
}

vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient>& vClients)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out); // overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient& C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLine(C);

				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return vClients;
}

void AddClientDataLineToFile(string FileName, string ClientLine)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << ClientLine << endl;

		MyFile.close();

	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddClientDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewClients()
{

	char AddMoreClient = 'Y';

	do
	{
		//system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully , do you want to add more client? ";
		cin >> AddMoreClient;

	} while (toupper(AddMoreClient == 'y'));

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientDataForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return	true;

		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!";
		return	false;
	}

}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}


			SaveClientsDataToFile(ClientsFileName, vClients);


			cout << "\n\nClient updated Successfully.";
			return	true;
		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!";
		return	false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "Please enter the account Number: ";
	cin >> AccountNumber;
	return AccountNumber;
}

void ShowDeleteClientScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tDelete Client Screen";
	cout << "\n---------------------------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tUpdate Client Screen";
	cout << "\n---------------------------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tAdd New Clients Screen";
	cout << "\n---------------------------------------------------\n";
	AddNewClients();
}

void ShowFindClientScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\n\Find Client Screen";
	cout << "\n---------------------------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found.\n";

	}

}

void ShowEndScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tProgram Ends :-)";
	cout << "\n---------------------------------------------------\n";
}

enum enMainMenueOptions {
	eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
	eUpdateClient = 4, eFindClient = 5, eExit = 6
};

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	ShowMainMenu();

}

short ReadMainMainMenuOption()
{
	cout << "Choice What do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void PerformMainMenuOption(enMainMenueOptions MainMenuOptions)
{


	switch (MainMenuOptions)
	{
	case enMainMenueOptions::eListClients:
		system("cls");
		ShowAllClientsScreen(); // Show All Clients Data (Choice 1)
		GoBackToMainMenu();
		break;
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen(); // 47 ADD Clients (Choice 2)
		GoBackToMainMenu();
		break;
	case enMainMenueOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen(); // Delete Client Data By Account Number (Choice 3)
		GoBackToMainMenu();
		break;
	case enMainMenueOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen(); // Update Client Data By Account Number (Choice 4)
		GoBackToMainMenu();
		break;
	case enMainMenueOptions::eFindClient:
		system("cls");
		ShowFindClientScreen(); // Find Client Data By Account Number (Choice 5)
		GoBackToMainMenu();
		break;
	case enMainMenueOptions::eExit: // End The Program (Choice 6)
		system("cls");
		ShowEndScreen();
		break;
	}

}


void ShowMainMenu()
{
	system("cls");
	cout << "=============================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client.\n";
	cout << "\t[5] Find Client Info.\n";
	cout << "\t[6] Exit.\n";
	cout << "=============================================\n";
	PerformMainMenuOption((enMainMenueOptions)ReadMainMainMenuOption());
}



int main()
{

	ShowMainMenu();
	system("pause>0");
	return 0;
}

