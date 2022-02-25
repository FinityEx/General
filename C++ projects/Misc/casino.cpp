//Casino game - program takes name of the player, starting balance, and uses pseudorandom numbers generator for gambling. 

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

string playerName;
double balance;
double bet;
int guess;
int roll;
char yesNo = 'y';
int play();
int again();


int main() {

	cout << "Hello, player, what's your name?: "; cin >> playerName;
	cout << "What's the starting balance for tonight?: $"; cin >> balance;

	while (yesNo == 'y' && balance != 0) {
		play();

		if (guess == roll) {
			balance += bet * 10;
			cout << "You are in luck!\nYou won " << bet * 10 << endl;
			cout << "You current balance is : $" << balance << endl;
			cout << "Do you want to play again? (y/n): "; cin >> yesNo;
		}
		else {
			balance -= bet;
			cout << "No luck this time, you lost $" << bet << " and your current balance is $" << balance << endl;
			if (balance == 0) {
				cout << "You're broke! Thanks for playing " << endl;
				return 0;
			}
			else cout << "Do you want to play again? (y/n): "; cin >> yesNo;
		}
	}

	cout << "Thanks for playing! Your final balance is: $" << balance << endl;
	return 0;
}



int play() {
	system("CLS"); //while aware use of system function is discouraged, figured its usage cant be too harmful in program like this one

	cout << "               =====CASINO RULES!=====              \n"
		"    1. Choose a number between 1 and 10\n"
		"    2. If you're in luck, you will win 10 times the amount you bet.\n"
		"    3. Guess wrong, you will lose the amount you bet" << endl << endl;
	while (1) {
		cout << "Your current balance is:  $" << balance << endl;
		cout << "Hey " << playerName << ", place your bet: "; cin >> bet;
		if (bet > balance) cout << "Bet can't be bigger than your balance!" << endl;
		else break;
	}
	cout << "Guess the number 1 to 10: "; cin >> guess;

	srand(time(NULL)); //seed initilized
	roll = rand() % 10 + 1; //number generated

	return roll;
}


int again() {
	cout << "Do you want to play again? (y/n): "; cin >> yesNo;
	while (1) {
		if (yesNo == 'y') {
			play();
			break;
		}
		else if (yesNo == 'n') {
			cout << "Thanks for playing! Your final balance is: $" << balance << endl;
			return 1;
		}
		else cout << "Wrong answer!" << endl;
	}
}