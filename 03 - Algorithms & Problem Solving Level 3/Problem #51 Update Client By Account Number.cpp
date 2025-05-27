#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip> 
using namespace std;

const string ClientsFileName = "ClientRecord.txt";

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

vector <sClient> LoadClientsDataFromFile(string FileName)
{

	vector <sClient> vClients;

	fstream MyFile;


	MyFile.open(FileName, ios::in); // read mode

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

string ReadAccountNumber()
{
	string AccountNumber;

	cout << "Please enter the account Number: ";
	cin >> AccountNumber;
	return AccountNumber;
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

void PrintClientCard(sClient Client)
{
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPhin Code     : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
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
			true;
		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

int main()
{
	vector <sClient> vClient = LoadClientsDataFromFile(ClientsFileName);

	sClient Client;
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClient);

	system("pause>0");

}

