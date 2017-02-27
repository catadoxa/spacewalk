/*********************************************************************
 ** Program Filename: player.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Player can move through Spaces and pick up Objects. Interacts through 
 ** menues.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

#include "space.hpp"
#include "object.hpp"

class Player {
	
	private:
	
		std::string name;
		std::vector<Object *> inventory;
		Space *location;
		
		std::vector<std::string> options;
		
	public:
		
		Player(std::string name, Space *location);
		
		std::string get_name() { return name; }
		
		Space * get_location() { return location; }
		
		std::vector<Object *> get_inventory() { return inventory; }

		
		void move(Space *move_to);
		
		void view_inventory();
		
		void add_object(Object *obj);
		
		void examine_object(Object *obj);
		
		void drop_object(Object *obj);
		
		void pick_up_object(Object *obj);
		
		std::vector<int> update_switches();
		
		bool space_options();
		
		bool space_actions(int n);
		
		void help();
		
		void examine_all_objects();
};

#endif
