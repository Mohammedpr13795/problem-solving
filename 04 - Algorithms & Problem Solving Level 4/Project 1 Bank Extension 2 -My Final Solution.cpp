#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";



struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string  Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;

};

struct stUser
{
	string UserName = "";
	string Password = "";
	int Permission = 0;
	bool MarkForDelete = false;
};

enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenu = 4 };
enum enManageUsersMenuOptions  {
	eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, 
	eUpdateUser = 4, eFindUser = 5,  eMainMenu = 6
};
enum enMainMenuOptions {
	eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6, eManageUsers = 7, eExit = 8
};
enum enMainMenuPermissions {
	eAll = -1, pListClients = 1, pAddNewClient = 2,
	pDeleteClient = 4, pUpdateClients = 8, pFindClient = 16,
	pTranactions = 32, pManageUsers = 64
};

void ShowMainMenu();
void ShowTransactionsMenu();
void ShowManageUsersMenu();
bool CheckAccessPermission(enMainMenuPermissions Permission);
void Login();

stUser CurrentUser;

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

stUser ConvertUserLineToRecord(string Line, string Separator = "#//#")
{
	stUser User;
	vector <string> vUserData;
	vUserData = SplitString(Line, Separator);

	User.UserName = vUserData[0];
	User.Password = vUserData[1];
	User.Permission = stoi(vUserData[2]);

	return User;

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



string ConvertUserRecordToLine(stUser User, string Separator = "#//#")
{
	string stUserRecord = "";

	stUserRecord += User.UserName + Separator;
	stUserRecord += User.Password + Separator;
	stUserRecord += to_string(User.Permission);


	return stUserRecord;

}


bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector <stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

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

bool UserExistsByUserName(string UserName, string FileName)
{

	vector <stUser> vUsers;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		stUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);
			if (User.UserName == UserName)
			{
				MyFile.close();
				return true;
			}
			vUsers.push_back(User);
		}
		MyFile.close();
	}
	return false;
}

stClient ReadNewClient()
{
	stClient Client;
	cout << "Enter Account Number: ";

	// Usage of std::ws will extract all the whitespace character
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists , Enter another Account Number: ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Please enter PinCode: ";
	getline(cin, Client.PinCode);

	cout << "Please enter Name: ";
	getline(cin, Client.Name);

	cout << "Please enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Please enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

int  ReadPermissionsToSet()
{

	int Permissions = 0;
	char Answer = 'n';

	cout << "\n\nDo you want to give full access? y/n ";
	cin >> Answer;


	if (Answer == 'y' || Answer == 'Y')
		return -1;

	

		cout << "\nDo you want to access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pListClients;



		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pAddNewClient;




		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pDeleteClient;




		cout << "\n\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pUpdateClients;



		cout << "\nFind Clients? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pFindClient;



		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pTranactions;



		cout << "\nManage System? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enMainMenuPermissions::pManageUsers;

	return Permissions;
}

stUser ReadNewUser()
{
	stUser User;


	// Usage of std::ws will extract all the whitespace character
	cout << "Enter UserName: ";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUserName(User.UserName, UsersFileName))
	{
		cout << "\nUser with [" << User.UserName << "] already exists , Enter another UserName: ";
		getline(cin >> ws, User.UserName);
	}

	cout << "enter Password: ";
	getline(cin, User.Password);

	User.Permission = ReadPermissionsToSet();

	return User;

}

vector <stUser> LoadUsersDataFromFile(string FileName)
{
	vector <stUser> vUsers;

	fstream MyFile;


	MyFile.open(UsersFileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		stUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);
			vUsers.push_back(User);
		}
		MyFile.close();
	}

	return vUsers;
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

void PrintClientRecordLine(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintUserRecordLine(stUser User)
{
	cout << "| " << setw(15) << left << User.UserName;
	cout << "| " << setw(10) << left << User.Password;
	cout << "| " << setw(40) << left << User.Permission;
}

void PrintClientRecordBalanceLine(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAccessDeniedMessage()
{
	cout << "\n---------------------------------------------------\n";
	cout << "Access Denied,\nYou don't Have Permission To Do this,\nPlease Connect Your Admin.";
	cout << "\n---------------------------------------------------\n";
}

void ShowAllClientsScreen()
{

	if (!CheckAccessPermission(enMainMenuPermissions::pListClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);


	cout << "\n\t\t\t\t\t" << "Client List " << "(" << vClients.size() << ")" << " Client(s).";
	cout << "\n______________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________________________________________________\n\n";

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
	{
		for (stClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";

	}

}

void ShowAllUsersScreen()
{
	vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);


	cout << "\n\t\t\t\t\t" << "Users List " << "(" << vUsers.size() << ")" << " Client(s).";
	cout << "\n______________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(15) << "Client Name";
	cout << "| " << left << setw(15) << "Password";
	cout << "| " << left << setw(12) << "Permission";
	cout << "\n_______________________________________________________________________________________________\n\n";

	if (vUsers.size() == 0)
		cout << "\t\t\t\tNo Users Available In the System!";
	else
	{
		for (stUser User : vUsers)
		{
			PrintUserRecordLine(User);
			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";

	}

}

void ShowTotalBalances()
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);


	cout << "\n\t\t\t\t\t" << "Client List " << "(" << vClients.size() << ")" << " Client(s).";
	cout << "\n______________________________________________________________________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________________________________________________\n\n";

	double TotalBalances = 0;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
	{
		for (stClient& Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			TotalBalances += Client.AccountBalance;

			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";
		cout << "\t\t\t\tTotal Balance = " << TotalBalances;
	}
}

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPhin Code     : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}

void PrintUserCard(stUser User)
{
	cout << "\nThe following are the User details:\n";
	cout << "-----------------------------------";

	cout << "\nUser Name :  " << User.UserName;
	cout << "\nPassword  :   " << User.Password;
	cout << "\nPermission: " << User.Permission;
	cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool FindUserByUserName(string UserName, vector <stUser> vUsers, stUser& User)
{

	for (stUser& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool FindUserByUserNameAndPassword(string UserName, string Password, stUser& User)
{
	vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	for (stUser U : vUsers)
	{
		if (U.UserName == UserName && U.Password == Password)
		{
			User = U;
			return true;
		}
	}
	return false;

}

stClient ChangeClientRecord(string AccountNumber)
{
	stClient Client;

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

stUser ChangeUserRecord(string UserName)
{
	stUser User;

	User.UserName = UserName;

	cout << "\n\nPlease enter Password: ";
	getline(cin >> ws, User.Password);

	User.Permission = ReadPermissionsToSet();

	return User;
}

bool MarkClientDataForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return	true;
		}
	}
	return false;
}

bool MarkUserDataForDeleteByUserName(string UserName, vector <stUser>& vUsers)
{
	for (stUser& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			U.MarkForDelete = true;
			return	true;
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

vector <stUser> SaveUsersDataToFile(string FileName, vector <stUser>& vUsers)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out); // overwrite

	string UserData;

	if (MyFile.is_open())
	{
		for (stUser U : vUsers)
		{
			if (U.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				UserData = ConvertUserRecordToLine(U);

				MyFile << UserData << endl;
			}
		}

		MyFile.close();
	}

	return vUsers;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << stDataLine << endl;

		MyFile.close();

	}
}

void AddNewClient()
{
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewUser()
{
	stUser User;
	User = ReadNewUser();
	AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));

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

void AddNewUsers()
{

	char AddMoreUser = 'Y';

	do
	{
		//system("cls");
		cout << "Adding New User:\n\n";
		AddNewUser();
		cout << "\nUser Added Successfully , do you want to add more User? ";
		cin >> AddMoreUser;

	} while (toupper(AddMoreUser == 'y'));

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	stClient Client;
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

bool DeleteUserByUserName(string UserName, vector <stUser>& vUsers)
{
	stUser User;
	char Answer = 'n';
	if (FindUserByUserName(UserName, vUsers, User))
	{

		if (UserName == "Admin")
		{
			cout << "\n\nYou cannot Delete this user.";
			return true;
		}

		PrintUserCard(User);

		cout << "\n\nAre you sure you want delete this User? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			MarkUserDataForDeleteByUserName(UserName, vUsers);
			SaveUsersDataToFile(UsersFileName, vUsers);

			//Refresh Users
			vUsers = LoadUsersDataFromFile(UsersFileName);

			cout << "\n\nClient Deleted Successfully.";
			return	true;

		}
	}
	else
	{
		cout << "\nUser With UserName (" << UserName << ") is Not Found!";
		return	false;
	}

}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
	stClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			for (stClient& C : vClients)
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

bool UpdateUserByUserName(string UserName, vector <stUser>& vUsers)
{
	stUser User;
	char Answer = 'n';
	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);

		cout << "\n\nAre you sure you want update this User? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			for (stUser& U : vUsers)
			{
				if (U.UserName == UserName)
				{
					U = ChangeUserRecord(UserName);
					break;
				}
			}


			SaveUsersDataToFile(UsersFileName, vUsers);


			cout << "\n\nUser updated Successfully.";
			return	true;
		}
	}
	else
	{
		cout << "\nUser With UserName (" << UserName << ") is Not Found!";
		return	false;
	}
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

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "Please enter the account Number: ";
	cin >> AccountNumber;
	return AccountNumber;
}

string ReadUserName()
{
	string UserName = "";

	cout << "Please enter the UserName: ";
	cin >> UserName;
	return UserName;
}

void ShowListUsersScreen()
{
	ShowAllUsersScreen();
}

void ShowAddNewUsersScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tAdd New Users Screen";
	cout << "\n---------------------------------------------------\n";
	AddNewUsers();

}

void ShowDeleteUserScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tDelete User Screen";
	cout << "\n---------------------------------------------------\n";

	vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
	string UserName = ReadUserName();
	DeleteUserByUserName(UserName, vUsers);

}

void ShowUpdateUserScreen()
{

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tUpdate User Screen";
	cout << "\n---------------------------------------------------\n";

	string UserName = ReadUserName();
	vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
	UpdateUserByUserName(UserName, vUsers);

}

void ShowDeleteClientScreen()
{

	if (!CheckAccessPermission(enMainMenuPermissions::pDeleteClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tDelete Client Screen";
	cout << "\n---------------------------------------------------\n";

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{


	if (!CheckAccessPermission(enMainMenuPermissions::pUpdateClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tUpdate Client Screen";
	cout << "\n---------------------------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pAddNewClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tAdd New Clients Screen";
	cout << "\n---------------------------------------------------\n";
	AddNewClients();
}

void ShowFindClientScreen()
{

	if (!CheckAccessPermission(enMainMenuPermissions::pFindClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n---------------------------------------------------\n";
	cout << "\n\Find Client Screen";
	cout << "\n---------------------------------------------------\n";

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	stClient Client;
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

void ShowFindUserScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tFind User Screen";
	cout << "\n-----------------------------------\n";

	vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
	stUser User;
	string Username = ReadUserName();
	if (FindUserByUserName(Username, vUsers, User))
		PrintUserCard(User);
	else
		cout << "\nUser with Username [" << Username << "] is not found!";

}

void ShowEndScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tProgram Ends :-)";
	cout << "\n---------------------------------------------------\n";
}

void ShowDepositScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\t\Deposit Screen :-)";
	cout << "\n---------------------------------------------------\n";

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	stClient Client;
	string AccountNumber = ReadClientAccountNumber();
	char Answer = 'n';


	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient With Account Number [" << AccountNumber << "] does Not exit.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double DepositAmount = 0;
	cout << "\n\nPlease enter deposit amount: ";
	cin >> DepositAmount;

	DepositBalanceToClientByAccountNumber(AccountNumber, DepositAmount, vClients);


}

void ShowWithdrawScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\t\Withdrew Screen :-)";
	cout << "\n---------------------------------------------------\n";

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	stClient Client;
	string AccountNumber = ReadClientAccountNumber();
	char Answer = 'n';

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient With Account Number [" << AccountNumber << "] does Not exit.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	cout << "\n\nPlease enter withdrew amount: ";
	double WithdrewAmount = 0;
	cin >> WithdrewAmount;

	//Validate that the amount does not exceeds the balance
	while (WithdrewAmount > Client.AccountBalance)
	{
		cout << "Amount Exceeds the balance , you can withdraw up to : " << Client.AccountBalance;
		cout << "\nPlease enter another amount: ";
		cin >> WithdrewAmount;
	}

	DepositBalanceToClientByAccountNumber(AccountNumber, WithdrewAmount * -1, vClients);

}

void ShowTotalBalancesScreen()
{
	ShowTotalBalances();
}

bool CheckAccessPermission(enMainMenuPermissions Permission)
{
	if (CurrentUser.Permission == enMainMenuPermissions::eAll)
		return true;

	if ((Permission & CurrentUser.Permission) == Permission)
		return true;

	else
		return false;
}


void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	ShowMainMenu();

}

void GoBackToTransactionsMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	ShowTransactionsMenu();

}

void GoBackToManageUsersMenu()
{
	cout << "\n\nPress any key to go back to ManageUsers menu...";
	system("pause>0");
	ShowManageUsersMenu();
}

short ReadTransactionsMenuOption()
{
	cout << "Choice What do you want to do? [1 to 4]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void PerformTransactions(enTransactionsMenuOptions TransactionsOptions)
{
	switch (TransactionsOptions)
	{
	case enTransactionsMenuOptions::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenuOptions::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenuOptions::eShowTotalBalance:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenuOptions::eShowMainMenu:
		ShowMainMenu();
	
	}

}

void ShowTransactionsMenu()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pTranactions))
	{
		ShowAccessDeniedMessage();
		return;
	}

	system("cls");
	cout << "=============================================\n";
	cout << "\tTransactions Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "=============================================\n";
	PerformTransactions((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

short ReadMainMainMenuOption()
{
	cout << "Choice What do you want to do? [1 to 8]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOptions)
{
	switch (ManageUsersMenuOptions)
	{
	case enManageUsersMenuOptions::eListUsers:
		system("cls");
		ShowListUsersScreen();
		GoBackToManageUsersMenu();
		break;

	case enManageUsersMenuOptions::eAddNewUser:
		system("cls");
		ShowAddNewUsersScreen();
		GoBackToManageUsersMenu();
		break;

	case enManageUsersMenuOptions::eDeleteUser:
		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUsersMenu();
		break;

	case enManageUsersMenuOptions::eUpdateUser:
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUsersMenu();
		break;

	case enManageUsersMenuOptions::eFindUser:
		system("cls");
		ShowFindUserScreen();
		GoBackToManageUsersMenu();
		break;

	case enManageUsersMenuOptions::eMainMenu:
		ShowMainMenu();

	}

}

short ReadManageUsersMenuOption()
{
	cout << "Choice What do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void ShowManageUsersMenu()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pManageUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}

	system("cls");
	cout << "=============================================\n";
	cout << "\tManage Users Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menu.\n";
	cout << "=============================================\n";

	PerformManageUsersMenuOption((enManageUsersMenuOptions)ReadManageUsersMenuOption());
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOptions)
{
	switch (MainMenuOptions)
	{
	case enMainMenuOptions::eListClients:
		system("cls");
		ShowAllClientsScreen(); // Show All Clients Data (Choice 1)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen(); // 47 ADD Clients (Choice 2)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen(); // Delete Client Data By Account Number (Choice 3)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen(); // Update Client Data By Account Number (Choice 4)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eFindClient:
		system("cls");
		ShowFindClientScreen(); // Find Client Data By Account Number (Choice 5)
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eTransactions:
		system("cls");
		ShowTransactionsMenu(); // Go to Transaction Menu (Choice 6)
		break;

	case enMainMenuOptions::eManageUsers:
		system("cls");
		ShowManageUsersMenu(); // Go to Manage User Menu (Choice 7)
		break;

	case enMainMenuOptions::eExit: // LogOut Of Program (Choice 8)
		system("cls");
		//ShowEndScreen();
		Login();
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
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "=============================================\n";
	PerformMainMenuOption(enMainMenuOptions(ReadMainMainMenuOption()));
}

bool LoadUserInfo(string UserName, string Password)
{
	if (FindUserByUserNameAndPassword(UserName, Password, CurrentUser))
		return true;

	else
		return false;
}

void Login()
{

	bool LoginFailed = false;

	string UserName, Password;

	do
	{
		system("cls");

		cout << "---------------------------------------------\n";
		cout << "\t\tLogin Screen\n";
		cout << "---------------------------------------------\n";

		if(LoginFailed)
			cout << "\nInvalid Username/Password!\n";

		cout << "Enter UserName: ";
		cin >>  UserName;

		cout << "enter Password: ";
		cin >> Password;

		LoginFailed = !LoadUserInfo(UserName, Password);

	} while (LoginFailed);

	ShowMainMenu();


}

int main()
{

	Login();
	system("pause>0");
	return 0;
}

