/*********************************************************************
 ** Program Filename: player.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Player can move through Spaces and pick up Objects. Interacts through 
 ** menues.
 ** Input:
 ** Output:
**********************************************************************/

#include <iostream>

#include "menu.hpp"

#include "player.hpp"

/*********************************************************************
 ** Function: Player::Player(std::string name, Space *location)
 ** Description: Constructor initializes name and starting Space
 ** Parameters: std::string name, Space *location
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Player::Player(std::string name, Space *location) {
	
	this->name = name;
	move(location);
	
	
}

/*********************************************************************
 ** Function: void Player::move(Space *move_to)
 ** Description: Changes the space the Player is interacting with.
 ** Parameters: Space *move_to
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::move(Space *move_to) {

	location = move_to;

}

/*********************************************************************
 ** Function: void Player::add_object(Object *obj)
 ** Description: pushes an object into the player inventory
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::add_object(Object *obj) {

	obj->set_index(inventory.size());
	inventory.push_back(obj);
	obj->set_in_inv(true);
	
}

/*********************************************************************
 ** Function: void Player::view_inventory()
 ** Description: Creates a vector of menu options for the names of objects in the 
 ** player inventory, and then outputs them with menu(). Allows player to examine
 ** a single object more closely.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::view_inventory() {
	
	std::string message = "\nInventory. Enter item number to examine more closely.";
	
	/*create item menu*/
	std::vector<std::string> items;
	for(unsigned i = 0; i < inventory.size(); i++)
		items.push_back(inventory[i]->get_name());
	
	items.push_back("Return to previous menu.");
	
	/*call menu()*/
	int opt = menu(items, message);
	
	if(opt < (int) inventory.size())
		examine_object(inventory[opt]);
	
}

/*********************************************************************
 ** Function: void Player::examine_object(Object *obj)
 ** Description: allows the player to view an object more closely, and gives some options.
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::examine_object(Object *obj) {
	
	/*call object menu to show what can be done with object*/
	std::string opt = obj->actions();

	/*calls the appropriate action chosen*/
	if(opt == "get")
		pick_up_object(obj);
	else if(opt == "drop")
		drop_object(obj);
	else if(opt == "use")
		obj->use();

}

/*********************************************************************
 ** Function: void Player::drop_object(Object *obj)
 ** Description: Removes object from player inventory, and adds it to the location.
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::drop_object(Object *obj) {

	inventory.erase(inventory.begin() + obj->get_index());
	
	/*change indexes of other objects in inventory, ie move them down one index*/
	for(unsigned i = obj->get_index(); i < inventory.size(); i++)
		inventory[i]->set_index(inventory[i]->get_index() - 1);
	
	location->add_object(obj);
	
	std::cout << "\nYou drop the " << obj->get_name() << "." << std::endl;
		
}

/*********************************************************************
 ** Function: void Player::pick_up_object(Object *obj)
 ** Description: removes object from location, adds it to inventory. Has a max capacity.
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::pick_up_object(Object *obj) {

	unsigned max_inv = 4;
	
	if(inventory.size() < max_inv) {
		
		location->remove_object(obj);
		this->add_object(obj);
	
		std::cout << "\nYou pick up the " << obj->get_name() << "." << std::endl;
		
	} else
		std::cout << "\nYou can only carry so much! You'll have to drop something."
			<< std::endl;
	
}

/*********************************************************************
 ** Function: std::vector<int> Player::update_switches()
 ** Description: This acts as a key for the menu options, ensuring only appropriate
 ** options are output.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::vector<int> Player::update_switches() {

	int size = options.size();
	std::vector<int> switches(size, -1);

	int count = 1;
	
	/*go north*/
	if(location->get_north() != NULL) {
		switches[0] = count;
		count++;
	}
	
	/*go south*/
	if(location->get_south() != NULL) {
		switches[1] = count;
		count++;
	}
	
	/*go east*/
	if(location->get_east() != NULL) {
		switches[2] = count;
		count++;
	}
	
	/*go west*/
	if(location->get_west() != NULL) {
		switches[3] = count;
		count++;
	}

	/*examine objects*/
	if(!location->get_objects().empty()) {
		switches[4] = count;
		count++;
	}
	
	/*special option*/
	switches[5] = count;
	count++;
	
	/*examine inventory*/
	switches[6] = count;
	count++;

	/*examine area*/
	switches[7] = count;
	count++;
	
	/*help*/
	switches[8] = count;

	return switches;

}

/*********************************************************************
 ** Function: bool Player::space_options()
 ** Description: creates a menu of options, updates switches, and calls menu() on options
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
bool Player::space_options() {

	std::string temp;
	options.clear();
	
	temp = "Exit this area and go to the ";
	if(location->get_north() != NULL)
		temp += location->get_north()->get_name() + ".";
	options.push_back(temp);
	
	temp = "Exit this area and go to the ";
	if(location->get_south() != NULL)
		temp += location->get_south()->get_name() + ".";
	options.push_back(temp);
	
	temp = "Exit this area and go to the ";
	if(location->get_east() != NULL)
		temp += location->get_east()->get_name() + ".";
	options.push_back(temp);
	
	temp = "Exit this area and go to the ";
	if(location->get_west() != NULL)
		temp += location->get_west()->get_name() + ".";
	options.push_back(temp);
	
	temp = "Examine the objects.";
	options.push_back(temp);
	
	temp = location->get_special_option();
	options.push_back(temp);
	
	temp = "Examine your inventory.";
	options.push_back(temp);
	
	temp = "Look around the area.";
	options.push_back(temp);
	
	temp = "Help.";
	options.push_back(temp);
	
	/*get user input*/
	int choice = menu(options, update_switches());
	
	/*call to get the appropriate action*/
	bool moved = space_actions(choice);
	
	return moved;
	
}

/*********************************************************************
 ** Function: bool Player::space_actions(int n)
 ** Description: performs the appropriate action indicated by paramater. If location is
 ** changed, then returns moved = true.
 ** Parameters: int n
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
bool Player::space_actions(int n) {
	
	/*return true if player changes location*/
	bool moved = false;
	
	/*go north*/
	if(n == 0) {
	
		move(location->get_north());
		moved = true;	
		
	/*go south*/
	} else if(n == 1) {
	
		move(location->get_south());
		moved = true;	
		
	/*go east*/
	} else if(n == 2) {
	
		move(location->get_east());
		moved = true;	
	
	/*go west*/
	} else if(n == 3) {
	
		move(location->get_west());
		moved = true;	
	
	/*examine object in area*/
	} else if(n == 4) {
		examine_all_objects();

	/*call special action*/
	} else if(n == 5) {
		location->special();
		
	/*examine object in inventory*/
	} else if(n == 6) {
		view_inventory();	
		
	/*describe the area*/
	} else if(n == 7) {
	
		location->print_space();
	
	/*help (cheat) option*/
	} else if(n == 8) {
		help();
	}
	
	return moved;

}

/*********************************************************************
 ** Function: void Player::help()
 ** Description: Outputs cheat infor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::help() {

	std::cout << "\nYou need to open the airlock doors to reach the airlock compartment"
		"\nOnce inside, you need to have read the book so you can ask the robot some "
		"\nimpossible logic puzzles. Make sure you are wearing the spacesuit before"
		"\nyou do this, though, because after three questions the robot tosses you into"
		"\nspace. Here, you need chewed gum and ducttape to fix the damage." << std::endl;

}

/*********************************************************************
 ** Function: void Player::examine_all_objects()
 ** Description: outputs object in location in a menu, allowing user to examine them more
 ** closely.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Player::examine_all_objects() {

	std::vector<std::string> obj_names;
	/*create menu of objects in location*/
	for(unsigned i = 0; i < location->get_objects().size(); i++)
		obj_names.push_back("Examine the " + location->get_objects()[i]->get_name() + ".");
	
	obj_names.push_back("Return to the previous menu.");
	
	/*get user input from menu*/
	unsigned choice = menu(obj_names);

	/*examine chosen object more closely, or do nothing if appropriate*/
	if(choice < location->get_objects().size())
		examine_object(location->get_objects()[choice]);

}