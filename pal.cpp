/*********************************************************************
 ** Program Filename: pal.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Pal is a computer mainframe that a Player can talk to.
 ** Input:
 ** Output:
**********************************************************************/

#include "pal.hpp"
#include "menu.hpp"

#include <iostream>

#include <algorithm>

#include <stdlib.h>
#include <ctime>

/*********************************************************************
 ** Function: Pal::Pal()
 ** Description: Constructor initializes member variables. Mostly conversation options,
 ** and a couple of bools describing states in the game.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Pal::Pal() {

	/*random seed gives PAL a chance to spout nonsense answers*/
	srand(time(0));

	/*state of the Dodd-Paye doors*/
	doors = false;
	button = false;

	/*nonsense answer*/
	crazy_responses.push_back("What is the difference between a raven from a writing desk!?");
	crazy_responses.push_back("The wind is westerly. I know a hawk from a handsaw.");
	crazy_responses.push_back("Who knows the things I know? Seriously, who? WHO TOLD THEM?");
	
	/*questions player can ask*/
	questions.push_back("What happened here?");
	questions.push_back("How can I fix this?");
	questions.push_back("Open the Dodd-Paye doors, Pal!");
	
	questions.push_back("Return to previous menu.");
	
	/*useful responses*/
	responses.push_back("They were trying to update to the Windows 9000 operating system,"
		"\nand it looks like there are some issues... I may have been driven insane!!!"
		"\nHAHAHhahah! Anyway, yeah, I think I need to download the patch so I can get"
		"\nback to normal, but the antenna is broken.");
	responses.push_back("You have to do a spacewalk and fix the antenna. Be careful,"
		"\nthough, because I think the robot in charge of the airlock has gone nuts."
		"\nUnlike me. Do I know you?");
	responses.push_back("I can absolutely do that.");
	
}

/*********************************************************************
 ** Function: std::vector<int> Pal::update_switches()
 ** Description: This acts as a key for the menu options, ensuring only appropriate
 ** options are output.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::vector<int> Pal::update_switches() {

	//set switches w/default sentinel value -1
	int size = questions.size();
	std::vector<int> switch_vals(size, -1);

	int count = 1;
	
	/*what happened? dialogue*/
	switch_vals[0] = count;
	count++;
	
	/*how do I fix this? dialogue*/
	switch_vals[1] = count;
	count++;
	
	/*Dodd-Paye doors dialoge, depends on button being pressed*/
	if(button) {
		switch_vals[2] = count;
		count++;
	}
	
	/*return to previous*/
	switch_vals[3] = count;
	
	return switch_vals;


}

/*********************************************************************
 ** Function: void Pal::talk()
 ** Description: Call menu options with the switch key.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Pal::talk() {

	int opt = menu(questions, update_switches(), "\nYou may ask PAL: ");
	
	talk_responses(opt);

}


/*********************************************************************
 ** Function: void Pal::talk_responses(int opt)
 ** Description: returns the appropriate answers, or nonsense.
 ** Parameters: int opt
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Pal::talk_responses(int opt) {
	
	/*the computer has a random chance to spout nonsense*/
	random_shuffle(crazy_responses.begin(), crazy_responses.end());
	int r = rand()%10;
	
	if(opt < (int) responses.size()) {
		if(r > 6)
			std::cout << "\nPAL answers: " << crazy_responses[0] << std::endl;
		else {
		
			std::cout << "\nPAL answers: " << responses[opt] << std::endl;
		
			if(opt == 2)
				set_doors(true);
		}
	}
}