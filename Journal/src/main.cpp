#include <iostream>
#include <string>
#include <iomanip>
#include "User.h"
#include "hash_password.h"
#include "Registration.h"
#include "Login.h"
#include "Date.h"


using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(); //called when an user is deleted

int logged_user_choice(User* logged_user) {
	int choice;
	cout << "What would you like to do?\n\n";
	cout << "1. Show past entries\n2. Add new entry\n3. Change password\n4. Delete the account\n5. Exit\n";
	cout << "\nYour choice: ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
		cin.clear(); //clears bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Wrong choice!\nTry again: ";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		logged_user->show_entries();
		logged_user_choice(logged_user);
		break;
	case 2:
		logged_user->add_entry();
		logged_user_choice(logged_user);
		break;
	case 3:
		logged_user->change_password();
		logged_user_choice(logged_user);
		break;
	case 4:
		while (!logged_user->delete_user());
		main();
		break;
	case 5:
		system("cls");
		cout << "See you next time!";
		return 1;
		break;
	}
}


int main() {
	User* logged_user = NULL;
	int choice;
	 load_userbase();
	 cout << std::setw(50) << "Today is " << date();
	 cout << "\n\n\nWhat would you like to do?\n";
	 cout << "1. Login\n2. Register\n";
	 cout << "\nYour choice: ";
	 cin >> choice;
	 while (choice != 1 && choice != 2) {
		 cin.clear();
		 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		 cout << "Wrong choice!\nTry again: ";
		 cin >> choice;
	 }
	 switch (choice) {
	 case 1:
		 do { //login until successful
			 logged_user = login();
		 } while (logged_user == NULL); 
		 break;
	 case 2:
		 cin.ignore(); //ignore input not to break registration function
		 while (!registration());
		cout << "\nNow log in: \n";
		do {
			logged_user = login();
		} while (logged_user == NULL);
		 break;
	 };
	 system("cls");
	 cout << std::setw(50) << "Hello " << logged_user->get_username() << "!" << endl;
	 while (logged_user_choice(logged_user) != 1);

	return 0;
}

