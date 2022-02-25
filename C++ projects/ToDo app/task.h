#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Task {
private:
	string desc{}; //task description
public:
	Task(string d);
	string getDesc();
};


