/*Counts words in a string and that's it */

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

size_t wordsCount(const string& s) {
	string str = s;
	string word{};
	std::stringstream sm(str); 
	size_t count{};

	//takes words from stringstream object into string one by one
	while (sm >> word) count++; 

	return count;
}

int main() {
	string usrInput{};

	while (true) {
		cout << "Input string to be examined or \"0\" to exit: ";
		std::getline(cin, usrInput);

		if (usrInput == "0") {
			cout << "Bye!";
			break;
		}
		else cout << "The number of words in your string is: " << wordsCount(usrInput) << endl;
	}

	return 0;
}


