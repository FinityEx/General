#include "hash_password.h"
#include "Registration.h"
#include "User.h"
#include "UserList.h"
#include <string>
#include <iostream>
#include <vector>
#include <sqlite3.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;



bool registration() {
	bool success = false;
	string username, password;


	cout << "Create new account: \n";
	cout << "Type in your login: ";
	std::getline(cin, username);


	cout << "Type in your password: ";
	std::getline(cin, password);

	string password_hashed = hash_password(password);
	UserList::AddUser(username, password_hashed);



	sqlite3* db;
	sqlite3_stmt* stmt;
	char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open("userbase.db", &db); //open SQL connection


	string sql_check = "select exists(select * from users where username = '" + username + "');"; //check if username already exists. Create if not

	sqlite3_prepare_v2(db, sql_check.c_str(), -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);

	std::string str;
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		str = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))); //SQL returns 1 if username exists
		
	}

	if (std::stoi(str)) { 
		std::cout << "User already exists!";
		success = false;
	}
	else {

		std::string sql = "CREATE TABLE " + username + "(number integer, entry_title text, entry text);";
		sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

		sql = "INSERT INTO USERS VALUES('" + username + "', '" + password_hashed + "', 0)";

		sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
		cout << "User has been added!" << endl;

		success = true;
	}

	return success;

}
