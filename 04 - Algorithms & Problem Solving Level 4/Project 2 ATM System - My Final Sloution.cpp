#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";


struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string  Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;

};


enum enMainMenuOptions {eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3,  
						   eCheckBalance = 4,  eExit = 5 };



void ShowMainMenu();
void Login();
void ShowQuickWithdrawScreen();
void ShowNormalWithDrawScreen();
void ShowDepositScreen();

stClient CurrentClient;


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

string ConvertRecordToLine(stClient Client, string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Separator;
	stClientRecord += Client.PinCode + Separator;
	stClientRecord += Client.Name + Separator;
	stClientRecord += Client.Phone + Separator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}


stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	stClient sClient;
	vector <string> vClientData;
	vClientData = SplitString(Line, Separator);

	sClient.AccountNumber = vClientData[0];
	sClient.PinCode = vClientData[1];
	sClient.Name = vClientData[2];
	sClient.Phone = vClientData[3];
	sClient.AccountBalance = stod(vClientData[4]); // cast string to double


	return sClient;

}

vector <stClient> LoadClientsDataFromFile(string FileName)
{

	vector <stClient> vClients;

	fstream MyFile;


	MyFile.open(ClientsFileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}


bool FindClientByUserAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}
	return false;

}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient>& vClients)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out); // overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient& C : vClients)
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

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <stClient> vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to perform this Transaction? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully . New Balance is " << C.AccountBalance;
				return true;
			}
		}
	}
	return false;
}

short ReadQuickWithdrawOption()
{
	cout << "\nChoice What to do Withdraw from [1] to [9] ? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}


short getQuickWithDrawAmount(short QuickWithdrawOption)
{


	switch (QuickWithdrawOption)
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 1000;
	default:
		return 0;
	}
}

void PerformQuickWithDrawOption(short QuickWithDrawOption)
{
	if (QuickWithDrawOption == 9) // exit
		return;

	short WithDrawBalance = getQuickWithDrawAmount(QuickWithDrawOption);

	while (WithDrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount Exceeds your balance , make another choice.";
		cout << "\nPress Anykey to continue...\n";
		system("pause>0");
		ShowQuickWithdrawScreen();
		return;
	}

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients);
	CurrentClient.AccountBalance -= WithDrawBalance;

}

double ReadDepositAmount()
{
	double Amount = 0;
	cout << "\n\Enter a positive Deposit Amount : ";
	cin >> Amount;

	while (Amount <= 0)
	{
		cout << "\n\Enter a positive Deposit Amount : ";
		cin >> Amount;
	}

	return Amount;
}

void PerformDepositOption()
{
	double DepositAmount = ReadDepositAmount();

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClients);
	CurrentClient.AccountBalance += DepositAmount;
}

void ShowDepositScreen()
{
	system("cls");
	cout << "\n===================================================\n";
	cout << "\t\t\Deposit Screen";
	cout << "\n===================================================\n";
	PerformDepositOption();
}

void ShowCheckBalanceScreen()
{
	system("cls");
	cout << "\n===================================================\n";
	cout << "\t\tCheck Balance Screen";
	cout << "\n===================================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
}

int ReadWithDrawAmount()
{
	int Amount = 0;

	cout << "\n\Enter an amount multiple of 5's : ";
	cin >> Amount;

	while (Amount % 5 != 0)
	{
		cout << "\n\Enter an amount multiple of 5's : ";
		cin >> Amount;
	}

	return Amount;
}

void PerformNormalWithDrawOption()
{
	int WithDrawBalance = ReadWithDrawAmount();

	//Validate that the amount does not exceeds the balance
	while (WithDrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount Exceeds your balance , make another choice.";
		cout << "\nPress Anykey to continue...";
		system("pause>0");
		ShowNormalWithDrawScreen();
		return;
	}
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients);
	CurrentClient.AccountBalance -= WithDrawBalance;
}

void ShowNormalWithDrawScreen()
{
	system("cls");
	cout << "\n===================================================\n";
	cout << "\t\t\Normal Withdraw Screen :-)";
	cout << "\n===================================================\n";
	PerformNormalWithDrawOption();
}

void ShowQuickWithdrawScreen()
{
	system("cls");
	cout << "\n===================================================\n";
	cout << "\t\t\Quick Withdraw Screen :-)";
	cout << "\n===================================================\n";
	cout << "\t[1] 20\t\t[2] 50\n ";
	cout << "\t[3] 100\t\t[4] 200\n ";
	cout << "\t[5] 400\t\t[6] 600\n ";
	cout << "\t[7] 800\t\t[8] 1000\n ";
	cout << "\t[9] Exit\n";
	cout << "\n===================================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance;

	PerformQuickWithDrawOption(ReadQuickWithdrawOption());

}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to ATM main menu...";
	system("pause>0");
	ShowMainMenu();

}

short ReadMainMainMenuOption()
{
	cout << "Choice What do you want to do? [1 to 5]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOptions)
{
	switch (MainMenuOptions)
	{
	case enMainMenuOptions::eQuickWithdraw:
		system("cls");
		ShowQuickWithdrawScreen(); // Quick Withdraw (Choice 1)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eNormalWithdraw:
		system("cls");
		ShowNormalWithDrawScreen(); // Normal Withdraw (Choice 2)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eDeposit:
		system("cls");
		ShowDepositScreen(); // Deposit (Choice 3)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eCheckBalance:
		system("cls");
		ShowCheckBalanceScreen(); // Check Balance (Choice 4)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eExit: // LogOut Of Program (Choice 5)
		system("cls");
		Login();
		break;
	}

}

void ShowMainMenu()
{
	system("cls");
	cout << "=============================================\n";
	cout << "\t\tATM Main Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "=============================================\n";
	PerformMainMenuOption(enMainMenuOptions(ReadMainMainMenuOption()));
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
	if (FindClientByUserAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
		return true;

	else
		return false;
}

void Login()
{

	bool LoginFailed = false;

	string AccountNumber, PinCode;

	do
	{
		system("cls");

		cout << "---------------------------------------------\n";
		cout << "\t\tLogin Screen\n";
		cout << "---------------------------------------------\n";

		if(LoginFailed)
			cout << "\nInvalid Account Number/PinCode!\n";

		cout << "Enter Account Number: ";
		cin >>  AccountNumber;

		cout << "enter PinCode: ";
		cin >> PinCode;

		LoginFailed = !LoadClientInfo(AccountNumber, PinCode);

	} while (LoginFailed);

	ShowMainMenu();


}

int main()
{

	Login();
	system("pause>0");
	return 0;
}

