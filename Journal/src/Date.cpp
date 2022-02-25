//function returns current date in specific string format

#include "Date.h"
#include <iostream>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;





std::string date() {

	time_t now = time(0);
	tm* ltm = localtime(&now);

	std::string today = wdays[ltm->tm_wday];
	std::string t_month = months[ltm->tm_mon];
	std::string sufix;

	switch (ltm->tm_mday % 10) {
	case 1:
		sufix = "st";
		break;
	case 2:
		sufix = "nd";
		break;
	case 3:
		sufix = "rd";
		break;
	default:
		sufix = "th";
		break;
	}
	std::string date = today + ", " + t_month + " " + std::to_string(ltm->tm_mday) + sufix + ", " + std::to_string(1900 + ltm->tm_year);
	
	return date;
}