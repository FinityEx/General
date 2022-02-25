#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "Login.h"
#include "UserList.h"
#include "sha256.h"


void load_userbase() {
	std::string line;
	std::string username;
	std::string password;

	sqlite3* db;
	sqlite3_stmt* stmt;

	char* zErrMsg = 0;
	int rc;

	std::string sql;
	std::string sql_check;

	// Open database 
	rc = sqlite3_open("userbase.db", &db);

	//checks if table already exists in database. Creates new one if not
	sql_check = "CREATE TABLE IF NOT EXISTS users (username text primary key, hashed_password text not null, entries_count integer);";
	sqlite3_exec(db, sql_check.c_str(), 0, 0, &zErrMsg);
	sql_check = "CREATE TABLE IF NOT EXISTS entries(number integer, username text, entry_title text, entry text);";
	sqlite3_exec(db, sql_check.c_str(), 0, 0, &zErrMsg);


	sqlite3_prepare_v2(db, "select * from users;", -1, &stmt, NULL);

	sqlite3_bind_int(stmt, 1, 16);

	//callbacks from SQL binded to string variables
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {                                          
		username = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		password = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));

		UserList::AddUser(username, password); //adds user to a vector - to be changed
	}

}


User* login() {
	int logged_in;
	static User* ptr_to_usr = NULL;

	std::string username, password;
	std::string hashed_password;


	std::cout << "Enter your username: ";
	std::cin >> username;
	std::cout << "Enter your password: ";
	std::cin >> password;


	hashed_password = sha256(password); //hash password

	//ineffective logging method, to be changed using database
	std::vector<User*> users = UserList::vector_of_users();
	bool found = false;
	for (auto x : users) {
		if (x->get_username() == username && x->get_password() == hashed_password) {
			found = true;
			logged_in = 1;
			ptr_to_usr = x;
			return ptr_to_usr; //return pointer to user object if login was successful 
			break;
		}
	}
	if (!found){
		std::cout << "Wrong username or password" << std::endl;
		logged_in = 0;
		return ptr_to_usr; //return NULL pointer
	}
}
		