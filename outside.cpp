/*********************************************************************
 ** Program Filename: outside.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Outside objects are derived from the abstract base Space. Aside from 
 ** descriptive strings, Outside has booleans for an antenna and a puncture that can be
 ** "fixed" by a Player.
 ** Input:
 ** Output:
**********************************************************************/

#include "outside.hpp"

#include <iostream>

/*********************************************************************
 ** Function: Outside::Outside()
 ** Description: Default constructor initializes member variables. Mostly descriptions.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Outside::Outside() {
	
	/*name and description will be reset for specific deck areas*/
	set_name("Outer space");
	set_description("Open space outside the space station.");
	
	set_special_name("broken antenna, and puncture in the hull");
	set_special_option("Examine the damage.");

	antenna = "It appears that an important wire melted down. Perhaps you could stick the"
		" ends \nof the wire back together with something?";
	
	puncture = "\nThe melting antenna wire appears to have created a puncture in the hull "
		"of the \nspace station. Maybe you could cover it with something?";		
	
	fixed_antenna = false;
	fixed_puncture = false;
}

/*********************************************************************
 ** Function: Outside::~Outside()
 ** Description: Destructor has nothing to destroy.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Outside::~Outside() {

}

/*********************************************************************
 ** Function: void Outside::special()
 ** Description: Describes the damage, depending on the state of the "damaged" bools.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Outside::special() {

	if(fixed_antenna)
		antenna = "The sticky chewed gum is holding the wires together.";
		
	if(fixed_puncture)
		puncture = "The ducttape is doing a remarkable job of sealing the puncture.";

	std::cout << antenna << puncture << std::endl;

}