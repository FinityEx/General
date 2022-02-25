#include "task.h"

Task::Task(string description) : desc{ description } {} //class constructor

string Task::getDesc(){ 
	return desc;
}
