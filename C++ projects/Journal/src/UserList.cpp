#include "User.h"
#include "UserList.h"
#include <vector>


//is this vector still needed?
//it is, but shouldn't be. To be updated
vector<User*> UserList::users;

User*  UserList::AddUser(const string& username, const string& password) {
	User* p = new User(username, password);
	users.push_back(p);
	return p;
}

std::vector<User*> UserList::vector_of_users(){
	return users;
}

UserList::~UserList() {
	for (auto user : users) {
		delete user;
	}
}