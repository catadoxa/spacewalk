/*********************************************************************
 ** Program Filename: outside.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Outside objects are derived from the abstract base Space. Aside from 
 ** descriptive strings, Outside has booleans for an antenna and a puncture that can be
 ** "fixed" by a Player.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

#include "space.hpp"
#include <string>

class Outside : public Space {

	private:
		
		bool fixed_antenna;
		bool fixed_puncture;
		
		std::string antenna;
		std::string puncture;

	public:
	
		Outside();
		
		~Outside();
		
		bool get_fixed_antenna() { return fixed_antenna; }
		bool get_fixed_puncture() { return fixed_puncture; }
		
		void set_fixed_antenna(bool fixed_antenna) { this->fixed_antenna = fixed_antenna; }
		void set_fixed_puncture(bool fixed_puncture) { this->fixed_puncture = fixed_puncture; }
		
		void special();

		
};

#endif