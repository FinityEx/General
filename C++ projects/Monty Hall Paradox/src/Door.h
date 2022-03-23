#pragma once
#include <vector>

class Door {

private:
	const bool prize_;
	bool chosen_;
	bool discarded_;
	inline static std::vector<Door*> Doors;

public:
	Door(bool);
	bool has_prize();
	static void choose();
	bool is_chosen();
	bool is_discarded();
	static void populate_vector();
	static void discard();
	static void switch_doors();
	static int result();
	static void delete_pointers();
};