#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;


class User {
public:
	const string& get_username() const;
	const string& get_password() const;
	void change_password();
	User(const string& username, const string& password);
	void add_entry();
	void show_entries();
	bool delete_user();
	
private:
	string username_;
	string password_hash_;
};
