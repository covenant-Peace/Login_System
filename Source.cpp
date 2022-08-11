#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn();

int main()
{
	int choice;

	cout << "1. Register \n2. Login \n\nYour choice: ";
	cin >> choice;

	if (choice == 1)
	{
		string username, password;

		cout << "Select a username: ";
		cin >> username;

		cout << "Select a password: ";
		cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "False Login!" << endl;
		}
		else
			cout << "Successfully logged in!" << endl;
	}
	return 0;
}

bool IsLoggedIn()
{
	string username, password, username1, password1;

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, username1);
	getline(read, password1);

	if (username1 == username and password1 == password)
	{
		return true;
	}
	else
		return false;
}
