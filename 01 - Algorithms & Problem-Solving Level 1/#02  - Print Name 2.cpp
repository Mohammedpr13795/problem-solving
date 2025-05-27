/*
Ask the user to enter his or her name
print it on the screen
*/
#include <iostream>
#include <string>

using namespace std;

string ReadName() {
	string Name;

	cout << "Please enter your name: " << endl;
	getline(cin, Name);
	return Name;
}

void PrintName(string Name)
{
	cout << "\nYour name is: " << Name << endl;

}

int main() {


	PrintName(ReadName());



	return 0;
}