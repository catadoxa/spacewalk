/*********************************************************************
 ** Program Filename: airlock1.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Derived from space, contains boolean and doors that must be reset to 
 ** true by Player actions for game to progress.
 ** Input:
 ** Output:
**********************************************************************/

#include "airlock1.hpp"

#include <iostream>
#include <sstream>

/*********************************************************************
 ** Function: Airlock1::Airlock1()
 ** Description: initializes members
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Airlock1::Airlock1() {

	doors = button = false;
	
	set_name("Airlock entryway");
	
	std::string desc = "\nIn this section of the deck you find the doors to the airlock. "
		"Opening \nthe airlock requires both operator and computer approval, for "
		"safety reasons \nor some similar nonsense.";
		
	set_description(desc);
	
	desc = "doors to the airlock";
	
	set_special_name(desc);
	
	desc = "Examine the airlock doors.";
	
	set_special_option(desc);

}

/*********************************************************************
 ** Function: Airlock1::~Airlock1()
 ** Description: does nothing
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Airlock1::~Airlock1() {



}

/*********************************************************************
 ** Function: void Airlock1::special()
 ** Description: outputs special options and descriptions
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Airlock1::special() {

	std::string door;
	
	if(!button && !doors)
		door = "The doors are closed. A glowing green button indicates they are locked.";
	else if(!doors)
		door = "The doors are closed. The green lock button has been disengaged, which\n"
			"allows the PAL computer to open the doors.";
	else
		door = "The doors stand open.";
		
	std::cout << "\nThe airlock is protected by a double door with an airtight seal, "
		"and a \nline of text informs you it was \"Designed by Robert Paye.\" A placard "
		"further \ninforms you that \"To initiate access, press the green button, "
		"designed \nby Claire Dodd.\" These engineers seem a tad full of themselves.\n"
		<< door << std::endl;
	
	/*this should all be sent through the menu() function but I just don't have time*/
	std::vector<std::string> opts(2);
	opts[0] = "Push the button.";
	opts[1] = "Return to previous menu.";
	
	bool input = false;
	std::string in;
	unsigned choice;
	
	while(!input) {
	
		std::cout << "\nYour options are: " << std::endl;
		
		for(unsigned i = 0; i < opts.size(); i++)
			std::cout << "   " << (i + 1) << ")   " << opts[i] << std::endl;
			
		std::cout << "Enter a menu option: ";
		std::getline(std::cin, in);
		
		if(std::istringstream(in) >> choice && choice > 0 && choice <= opts.size())
			input = true;
		else
			std::cout << "That is not a valid menu option." << std::endl;
	
	}
	
	if(choice == 1) {
		if(!button) {
			std::cout << "\nYou push the button." << std::endl;
			set_button(true);
		} else
			std::cout << "\nThe button has already been pushed." << std::endl;
	}
		
}