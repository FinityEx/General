#include "functions.h"
#include "task.h"
#include <vector>
#include <fstream>
#include <string>


using std::vector;


int choice;
vector<Task> undoneTasks{};

void start() {
	cout << "Welcome to your ToDo list.\n\n";
	string line;
	std::ifstream file("tasks.txt");

	//read tasks from file
	if (file.is_open()) { 
		while (std::getline(file, line)) {
			Task obj(line);
			undoneTasks.push_back(obj);
		}
	}

	file.close();
	std::remove("tasks.txt"); //delete the temporary file to avoid duplicates
	showTask();
}

int choose() {
	bool fail;
	cout << "\nWhat do you want to do?";
	cout << "\n1. Create new task\n2. Show tasks\n3. Mark as done\n4. Exit\n\n";
	do{
		cout << "Your choice: ";
		cin >> choice;
		
		fail = cin.fail();
		cin.clear(); //clear bad input flag
		cin.ignore(INT_MAX, '\n');
	} while (fail);
	cout << "\n=================" << endl;
	switch (choice) {
	case 1:
		createTask();
		break;
	case 2:
		showTask();
		break;
	case 3:
		markDone();
		break;
	case 4:
		exit();
		return 0;
		break;
	}
}


void exit() {
	cout << "Bye!";
	std::ofstream file;
	file.open("tasks.txt", std::ios::app);
	for (auto x : undoneTasks) { //save tasks into .txt file
		file << x.getDesc() << endl;
	}
}



void createTask() {
	string d;
	cout << "Input description for your task: " << endl;
	std::getline(cin, d);
	Task obj(d);
	undoneTasks.push_back(obj);
	cout << "\n=================" << endl;
}

void markDone() {
	if (!undoneTasks.size()) cout << "No tasks yet!" << "\n=================" << endl;
	else {
		vector<Task>::iterator it;
		int task;
		showTask();
		cout << "Input done task's number (input \"0\" to mark all tasks as done): ";
		cin >> task;
		if (!task) undoneTasks.clear();
		else {
			it = undoneTasks.begin() + (task - 1);
			undoneTasks.erase(it);
			cout << "\n=================" << endl;
			showTask();
		}
	}
}



void showTask() {
	int i = 1;
	cout << "Tasks to be done: " << endl;
	cout << "=================" << endl;
	if (!undoneTasks.size()) cout << "No tasks yet!";
	else {
		for (auto x : undoneTasks) {
			cout << i++ << ". " << x.getDesc() << endl;
		}
	}
	cout << "\n=================" << endl;
}