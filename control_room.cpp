/*********************************************************************
 ** Program Filename: control_room.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space contains a Pal object the Player can talk to in order to get
 ** information and progress the game.
 ** Input:
 ** Output:
**********************************************************************/

#include "control_room.hpp"

#include <iostream>

/*********************************************************************
 ** Function: Control_Room::Control_Room()
 ** Description: initializes descriptions and Pal Object
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Control_Room::Control_Room() {
	
	/*create a PAL computer object*/
	pal = new Pal();
	
	/*set name and description*/
	set_name("Control Room");
	std::string desc = "\nThe Control Room has many blinking lights, some levers, a few "
		"buttons,\nand even a dial or two. It is dominated by a large orange indicator "
		"light\nshowing that the Programmatic Artificially Linguistic Computer, or PAL,"
		"\nis active. The PAL computer is a voice-address mainframe computer that "
		"\ncontrols many space station systems.";
		
	set_description(desc);
	
	/*set special name and description*/
	set_special_name("PAL Computer");
		
	desc = "Speak to PAL computer.";
	set_special_option(desc);

	
}

/*********************************************************************
 ** Function: Control_Room::~Control_Room()
 ** Description: deletes Pal
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Control_Room::~Control_Room() {

	delete pal;
	pal = NULL;

}

/*********************************************************************
 ** Function: void Control_Room::special()
 ** Description: outputs description and calls Pal interaction method
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Control_Room::special() {

	std::cout << "\nThe PAL computer's orange light blinks at you.\n"
		"PAL says: Hello! Do I know you?" << std::endl;
		
	pal->talk();

}