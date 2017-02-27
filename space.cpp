/*********************************************************************
 ** Program Filename: space.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space has some descriptive elements and pointers allowing it to be 
 ** linked to other Spaces in four different directions. Also contains a pure abstract
 ** special function, and can contain Object objects.
 ** Input:
 ** Output:
**********************************************************************/

#include <iostream>
#include <sstream>

#include "space.hpp"

/*********************************************************************
 ** Function: Space::Space()
 ** Description: sets some default values.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Space::Space() {

	north = south = east = west = NULL;
	
	name = description = special_name = special_option = "";
	
	
}

/*********************************************************************
 ** Function: Space::~Space()
 ** Description: sets pointers to NULL
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Space::~Space() {

	north = south = east = west = NULL;
	
	for(unsigned i = 0; i < objects.size(); i++)
		objects[i] = NULL;

}

/*********************************************************************
 ** Function: void Space::set_directions(Space *north, Space *south, Space *east, Space *west)
 ** Description: sets all pointers
 ** Parameters: Space *north, Space *south, Space *east, Space *west
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Space::set_directions(Space *north, Space *south, Space *east, Space *west) {

	this->north = north;
	this->south = south;
	this->east = east;
	this->west = west;

}

/*********************************************************************
 ** Function: void Space::add_object(Object *obj)
 ** Description: adds object to objects vector
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Space::add_object(Object *obj) {

	obj->set_index(objects.size());
	this->objects.push_back(obj);
	obj->set_in_inv(false);

}

/*********************************************************************
 ** Function: void Space::remove_object(Object *obj)
 ** Description: removes objects
 ** Parameters: Object *obj
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Space::remove_object(Object *obj) {
	
	objects.erase(objects.begin() + obj->get_index());
	/*change indexes of other objects in location, ie move them down one index*/
	for(unsigned i = obj->get_index(); i < objects.size(); i++)
		objects[i]->set_index(objects[i]->get_index() - 1);

}

/*********************************************************************
 ** Function: void Space::print_space()
 ** Description: prints out description, special description, and object names.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Space::print_space() {

	std::cout << get_description() << std::endl;
	
	std::cout << "There is a " << get_special_name() << " here." << std::endl;
	
	if(!get_objects().empty()) {
		for(unsigned i = 0; i < get_objects().size(); i++)
			std::cout << "There is a " << get_objects()[i]->get_name() << " here." << std::endl;
	}
}