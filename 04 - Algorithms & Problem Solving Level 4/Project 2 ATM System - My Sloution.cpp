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


enum enATMMainMenuOptions {eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3,  
						   eCheckBalance = 4,  eExit = 5 };

enum enQuickWithdrawAmount {
	One = 20, Two = 50, Three = 100, Four = 200, Five = 400,
	Six = 600, Seven = 800, Eight = 1000, Exit = 9
};

void ShowATMMainMenu();
void Login();


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


vector <stClient> SaveClientsDataToFile(string FileName)
{
	fstream MyFile;

	vector <stClient> vClients = LoadClientsDataFromFile(FileName);

	

	MyFile.open(FileName, ios::out); // overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)			
				C.AccountBalance = CurrentClient.AccountBalance;
				
				DataLine = ConvertRecordToLine(C);

				MyFile << DataLine << endl;
			
		}

		MyFile.close();
	}

	return vClients;
}


bool FindClientByUserAccountNumberAndPinCode(string UserName, string Password, stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient C : vClients)
	{
		if (C.AccountNumber == UserName && C.PinCode == Password)
		{
			Client = C;
			return true;
		}
	}
	return false;

}


bool DepositBalanceToClientByAccountNumber(double Amount, stClient Client)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to perform this Transaction? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
	CurrentClient.AccountBalance += Amount;
	SaveClientsDataToFile(ClientsFileName);
	cout << "\n\nDone Successfully . New Balance is " << CurrentClient.AccountBalance;
	return true;
	}
	return false;
}


void GoBackToATMMainMenu()
{
	cout << "\n\nPress any key to go back to ATM main menu...";
	system("pause>0");
	ShowATMMainMenu();

}

short ReadATMMainMainMenuOption()
{
	cout << "Choice What do you want to do? [1 to 5]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

short ReadQuickWithdraw()
{
	cout << "Choice What to Withdraw from [1] to [9] ? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

bool CheckQuickAmount(enQuickWithdrawAmount Choice)
{
	if (Choice < CurrentClient.AccountBalance)
		return true;
	
	else
	{
		cout << "\nThe amount Exceeds your balance , make another choice.";
		GoBackToATMMainMenu();
		return false;
	}
		

}

void QuickWithdraw(enQuickWithdrawAmount QuickWithdrawAmount)
{


	switch (QuickWithdrawAmount)
	{
	case 1:
		CheckQuickAmount(One);
		DepositBalanceToClientByAccountNumber(One * -1, CurrentClient);
		break;

	case 2:
		CheckQuickAmount(Two);
		DepositBalanceToClientByAccountNumber(Two * -1, CurrentClient);
		break;

	case 3:
		CheckQuickAmount(Three);
		DepositBalanceToClientByAccountNumber(Three * -1, CurrentClient);
		break;
	case 4:
		CheckQuickAmount(Four);
		DepositBalanceToClientByAccountNumber(Four * -1, CurrentClient);
		break;

	case 5:
		CheckQuickAmount(Five);
		DepositBalanceToClientByAccountNumber(Five * -1, CurrentClient);
		break;

	case 6:
		CheckQuickAmount(Six);
		DepositBalanceToClientByAccountNumber(Six * -1, CurrentClient);
		break;

	case 7:
		CheckQuickAmount(Seven);
		DepositBalanceToClientByAccountNumber(Seven * -1, CurrentClient);
		break;

	case 8:
		CheckQuickAmount(Eight);
		DepositBalanceToClientByAccountNumber(Eight * -1, CurrentClient);
		break;
	case 9:
		GoBackToATMMainMenu();
		break;

	}

}

void ShowQuickWithdrawScreen()
{
	cout << "\n===================================================\n";
	cout << "\t\t\Quick Withdraw Screen :-)";
	cout << "\n===================================================\n";

	cout <<  "[1] 20     [2] 50\n";
	cout <<  "[3] 100    [4] 200\n";
	cout <<  "[5] 400    [6] 600\n";
	cout <<  "[7] 800    [8] 1000\n";
	cout <<  "[9] Exit";
	cout << "\n===================================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << endl << endl;

	short Choice = ReadQuickWithdraw();
	
	QuickWithdraw(enQuickWithdrawAmount(Choice));


}

void ShowNormalDrawScreen()
{
	cout << "\n===================================================\n";
	cout << "\t\t\Normal Withdraw Screen :-)";
	cout << "\n===================================================\n";

	cout << "\n\Enter an  multiple of 5's amount : ";
	int WithdrewAmount = 0;
	cin >> WithdrewAmount;

	while (WithdrewAmount % 5 != 0)
	{
		cout << "\n\Enter an  multiple of 5's amount : ";
		cin >> WithdrewAmount;
	}

	//Validate that the amount does not exceeds the balance
	while (WithdrewAmount > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount Exceeds your balance , make another choice.";
		cout << "\nPress any key to continue\n";
		system("pause>0");
		cout << "\n\Enter an  multiple of 5's amount : ";
		cin >> WithdrewAmount;
	}


	DepositBalanceToClientByAccountNumber(WithdrewAmount * -1, CurrentClient);

}

void ShowDepositScreen()
{
	cout << "\n===================================================\n";
	cout << "\t\t\Deposit Screen";
	cout << "\n===================================================\n";

	double DepositAmount = 0;

	do
	{
		cout << "\n\nEnter a Positive deposit amount: ";
		cin >> DepositAmount;
	} while (DepositAmount < 0);



	DepositBalanceToClientByAccountNumber(DepositAmount, CurrentClient);
}

void ShowCheckBalanceScreen()
{
	cout << "\n===================================================\n";
	cout << "\t\tCheck Balance Screen";
	cout << "\n===================================================\n";

	cout << "Your Balance is " << CurrentClient.AccountBalance;

	GoBackToATMMainMenu();
}


void PerformATMMainMenuOption(enATMMainMenuOptions ATMMainMenuOptions)
{
	switch (ATMMainMenuOptions)
	{
	case enATMMainMenuOptions::eQuickWithdraw:
		system("cls");
		ShowQuickWithdrawScreen(); // Quick Withdraw (Choice 1)
		GoBackToATMMainMenu();
		break;

	case enATMMainMenuOptions::eNormalWithdraw:
		system("cls");
		ShowNormalDrawScreen(); // Normal Withdraw (Choice 2)
		GoBackToATMMainMenu();
		break;

	case enATMMainMenuOptions::eDeposit:
		system("cls");
		ShowDepositScreen(); // Deposit (Choice 3)
		GoBackToATMMainMenu();
		break;

	case enATMMainMenuOptions::eCheckBalance:
		system("cls");
		ShowCheckBalanceScreen(); // Check Balance (Choice 4)
		GoBackToATMMainMenu();
		break;

	case enATMMainMenuOptions::eExit: // LogOut Of Program (Choice 5)
		system("cls");
		//ShowEndScreen();
		Login();
		break;
	}

}


void ShowATMMainMenu()
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
	PerformATMMainMenuOption(enATMMainMenuOptions(ReadATMMainMainMenuOption()));
}

bool LoadUserInfo(string AccountNumber, string PinCode)
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

		LoginFailed = !LoadUserInfo(AccountNumber, PinCode);

	} while (LoginFailed);

	ShowATMMainMenu();


}

int main()
{

	Login();
	system("pause>0");
	return 0;
}

