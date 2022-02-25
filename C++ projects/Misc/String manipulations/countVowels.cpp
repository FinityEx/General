/*Counts vowels in given string
* 
* TO DO:
* -Fail guard against wrong type of input
* 
*/


#include<iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;


//checks if passed char is a vowel
bool isVowel(char x) { 
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ) return true;
	else return false;
}

//transforms a string into lowercase. Passed string object remains untouched for possible future operations
string toLower(const string& s) {
	string str = s;
	std::for_each(str.begin(), str.end(), [](char& c) { c = ::tolower(c); });
	return str;
}


int main() {
	while (true) {
		string userInput{};
		cout << "Input string to be examined or \"0\" to exit: ";
		std::getline(cin, userInput);

		if (userInput == "0") {
			cout << "Bye!";
			break;
			return 0;
		}
		else {
			size_t total{};
			string userInputLow{};
			size_t yOccurrence{};

			userInputLow = toLower(userInput);

			//count vowels
			for (auto x : userInputLow) {
				if (isVowel(x)) {
					total++;
				}
			}

			//count instances of 'Y' in string
			size_t pos{ userInputLow.find("y") };
			while (pos != string::npos) {
				yOccurrence++;
				pos = userInputLow.find("y", pos + 1);
			}

			if(yOccurrence > 0) cout << "Total amount of vowels in your string is " << total 
				<< " without 'Y' included, or " << total + yOccurrence << " with 'Y' included." << endl;

			else cout << "Total amount of vowels in your string is: " << total << endl;
		}
	}

	return 0;
}

