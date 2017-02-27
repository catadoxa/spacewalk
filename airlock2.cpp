/*********************************************************************
 ** Program Filename: airlock2.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space that contains a Robot object Player must deal with for the game
 ** to progress.
 ** Input:
 ** Output:
**********************************************************************/

#include "airlock2.hpp"

#include <iostream>

/*********************************************************************
 ** Function: Airlock2::Airlock2()
 ** Description: initializes robot and descriptions.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Airlock2::Airlock2() {
	
	robot = new Robot();
	
	set_name("Airlock Compartment");
	set_description("\nA small room with airtight doors on both ends. A robot is here\n"
		"to safely operate the doors.\nA lever operating the outer door is here.");
	
	set_special_name("airlock control robot");
	set_special_option("Deal with the robot.");

}

/*********************************************************************
 ** Function: Airlock2::~Airlock2()
 ** Description: deletes robot
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Airlock2::~Airlock2() {

	delete robot;
	robot = NULL;

}

/*********************************************************************
 ** Function: void Airlock2::special() 
 ** Description: outputs description and calls robot interaction method.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Airlock2::special() {

	std::cout << "\nThe robot seems surly." << std::endl;

	robot->talk();

}