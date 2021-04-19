#include <iostream>
#include "Calculator.h"



Calculator::Calculator() { //Calculator class constructor
	double x, y, result;
	char op;

	std::cout << "The calculator is now in basic mode!" << std::endl;
	std::cout << "Possible operators are: +, -, *, /" << std::endl;


	std::cin >> x >> op >> y;

	result = Calculator::Calculate(x, op, y);

	std::cout << "Your result is: " << result;

};

double Calculator::Calculate(double a, char op, double b) //Definition of Calculate function of calculator class
{
		switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0) {
				std::cout << "Can't divide by zero!" << std::endl;
				break;
			}
			else {
				return a / b;
			}
	}
		return 0;
}


Calculator_more::Calculator_more() { //Constructor of Calculator_more class
	std::cout << "The calculator is in advanced mode. Here are your options: abs, pow, sqrt, cbrt, fmod" << std::endl;
	std::string fun;
	double result, arg, arg2;
	std::cin >> fun;

	if (fun == "abs") {
		std::cout << "abs - returns an absolute value of your argumet" << std::endl << "Input your argument: ";
		std::cin >> arg;		
		result = Calculator_more::abs(arg);
		std::cout << "Your result: " << result;
	}
	else if (fun == "pow") {
		std::cout << "pow - returns power of x to y" << std::endl << "Input your arguments (x, then y): ";
		std::cin >> arg >> arg2;
		result = Calculator_more::pow(arg, arg2);
		std::cout << "Your result: " << result;
	}
	else if (fun == "cbrt") {
		std::cout << "cbrt - returns cubic root of an argument" << std::endl << "Input your argument: ";
		std::cin >> arg;
		result = Calculator_more::cbrt(arg);
		std::cout << "Your result: " << result;
	}

	else if (fun == "fmod") {
		std::cout << "fmod - returns ramainder of x/y" << std::endl << "Input your arguments (x then y): ";
		std::cin >> arg, arg2;
		result = Calculator_more::pow(arg, arg2);
		std::cout << "Your result: " << result;
	}

	else if (fun == "sqrt") {
		std::cout << "sqrt - returns square root of an argumet" << std::endl << "Input your argument: ";
		std::cin >> arg;
		result = Calculator_more::sqrt(arg);
		std::cout << "Your result: " << result;
	}

	else {
		std::cout << "You must input a correct function name!";
	}


};


//Definitions of some cmath library functions
double Calculator_more::abs(double a) {
	return std::abs(a);
}

double Calculator_more::pow(double a, double b) {
	return std::pow(a, b);
}

double Calculator_more::cbrt(double a) {
	return std::cbrt(a);
}

double Calculator_more::fmod(double a, double b) {
	return std::fmod(a, b);
}

double Calculator_more::sqrt(double a) {
	return std::sqrt(a);
}

int main()
{
	std::cout << "Welcome to yet another C++ calculator. This one is unique, though, as it is mine." << std::endl;
	std::cout << "To use the calculator in basic mode, type B (basic). To use it in a bit more advanced version, type S" << std::endl;

	char mode;

	std::cin >> mode;
	while (toupper(mode) != 'B' && toupper(mode) != 'S') { //goes until user inputs correct input
			std::cout << "You must input a correct letter!" << std::endl;
			std::cin >> mode;
	}

	if (toupper(mode) == 'B') {
		Calculator bas;
	}

	else if (toupper(mode) == 'S') {
		Calculator_more adv;
	}

	return 0;
};