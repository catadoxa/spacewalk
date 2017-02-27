/*********************************************************************
 ** Program Filename: object.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Declaration of the Object class. Objects have descriptions of various
 ** qualities, and can be used and reused depending on how they are set up.
 ** Most functions are getter and setters. Other functions are explained in the 
 ** definition file object.cpp
 ** Input:
 ** Output:
**********************************************************************/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <vector>

class Object {

	private:
	
		unsigned index;
		bool in_inv;
		bool used;
		bool can_use;
		bool can_unuse;
	
		std::string name;		
		std::string description;
		std::string use_option;
	
		std::string describe_use;
		std::string describe_unuse;
		
		std::string used_name;
		std::string used_description;
		std::string used_use_option;
		
		std::vector<std::string> opts;
	
	public:
		
		Object();
		~Object();
		
		void set_index(unsigned n) {this->index = n; }
		
		int get_index() { return index; }
		
		void set_name(std::string name) { this->name = name; }
		void set_description(std::string description) { this->description = description; }
		void set_use_option(std::string option) { this->use_option = option; }
		
		void set_in_inv(bool inv) { this->in_inv = inv; }
		void set_can_use(bool can_use) { this->can_use = can_use; }
		void set_can_unuse(bool can_unuse) { this->can_unuse = can_unuse; }
		void set_used(bool used) { this->used = used; }
		
		void set_used_name(std::string name) { this->used_name = name; }
		void set_used_description(std::string description) 
			{ this->used_description = description; }
		void set_used_use_option(std::string option)
			{ this->used_use_option = option; }
		void set_describe_use(std::string use) {this->describe_use = use; }
		void set_describe_unuse(std::string unuse) {this->describe_unuse = unuse; }
		
		std::string get_name();
		std::string get_description();
		std::string get_use_option();
		
		bool get_in_inv() { return in_inv; }
		bool get_can_use() { return can_use; }
		bool get_can_unuse() { return can_unuse; }
		bool get_used() { return used; }
		
		void use();

		std::vector<int> update_switches();
		
		std::string actions();
		
};


#endif