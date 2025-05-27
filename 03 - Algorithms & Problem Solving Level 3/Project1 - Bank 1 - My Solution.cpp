#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "ClientRecord.txt";


enum enBankChoice {
	ShoiwClientList = 1, AddNewClient = 2, DeleteClient = 3,
	UpdateClientInfo = 4, FindClient = 5, Exit = 6
};

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string  Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;

};

sClient ReadNewClient();
string ReadAccountNumber();

vector <string> SplitString(string, string);
string ConvertRecordToLine(sClient, string);
sClient ConvertLineToRecord(string, string);

void AddNewClients();
void AddClients(string, vector <sClient>&, sClient);
void AddClientDataLineToFile(string, string);
vector <sClient> SaveClientsDataToFile(string, vector <sClient>&);
vector <sClient> LoadClientsDataFromFile(string);
bool UpdateClientByAccountNumber(string, vector <sClient>&);
bool DeleteClientByAccountNumber(string, vector <sClient>&);

bool FindClientByAccountNumber(string, vector <sClient>, sClient&);
bool MarkClientDataForDeleteByAccountNumber(string, vector <sClient>&);
void FindClientData(vector <sClient>&);
void DeleteClientData(vector <sClient>);
void UpdateClientData(vector <sClient>);



void PrintClientRecord(sClient);
void PrintAllClientsData(vector <sClient>);
void PrintClientCard(sClient);
sClient ChangeClientRecord(string);

void PauseScreen();


sClient ReadNewClient(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;
	/*وظيفة ws في استخدام
		getline تستخدم لإزالة الفراغات (المسافات والأمور ذات الصلة)
		من بداية السلسلة قبل قراءتها باستخدام getline.
		هذا يفيد في تجاوز الفراغات البيضاء الزائدة والمسافات في البداية
		الذي يمكن أن تؤدي إلى مشاكل عند قراءة البيانات.
		*/
	cout << "Please enter PinCode: ";
	getline(cin >> ws, Client.PinCode);

	cout << "Please enter Name: ";
	getline(cin, Client.Name);

	cout << "Please enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Please enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

string ReadAccountNumber()
{
	string AccountNumber;

	cout << "Please enter the account Number: ";
	cin >> AccountNumber;
	return AccountNumber;
}

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


			cout << "\n\nClient updated Successfully.\n\n";
			return	true;
		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!\n\n";
		return	false;
	}
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

			cout << "\n\nClient Deleted Successfully.\n\n";
			return	true;

		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!\n\n";
		return	false;
	}

}


void AddNewClients(vector <sClient> vClients)
{
	sClient Client;
	bool isFind = true;
	string AccountNumber = ReadAccountNumber();

	do
	{

		isFind = FindClientByAccountNumber(AccountNumber, vClients, Client) ? true : false;

		if (isFind)
		{
			cout << "Client with [" << AccountNumber << "] already exits , ";
			cout << "Enter another account number: ";
			cin >> AccountNumber;
			isFind = FindClientByAccountNumber(AccountNumber, vClients, Client) ? true : false;
			if (isFind == false)
				Client = ReadNewClient(AccountNumber);
			AddClientDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
			break;
		}

		else
		{
			Client = ReadNewClient(AccountNumber);
			AddClientDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
		}
	} while (isFind);




}

void AddClients(vector <sClient> vClients)
{
	sClient Client;
	char AddMoreClient = 'Y';


	do
	{
		system("cls");
		cout << "---------------------------------------------------\n";
		cout << "\t\tAdd New Clients Screen\n";
		cout << "---------------------------------------------------\n";
		cout << "Adding New Client:\n\n";
		AddNewClients(vClients);
		cout << "\nClient Added Successfully , do you want to add more client? ";
		cin >> AddMoreClient;


	} while (toupper(AddMoreClient == 'y'));

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
bool MarkClientDataForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			true;
		}
	}
	return false;
}


void FindClientData(vector <sClient>& vClients)
{
	system("cls");
	cout << "---------------------------------------------------\n";
	cout << "\t\Find Client Screen\n";
	cout << "---------------------------------------------------\n";
	sClient Client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found.\n";

	}

}

void DeleteClientData(vector <sClient> vClient)
{
	system("cls");
	cout << "---------------------------------------------------\n";
	cout << "\t\tDelete Client Screen\n";
	cout << "---------------------------------------------------\n";
	sClient Client;
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClient);

}

void UpdateClientData(vector <sClient> vClient)
{
	system("cls");
	cout << "---------------------------------------------------\n";
	cout << "\t\tUpdate Client Screen\n";
	cout << "---------------------------------------------------\n";
	sClient Client;
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClient);

}


void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	system("cls");
	cout << "\n\t\t\t\t\t" << "Client List " << "(" << vClients.size() << ")" << " Client(s).";
	cout << "\n______________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________________________________________________\n\n";

	for (sClient& Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "\n_______________________________________________________________________________________________\n\n";

}

void PrintClientCard(sClient Client)
{
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPhin Code     : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n\n";
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


void ExitFromBank()
{
	system("cls");
	cout << "---------------------------------------------------\n";
	cout << "\t\tProgram Ends :-)\n";
	cout << "---------------------------------------------------\n";
}


void TheChoiceOfProgram(short Choice)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);


	switch (Choice)
	{
	case enBankChoice::ShoiwClientList:
		PrintAllClientsData(vClients); // Show All Clients Data (Choice 1)
		PauseScreen();
		break;
	case enBankChoice::AddNewClient:
		AddClients(vClients); // 47 ADD Clients (Choice 2)
		break;
	case enBankChoice::DeleteClient:
		DeleteClientData(vClients); // Delete Client Data By Account Number (Choice 3)
		PauseScreen();
		break;
	case enBankChoice::UpdateClientInfo:
		UpdateClientData(vClients); // Update Client Data By Account Number (Choice 4)
		PauseScreen();
		break;
	case enBankChoice::FindClient:
		FindClientData(vClients); // Find Client Data By Account Number (Choice 5)
		PauseScreen();
		break;
	case enBankChoice::Exit: // End The Program (Choice 6)
		ExitFromBank();
		break;
	}

}

void PauseScreen()
{
	cout << "\nPress any key to go back to main menu..." << system("pause");


}

void ShowMainMenu()
{

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
	cout << "Choice what do you want to do? [1 to 6]? ";
}

void StartProgram()
{
	short Choice = 0;

	do
	{
		system("cls");
		ShowMainMenu();
		cin >> Choice;
		TheChoiceOfProgram(Choice);
		//cout << "Press any key to go back to Main Menu..." << system("pause");
	} while (Choice != 6);



}

int main()
{


	StartProgram();




	system("pause>0");

}

