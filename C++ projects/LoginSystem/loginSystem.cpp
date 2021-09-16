//Basic database system with file streaming. Program checks if username file exists in local folder, then either lets user log-in or register. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int choice;
	std::string username, password;
	cout << "1. Register \n2. Login \nYour choice: ";
	cin >> choice; if (choice != 1 && choice != 2) cout << "Wrong choice!";

	switch (choice) {
	case 1:
	{
		cout << "Choose username: ";
		cin >> username;
		cout << "Choose password: ";
		cin >> password;
		ofstream User;
		User.open((username+".txt").c_str()); //keeping username and password in plain text is tremendously bad idea that wouldn't be used if this program's purpose wasn't learning new stuff. 
		User << username << "\n" << password << std::endl;
		User.close();
		cout << "User has been created! " << std::endl;
	}
		break;

	case 2:
		string line;
		cout << "Type in username: ";
		cin >> username;
		ifstream ifile;
		ifile.open((username+".txt").c_str()); 
		if (ifile) {
			cout << "Type in password: ";
			cin >> password;
			getline(ifile, line); //get the 1st line and do nothing with it, because we want to read the 2nd line
			getline(ifile, line);
			if (line == password) cout << "Successfully logged in!";
			else cout << "Wrong password!";
		}
		else {
			cout << "Username does not exist!" << endl;
		}
		break;
	}
	return 0;
}

