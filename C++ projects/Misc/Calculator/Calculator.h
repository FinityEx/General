#pragma once

#include <cmath>

class Calculator { //Declaration of Calculator class
public:
	Calculator(); //Constructor
	double Calculate(double a, char op, double b);
};

class Calculator_more { //Declaration of Calculator_more class
public:
	Calculator_more(); //Constructor
	double abs(double a);
	double pow(double a, double b);
	double sqrt(double a);
	double cbrt(double a);
	double fmod(double a, double b);
};