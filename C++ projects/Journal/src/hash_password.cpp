//return password hashed with external SHA256 function

#include "hash_password.h"
#include <string>


std::string hash_password(const std::string& pass) {
	std::string hashed_password{};

	hashed_password = sha256(pass);

	return hashed_password;
}