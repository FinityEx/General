/*Program takes an input, then prints it out in reverse order */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string reverse(const string& s) {
	string rString{};

	//add characters one by one to a separate string
	for (int i = s.size() - 1; i >= 0; i--) { 
		rString += s[i];
	}
	return rString;
}


int main() {
	string userInput{};
	cout << "Input string to be reserved: ";
	std::getline(cin, userInput);

	cout << "Your string in reverse is: " << reverse(userInput);

	return 0;
}