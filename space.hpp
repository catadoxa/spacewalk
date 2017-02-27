/*********************************************************************
 ** Program Filename: space.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space has some descriptive elements and pointers allowing it to be 
 ** linked to other Spaces in four different directions. Also contains a pure abstract
 ** special function, and can contain Object objects.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <vector>


#include "object.hpp"

/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/

class Space {
	
	protected:
		
		Space *north, *south, *east, *west;
		std::string name, description, special_name, special_option;
		std::vector<Object *> objects;
		
	public:
		Space();
		virtual ~Space();
		
		Space * get_north() { return north; }
		Space * get_south() { return south; }
		Space * get_east() { return east; }
		Space * get_west() { return west; }		
			
		std::string get_name() { return name; }
		std::string get_description() { return description; }
		std::string get_special_name() { return special_name; }
		std::string get_special_option() { return special_option; }
		std::vector<Object *> get_objects() { return objects; }
		
		void set_directions(Space *north, Space *south, Space *east, Space *west);
		
		void set_north(Space *north) { this->north = north; }
		void set_south(Space *south) { this->south = south; }
		void set_east(Space *east) { this->east = east; }
		void set_west(Space *west) { this->west = west; }
		
		void set_name(std::string name) { this->name = name; }
		void set_description(std::string description) { this->description = description; }
		void set_special_name(std::string special_name) { this->special_name = special_name; }
		void set_special_option(std::string special_option) { this->special_option = special_option; }
		
		void add_object(Object *obj);
		
		void remove_object(Object *obj);
		
		virtual void special() = 0;
		
		void print_space();
		
};

#endif