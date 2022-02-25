#pragma once
#include "User.h"
#include <vector>

class UserList {
public:
	static User* AddUser(const string& username, const string& password);
	static std::vector<User*> vector_of_users();
	~UserList();
private:
	static std::vector<User*> users;
};

