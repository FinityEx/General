#include "Door.h"
#include "Functions.h"

using std::vector;

//constructor
Door::Door(bool status) : prize_(status), chosen_(false), discarded_(false) {}

//create vector of pointers to Door. A random door will contain the prize.
void Door::populate_vector() {
	unsigned int number = random_number();
	for (unsigned int i = 0; i < 3; i++) {
		if (i == number) {
			Door::Doors.push_back(new Door(true));
		}
		else {
			Door::Doors.push_back(new Door(false));
		}
	}
}


bool Door::has_prize() {
	return prize_;
}

//choose a door, per game rules
void Door::choose() {
	unsigned int doors_number = random_number();
	Doors[doors_number]->chosen_ = true;
}


bool Door::is_chosen() {
	return chosen_;
}

bool Door::is_discarded() {
	return discarded_;
}

//discards [opens] a door that has no prize and has not been chosen, per game rules
void Door::discard() {
	for (int i = 0; i < 3; i++) {
		if (!Doors[i]->is_chosen() && !Doors[i]->has_prize()) {
			Doors[i]->discarded_ = true;
			break;
		}
	}
}

//switch choice of doors, per game rules
void Door::switch_doors() {
	for (auto x : Doors) {
		if (x->discarded_) continue;
		else if (x->chosen_) x->chosen_ = false;
		else if (!x->chosen_) x->chosen_ = true;
	}
}

//return result of the game and delete pointers from vector
int Door::result() {
	for (auto x : Doors) {
		if (x->chosen_) {
			if (x->has_prize()) {
				delete_pointers();
				return 1;
			}
			else {
				delete_pointers();
				return 0;
			}
		}
	}
}


void Door::delete_pointers() {
	for (auto p : Doors) {
		delete p;
	}
	Doors.clear();
}
