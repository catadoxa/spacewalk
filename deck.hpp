/*********************************************************************
 ** Program Filename: deck.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: A simple space with various descriptions.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef DECK_HPP
#define DECK_HPP

#include "space.hpp"

#include <string>

class Deck : public Space {

	private:

		std::string special_string;

	public:
	
		Deck();
		
		~Deck();
		
		void special();
		
		void set_special_string(std::string special_string)
			{ this->special_string = special_string; }
		
};

#endif