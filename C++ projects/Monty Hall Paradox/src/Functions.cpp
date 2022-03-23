#include "Functions.h"
#include "Door.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

//returns random number between 0 and 2
unsigned int random_number() {
	boost::random::random_device dev;
	boost::random::mt19937 rng(dev);
	boost::random::uniform_int_distribution<> three(0, 2);

	unsigned int x = three(rng);

	return x;
}

//runs the simulation
unsigned int simulate(bool switched) {
	Door::populate_vector();
	Door::choose();
	Door::discard();
	if (switched) Door::switch_doors();
	return Door::result();
}

//controls user input
int run(unsigned int no) {
	size_t count_switched = 0;
	size_t count_not_switched = 0;
	char choice;

	for (int y = 0; y < no; y++) {
		count_not_switched += simulate(false);
		count_switched += simulate(true);
	}

	std::cout << "Simulation has been run " << no << " times for both cases. Results:\n" <<
		"Times won if NOT switched: " << count_not_switched << ". On avarage, chance to win when not switching was " <<
		count_not_switched * 100 / no << "%\n" <<
		"Times won if switched: " << count_switched << ". On avarage, chance to win when switching was " <<
		count_switched * 100 / no << "%" << std::endl;

	std::cout << "Repeat simulation? [Y/N]: ";
	std::cin >> choice;
	if (std::tolower(choice) == 'y') return 1;
	else return 0;

}

