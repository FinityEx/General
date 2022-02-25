/*Program transforms words according to Pig Latin game rules. For more information refer to: https://en.wikipedia.org/wiki/Pig_Latin
* 
* TO DO:
* -Input guard
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//transforms a string into lowercase. Passed string object remains untouched for possible future operations
string toLower(const string& s) {
	string str = s;
	std::for_each(str.begin(), str.end(), [](char& c) { c = ::tolower(c); });
	return str;
}

//checks if given char is a vowel. Considers 'Y' to be a vowel.
bool isVowel(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y') return true;
	else return false;
}


//transforms the word according to the game's rules
string piggyIt(const string& s) {
	string word = s;
	string wordPiggied{};

	if (isVowel(word[0])) {
		wordPiggied += word + "yay";
	}
	else {
		for (int i = 0; i < word.size(); i++) {
			if (isVowel(word[i])) {
				wordPiggied += word.substr(i, word.size() - 1) + word.substr(0, i) + "ay";
				break;
			}
		}
	}
	return wordPiggied;
}


int main() {
	while (true) {
		string userInput{}; 

		//for user's input in lowers case
		string userInputLow{}; 

		cout << "Input a word to be piggied up, or \"1\" to exit: ";
		cin >> userInput;

		if (userInput == "1") {
			cout << "Bye!";
			return 0;
		}
		else {
			userInputLow = toLower(userInput);
			cout << "Your word as Pig Latin is: " << piggyIt(userInputLow) << endl;
		}
	}

}




