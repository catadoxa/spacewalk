/*********************************************************************
 ** Program Filename: airlock1.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Derived from space, contains boolean and doors that must be reset to 
 ** true by Player actions for game to progress.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef AIRLOCK1_HPP
#define AIRLOCK1_HPP

#include "space.hpp"

class Airlock1 : public Space {

	private:
		
		bool doors;
		bool button;
		
	public:
		
		Airlock1();
		~Airlock1();
		void special();
		
		void set_doors(bool doors) { this->doors = doors; }
		bool get_doors() { return doors; }
		
		void set_button(bool button) { this->button = button; }
		bool get_button() { return button; }
		
};

#endif