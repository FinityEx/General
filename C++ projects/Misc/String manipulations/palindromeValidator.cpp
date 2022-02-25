/*Program checks wether or not an input is a palindrome */

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


bool isPalindrome(string s) {
	string newString {};
	s.erase(std::remove_if(s.begin(), s.end(), std::isspace), s.end()); //erase space characters from original string
	for (int i = s.size() - 1 ; i >= 0; i--) { //add characters one by one in reverse order
		newString += s[i];
	}
	if (s == newString) return true;
	else return false;
}
	


int main() {
	string userInput;

	cout << "Enter input to be checked: ";
	std::getline(cin, userInput);

	if (isPalindrome(userInput)) cout << "Your input is a palindrome.";
	else cout << "Your input is NOT a palindrome.";
	return 0;
}