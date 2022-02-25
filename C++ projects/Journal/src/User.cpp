#include <iostream>
#include <string>
#include <sqlite3.h>
#include <fstream>
#include "User.h"
#include "Login.h"
#include "Date.h"
#include "sha256.h"

using std::cout;
using std::cin;
using std::endl;


User::User(const string& username, const string& password) : username_{ username }, password_hash_{ password }{} //class constructor being fed username and hashed password

const string& User::get_password() const {
	return password_hash_;
}

const string& User::get_username() const {
	return username_;
}

void User::change_password() {
	string password_check;
	cout << "\nType in your current password: " << endl;
	cin.ignore();
	std::getline(cin, password_check);

	if (sha256(password_check) == password_hash_) { //check if hash matches with the one in database
		string new_password;

		cout << "Type in your new password: " << endl;
		std::getline(cin, new_password);

		password_hash_ = sha256(new_password);

		cout << "Password changed!" << endl;


		sqlite3* db;

		char* zErrMsg = 0;
		int rc;
		std::string sql;

		// Open database 
		rc = sqlite3_open("userbase.db", &db);


		sql = "update users set hashed_password = '" + password_hash_ + "' where username = '" + username_ + "';"; //update password in database


		// Execute SQL statement 
		rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
	}
	else {
		cout << "Wrong password!";
	}
}


void User::add_entry() {
	std::string text;
	std::string line;
	std::fstream file;
	


	file.open("C:\\entry.txt", std::ios::in|std::ios::out | std::ios::trunc); //create temp file for new entries to be written in
	if (file.is_open()) {
		system("notepad.exe C:\\entry.txt"); //invoke Windows notepad and open the temp file for user to type in...
		while (std::getline(file, line)) { //...then add its content into text string
			text += line + "\n";
		}
	}
	file.close();
	std::remove("C:\\entry.txt"); //remove temp file for privacy

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;

	// Open database 
	rc = sqlite3_open("userbase.db", &db);


	sql = "insert into " + username_ + " (entry_title, entry) values('" + date() + "', '" + text + "');"; //insert string filled with entry content into user's table

	// Execute SQL statement 
	rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

	sqlite3_close(db);
	}
	
void User::show_entries() {
	sqlite3* db;
	sqlite3_stmt* stmt;
	char* zErrMsg = 0;
	int rc;
	std::string sql;
	std::fstream file;
	std::string line;

	// Open database 
	rc = sqlite3_open("userbase.db", &db);

	sql = "select entry_title from " + username_ + ";"; //show entries titles to choose from
	sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

	sqlite3_bind_int(stmt, 1, 16);

	int i = 0;
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {                                          
		std::cout << ++i << ". " << sqlite3_column_text(stmt, 0) << endl; //print out entry titles
	}

	if (i == 0) cout << "No entries found!";
	else {
		cout << "\nWhich entry would you like to open?\n";
		cout << "Your choice: ";
		std::string k;  
		cin >> k;

		sql = "select entry from " + username_ + " where rowid = " + k + ";";
		sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

		sqlite3_bind_int(stmt, 1, 16);

		std::string text;
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {  //add content of database into string...
			text += std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))) + "\n";
		}
		file.open("C:\\entry.txt", std::ios::in | std::ios::out | std::ios::trunc);
		file << text; //...that is then added into temporary .txt file to be opened with windows' notepad
		file.close();
		system("notepad.exe C:\\entry.txt"); 

		text = ""; //reset string's content to avoid duplicates

		//update the entry in database in case user changes its content
		file.open("C:\\entry.txt", std::ios::in | std::ios::out); 
		if (file.is_open()) {
			while (std::getline(file, line)) {
				text += line + "\n";
			}
		}
		file.close();

		sql = "update " + username_ + " set entry = '" + text + "' where rowid = " + k + ";";
		sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
		std::remove("C:\\entry.txt");
	}

}

bool User::delete_user(){ 
	std::string password_check{};
	bool success = false;

	cout << "Type in your current password: ";
	cin >> password_check;
	if (sha256(password_check) == password_hash_) { //request password and compare hashes
		sqlite3* db;

		char* zErrMsg = 0;
		int rc;
		std::string sql;

		// Open database 
		rc = sqlite3_open("userbase.db", &db);


		sql = "delete from users where username = '" + username_ + "';";
		rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

		sql = "drop table " + username_ + ";";
		rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

		sqlite3_close(db);
		cout << "Username has been deleted!" << endl;
		success = true;
	}
	else cout << "Wrong password!\n";

	return success;
}