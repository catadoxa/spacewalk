/*********************************************************************
 ** Program Filename: deck.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: A simple space with various descriptions.
 ** Input:
 ** Output:
**********************************************************************/

#include "deck.hpp"

#include <iostream>

/*********************************************************************
 ** Function: Deck::Deck()
 ** Description: initializes default descriptions. The should be overridden.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Deck::Deck() {
	
	/*name and description will be reset for specific deck areas*/
	set_name("Deck");
	set_description("A section of deck.");
	
	set_special_name("porthole with a view");
	set_special_option("Look through the porthole.");

}

/*********************************************************************
 ** Function: Deck::~Deck()
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Deck::~Deck() {



}

/*********************************************************************
 ** Function: void Deck::special()
 ** Description: Outputs a description.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Deck::special() {

	std::cout << special_string << std::endl;

}