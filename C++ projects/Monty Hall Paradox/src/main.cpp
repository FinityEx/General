#include <iostream>
#include <vector>
#include <stdexcept>
#include "Functions.h"
#include "Door.h"


using std::cout;
using std::cin;
using std::endl;


int main() {
	size_t number;

	try {
		do {
			cout << "How many times shall the simulation be repeated?: ";
			cin >> number;
		} while (run(number));
	}

	catch (std::exception& e) {
		cout << "An exception has occured: " << e.what();
		return 1;
	}
	return 0;
}