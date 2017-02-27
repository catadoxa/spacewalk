/*********************************************************************
 ** Program Filename: pal.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Pal is a computer mainframe that a Player can talk to.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef PAL_HPP
#define PAL_HPP

#include <vector>
#include <string>

class Pal {

	private:
	
		std::vector<std::string> questions;
		std::vector<std::string> responses;
		std::vector<std::string> crazy_responses;
		
		//bools depending on what has happened?;
		bool button;
		bool doors;
	
	public:
		
		Pal();
		
		std::vector<int> update_switches();
		
		void talk();
		
		void talk_responses(int n);
		
		void set_doors(bool doors) { this->doors = doors; }
		bool get_doors() { return doors; }
		
		void set_button(bool button) { this->button = button; }
		bool get_button() { return button; }

};

#endif