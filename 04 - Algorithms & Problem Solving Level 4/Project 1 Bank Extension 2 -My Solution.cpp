#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;



const string ClientsFileName = "ClientsRecord.txt";
const string UsersFileName = "Users.txt";


struct sUser
{
	string UserName = "";
	string Password = "";
	int Permission = 0;
	bool MarkForDelete = false;
};

sUser CurrentUser;

void ShowMainMenu(sUser);
void ShowTransactionsMenu(sUser);
void ShowManageUsersMenu(sUser);
void Login();



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

string ConvertRecordToLine_User(sUser User, string Separator = "#//#")
{
	string stUser = "";

	stUser += User.UserName + Separator;
	stUser += User.Password + Separator;
	stUser += to_string(User.Permission);
	

	return stUser;

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

sUser ConvertLineToRecord_Users(string Line, string Separator = "#//#")
{
	sUser User;
	vector <string> vUserData;
	vUserData = SplitString(Line, Separator);

	User.UserName = vUserData[0];
	User.Password = vUserData[1];
	User.Permission = stoi(vUserData[2]);



	return User;

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

bool UserExistsByUserName(string UserName, string FileName)
{

	vector <sUser> vUsers;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		sUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertLineToRecord_Users(Line);
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
	getline(cin, Client.PinCode);

	cout << "Please enter Name: ";
	getline(cin, Client.Name);

	cout << "Please enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Please enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

bool FindUserByUserNameAndPassword(string UserName, string Password, string FileName)
{
	vector <sUser> vUsers;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		sUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertLineToRecord_Users(Line);

			if (User.UserName == UserName && User.Password == Password)
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

sUser ReadLoginUser()
{
	sUser User;

	cout << "Enter UserName: ";
	getline(cin >> ws, User.UserName);

	cout << "enter Password: ";
	getline(cin, User.Password);

	while (!FindUserByUserNameAndPassword(User.UserName, User.Password, UsersFileName))
	{
		system("cls");

		cout << "---------------------------------------------\n";
		cout << "\t\tLogin Screen\n";
		cout << "---------------------------------------------\n";

		cout << "\nInvalid Username/Password!\n";


		cout << "Enter UserName: ";
		getline(cin >> ws, User.UserName);

		cout << "enter Password: ";
		getline(cin, User.Password);
	}
	::CurrentUser = User;
	return User;

}

int  ReadPermission()
{

	int Binary = 0;
	char Answer = 'y';
	cout << "\n\nDo you want to give full access? y/n ";
	cin >> Answer;


	if (Answer == 'y' || Answer == 'Y')
		Binary = stoi("-1");

	else
	{

		cout << "\n\nDo you want to access to: ";

		cout << "\n\nShow Client List? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary = (1 & 1);
		
			

		cout << "\n\nAdd New Client? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (2 & 3);
		



		cout << "\n\nDelete Client? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (4 & 5);
		



		cout << "\n\nUpdate Client? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (8 & 9);
		


		cout << "\n\nFind Clients? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (16 & 17);
		


		cout << "\n\nTransactions? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (32 & 33);
		


		cout << "\n\nManage System? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Binary += (64 & 65);
		

		
	}
	return Binary;
}

sUser ReadNewUser()
{
	sUser User;

	cout << "Enter UserName: ";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUserName(User.UserName, UsersFileName))
	{
		cout << "\nUser with [" << User.UserName << "] already exists , Enter another UserName: ";
		getline(cin >> ws, User.UserName);
	}

	cout << "enter Password: ";
	getline(cin, User.Password);

	User.Permission = ReadPermission();

	return User;

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

vector <sUser> LoadUserDataFromFile(string FileName)
{
	vector <sUser> vUsers;

	fstream MyFile;


	MyFile.open(UsersFileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		sUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertLineToRecord_Users(Line);
			vUsers.push_back(User);
		}
		MyFile.close();
	}

	return vUsers;
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintUserList(sUser User)
{
	cout << "| " << setw(15) << left << User.UserName;
	cout << "| " << setw(15) << left << User.Password;
	cout << "| " << setw(12) << left << User.Permission;
}

void PrintClientRecordBalanceLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
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

	if (vClients.size() == 0)
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

void ShowListUsers()
{
	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);


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
		for (sUser& User : vUsers)
		{
			PrintUserList(User);
			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";

	}

}

void ShowTotalBalances()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);


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
		for (sClient& Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			TotalBalances += Client.AccountBalance;

			cout << endl;
		}
		cout << "\n_______________________________________________________________________________________________\n\n";
		cout << "\t\t\t\tTotal Balance = " << TotalBalances;
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
	cout << "\n-----------------------------------\n";
}

void PrintUserCard(sUser User)
{
	cout << "\nThe following are the User details:\n";
	cout << "-----------------------------------";

	cout << "\nUser Name:  " << User.UserName;
	cout << "\nPassword:   " << User.Password;
	cout << "\nPermission: " << User.Permission;
	cout << "\n-----------------------------------\n";
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

bool FindUserByUserName(string UserName, vector <sUser> vUsers, sUser& User)
{

	for (sUser& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			User = U;
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

sUser ChangeUserRecord(string UserName)
{
	sUser User;

	User.UserName = UserName;

	cout << "\n\nPlease enter Password: ";
	getline(cin >> ws, User.Password);


	return User;
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

bool MarkUserDataForDeleteByUserName(string UserName, vector <sUser>& vUsers)
{
	for (sUser& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			U.MarkForDelete = true;
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

vector <sUser> SaveUsersDataToFile(string FileName, vector <sUser>& vUsers)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out); // overwrite

	string UserData;

	if (MyFile.is_open())
	{
		for (sUser& U : vUsers)
		{
			if (U.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				UserData = ConvertRecordToLine_User(U);

				MyFile << UserData << endl;
			}
		}

		MyFile.close();
	}

	return vUsers;
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

void AddUserDataLineToFile(string FileName, string UserLine)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);


	if (MyFile.is_open())
	{

		MyFile << UserLine << endl;

		MyFile.close();

	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddClientDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

enum enSystemAccess {
	NumberClientList = 1, NumberAddNewClient = 2,
	NumberDeleteClient = 4, NumberUpdateClient = 8, NumberFindClient = 16,
	NumberTransactions = 32, NumberManageUsers = 64
};








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

void AddNewUser()
{
	sUser User;
	User = ReadNewUser();
	AddUserDataLineToFile(UsersFileName, ConvertRecordToLine_User(User));

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

bool DeleteUserByUserName(string UserName, vector <sUser>& vUsers)
{
	sUser User;
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
			vUsers = LoadUserDataFromFile(UsersFileName);

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

bool UpdateUserByUserName(string UserName, vector <sUser>& vUsers)
{
	sUser User;
	char Answer = 'n';
	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);

		cout << "\n\nAre you sure you want update this User? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			for (sUser& U : vUsers)
			{
				if (U.UserName == UserName)
				{
					U = ChangeUserRecord(UserName);
					U.Permission = ReadPermission();
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

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient> vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to perform this Transaction? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		for (sClient& C : vClients)
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

void ShowDeleteClientScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tDelete Client Screen";
	cout << "\n---------------------------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowDeleteUserScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tDelete User Screen";
	cout << "\n---------------------------------------------------\n";

	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	string UserName = ReadUserName();
	DeleteUserByUserName(UserName, vUsers);

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

void ShowUpdateUserScreen()
{

	cout << "\n---------------------------------------------------\n";
	cout << "\t\tUpdate User Screen";
	cout << "\n---------------------------------------------------\n";

	string UserName = ReadUserName();
	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	UpdateUserByUserName(UserName, vUsers);

}

void ShowAddNewClientsScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tAdd New Clients Screen";
	cout << "\n---------------------------------------------------\n";
	AddNewClients();
}

void ShowAddNewUsersScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tAdd New Users Screen";
	cout << "\n---------------------------------------------------\n";
	AddNewUsers();

}

void ShowFindClientScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tFind Client Screen";
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

void ShowFindUserScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\tFind User Screen";
	cout << "\n---------------------------------------------------\n";

	vector <sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	sUser User;
	string UserName = ReadUserName();

	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);

	}
	else
	{
		cout << "\nUser With UserName (" << UserName << ") is Not Found.\n";

	}

}

void ShowLogoutScreen()
{
	Login();
}

void ShowDepositScreen()
{
	cout << "\n---------------------------------------------------\n";
	cout << "\t\t\Deposit Screen :-)";
	cout << "\n---------------------------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;
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

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;
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

enum enManageUsersMenuOptions {
	eListUser = 1, eAddNewUser = 2,
	eDeleteUser = 3, eUpdateUser = 4,
	eFindUser = 5, eShowMainMenu2 = 6
};

enum enTransactionsMenuOptions {
	eDeposit = 1, eWithdraw = 2,
	eShowTotalBalance = 3, eShowMainMenu = 4
};

enum enMainMenueOptions {
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6,
	eManageUsers = 7, eLogout = 8
};

void GoBackToMainMenu(sUser User)
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	ShowMainMenu(User);

}

void GoBackToTransactionsMenu(sUser User)
{
	cout << "\n\nPress any key to go back to Transactions menu...";
	system("pause>0");
	ShowTransactionsMenu(User);

}

void GoBackToManageUsersMenu(sUser User)
{
	cout << "\n\nPress any key to go back to ManageUsers menu...";
	system("pause>0");
	ShowManageUsersMenu(User);
}

short ReadTransactionsMenuOption()
{
	cout << "Choice What do you want to do? [1 to 4]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

short ReadManageUsersMenuOption()
{
	cout << "Choice What do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void PerformTransactions(sUser User, enTransactionsMenuOptions TransactionsOptions)
{
	switch (TransactionsOptions)
	{
	case enTransactionsMenuOptions::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu(User);
		break;
	case enTransactionsMenuOptions::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu(User);
		break;
	case enTransactionsMenuOptions::eShowTotalBalance:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenu(User);
		break;
	case enTransactionsMenuOptions::eShowMainMenu:
		ShowMainMenu(User);

	}

}

void PerformManageUsers(sUser& User, enManageUsersMenuOptions ManageUsersOptions)
{
	switch (ManageUsersOptions)
	{
	case enManageUsersMenuOptions::eListUser:
		system("cls");
		ShowListUsers();
		GoBackToManageUsersMenu(User);
		break;
	case enManageUsersMenuOptions::eAddNewUser:
		system("cls");
		ShowAddNewUsersScreen();
		GoBackToManageUsersMenu(User);
		break;
	case enManageUsersMenuOptions::eDeleteUser:
		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUsersMenu(User);
		break;
	case enManageUsersMenuOptions::eUpdateUser:
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUsersMenu(User);
		break;
	case enManageUsersMenuOptions::eFindUser:

		system("cls");
		ShowFindUserScreen();
		GoBackToManageUsersMenu(User);
		break;
	case enManageUsersMenuOptions::eShowMainMenu2:
		ShowMainMenu(User);

	}

}
void ShowTransactionsMenu(sUser User)
{
	system("cls");
	cout << "=============================================\n";
	cout << "\tTransactions Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "=============================================\n";
	PerformTransactions(User, (enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

void ShowManageUsersMenu(sUser User)
{
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
	PerformManageUsers(User, (enManageUsersMenuOptions)ReadManageUsersMenuOption());
}

short ReadMainMainMenuOption()
{
	cout << "Choice What do you want to do? [1 to 8]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

bool PermissionAccess(sUser User, short Number)
{

	vector <sUser> Users = LoadUserDataFromFile(UsersFileName);

	for (sUser& U : Users)
	{
		if (U.UserName == User.UserName)
		{
			if (to_string(U.Permission) == "-1")
				return true;




			switch (Number)
			{


			case enSystemAccess::NumberClientList:
				return ((Number & U.Permission) == Number) ? true : false;

			case enSystemAccess::NumberAddNewClient:
				return ((enSystemAccess::NumberAddNewClient & U.Permission) == enSystemAccess::NumberAddNewClient) ? true : false;

			case enSystemAccess::NumberDeleteClient:
				return	((Number & U.Permission) == Number) ? true : false;

			case enSystemAccess::NumberUpdateClient:
				return ((Number & U.Permission) == Number) ? true : false;

			case enSystemAccess::NumberFindClient:
				return	((Number & U.Permission) == Number) ? true : false;

			case enSystemAccess::NumberTransactions:
				return	((Number & U.Permission) == Number) ? true : false;

			case enSystemAccess::NumberManageUsers:
				return	((Number & U.Permission) == Number) ? true : false;
						
			}


		}

	}
	return false;

}

void PerformMainMenuOption(sUser User, enMainMenueOptions MainMenuOptions)
{


	switch (MainMenuOptions)
	{
	case enMainMenueOptions::eListClients:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberClientList))
		{
			ShowAllClientsScreen(); // Show All Clients Data (Choice 1)
			GoBackToMainMenu(User);
		}
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberAddNewClient))
		{
			ShowAddNewClientsScreen(); // 47 ADD Clients (Choice 2)
			GoBackToMainMenu(User);
		}
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;
	case enMainMenueOptions::eDeleteClient:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberDeleteClient))
		{
			ShowDeleteClientScreen(); // Delete Client Data By Account Number (Choice 3)
			GoBackToMainMenu(User);
		}
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;
	case enMainMenueOptions::eUpdateClient:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberUpdateClient))
		{
			ShowUpdateClientScreen(); // Update Client Data By Account Number (Choice 4)
			GoBackToMainMenu(User);
		}
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;
	case enMainMenueOptions::eFindClient:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberFindClient))
		{
			ShowFindClientScreen(); // Find Client Data By Account Number (Choice 5)
			GoBackToMainMenu(User);
		}
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;
	case enMainMenueOptions::eTransactions:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberTransactions))
			ShowTransactionsMenu(User); // Go to Transaction Menu (Choice 6)
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;

	case enMainMenueOptions::eManageUsers:
		system("cls");
		if (PermissionAccess(User, enSystemAccess::NumberManageUsers))
			ShowManageUsersMenu(User); // Go to Manage User Menu (Choice 7)
		else {
			cout << "\n---------------------------------------------------\n";
			cout << "Access Denied,\n";
			cout << "You don't Have Permission To Do this,\n";
			cout << "Please Connect Your Admin";
			cout << "\n---------------------------------------------------\n";

			GoBackToMainMenu(User);
		}
		break;

	case enMainMenueOptions::eLogout: // Logout of The Program (Choice 8)
		system("cls");
		ShowLogoutScreen();
		break;
	}

}

void ShowMainMenu(sUser User)
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
	PerformMainMenuOption(User, enMainMenueOptions(ReadMainMainMenuOption()));
}



void Login()
{

	cout << "---------------------------------------------\n";
	cout << "\t\tLogin Screen\n";
	cout << "---------------------------------------------\n";

	sUser User = ReadLoginUser();
	::CurrentUser = User;

	ShowMainMenu(CurrentUser);

}

int main()
{

	Login();
	system("pause>0");
	return 0;
}

