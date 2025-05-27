#include <iostream>
#include <string>
using namespace std;


string ReadName()
{
	string Password;

	cout << "Please enter a 3-Letter Password (all capital)?\n";
	cin >> Password;


	return Password;
}


bool GuessPassword(string OriginalPassword)
{
	
	cout << "\n";
	string Word = "";
	int Number = 0;
	for (int Counter1 = 65; Counter1 <= 90; Counter1++)
	{


		for (int Counter2 = 65; Counter2 <= 90; Counter2++)
		{
			for (int Counter3 = 65; Counter3 <= 90; Counter3++)
			{
				Number++;


				Word += char(Counter1);
				Word += char(Counter2);
				Word += char(Counter3);
				
				cout << "Trial [" << Number << "] " << Word << endl;
				if (Word == OriginalPassword)
				{
					
					cout << "\nPassword is: " << Word << "\n";
					cout << "Found after " << Number << " Trail(s)\n";
					return true;
				}
				Word = "";

			}


		}

		cout << "\n----------------------\n";
	}

	return false;
}





int main()
{

	GuessPassword(ReadPassword());



	return 0;

}
