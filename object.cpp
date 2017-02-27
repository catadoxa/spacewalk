/*********************************************************************
 ** Program Filename: object.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Definition of the Object class. Objects have descriptions of various
 ** qualities, and can be used and reused depending on how they are set up.
 ** Input:
 ** Output:
**********************************************************************/

#include "object.hpp"

#include <iostream>

#include "menu.hpp"

/*********************************************************************
 ** Function: Object::Object()
 ** Description: sets default (most commonly used) values
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Object::Object() {

	in_inv = false;
	used = false;
	can_use = true;
	can_unuse = false;
}

/*********************************************************************
 ** Function: Object::~Object()
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Object::~Object() {

}

/*********************************************************************
 ** Function: std::string Object::get_name()
 ** Description: getter has different returns depending on variables
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::string Object::get_name() {

	if(!used)
		return name;
	else
		return used_name;

}

/*********************************************************************
 ** Function: std::string Object::get_description()
 ** Description: getter has different returns depending on variables
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::string Object::get_description() {

	if(!used)
		return description;
	else
		return used_description;
}

/*********************************************************************
 ** Function: std::string Object::get_use_option()
 ** Description: getter has different returns depending on variables
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::string Object::get_use_option() {

	if(!used)
		return use_option;
	else
		return used_use_option;
}

/*********************************************************************
 ** Function: std::vector<int> Object::update_switches()
 ** Description: creates a map of values for appropriate menu options
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::vector<int> Object::update_switches() {

	//set switches w/default sentinel value -1
	int size = opts.size();
	std::vector<int> switch_vals(size, -1);

	int count = 1;
	
	/*drop or pick up*/
	if(!in_inv) {
	
		switch_vals[0] = count;
		count++;
	
	} else {
		
		switch_vals[1] = count;
		count++;
	
		/*use, if possible. can only use things already picked up.*/
		if(!used && can_use) {
		
			switch_vals[2] = count;
			count++;
		
		} else if(used && can_unuse) {
			
			switch_vals[3] = count;		
			count++;
			
		}
	}
	
	/*return to previous*/
	switch_vals[4] = count;
	
	return switch_vals;


}

/*********************************************************************
 ** Function: std::string Object::actions()
 ** Description: creates a menu, and gets user input
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::string Object::actions() {
	
	/*must update opts here rather than constructor because options change*/
	opts.clear();
	opts.push_back("Pick up the " + get_name() + ".");
	opts.push_back("Drop the " + get_name() + ".");
	opts.push_back(get_use_option());
	opts.push_back(get_use_option());
	opts.push_back("Return to previous menu.");
	
	int choice = menu(opts, update_switches());
	std::string action;
	
	if(choice == 0)
		action = "get";
	else if(choice == 1)
		action = "drop";
	else if(choice == 2 || choice == 3)
		action = "use";
	else
		action = "nothing";
	
	
	return action;
}

/*********************************************************************
 ** Function: void Object::use() 
 ** Description: performs appropriate action depending on member variable bools
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Object::use() {
	
	/*first use it if it is unused*/
	if(!used && can_use) {
	
		std::cout << describe_use << std::endl;
	
		set_used(true);
	
	/*if unuse if possible*/
	} else if(used && can_unuse) {
	
		std::cout << describe_unuse << std::endl;
	
		set_used(false);
	}
	
}