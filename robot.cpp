/*********************************************************************
 ** Program Filename: robot.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Robot is an object that the Player must deal with to gain access to the
 ** Outside space. Mainly dialoge and action descriptions.
 ** Input:
 ** Output:
**********************************************************************/

#include "robot.hpp"
#include "menu.hpp"

#include <iostream>
#include <algorithm>

/*********************************************************************
 ** Function: Robot::Robot()
 ** Description: constructor initializes vectors with dialogue and action descriptions.
 ** annoyed must reach 3 for player to get tossed, setting tossed = true.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Robot::Robot() {

	tossed = false;
	annoyed = 0;
	
	questions.push_back("Can you please open the airlock?");
	questions.push_back("Ask the robot an illogical riddle.");	
	questions.push_back("Pull the lever to open the door.");
	
	questions.push_back("Return to previous menu.");
	
	
	puzzles.push_back("Can an omnipotent being create an object too heavy for the"
		"\nbeing to lift?");
	puzzles.push_back("Before the Big Bang, how long did it take until time began?");
	puzzles.push_back("A Cretan sails to Greece and says to some Greek men who are "
		"\nstanding upon the shore: \"All Cretans are liars.\" Did he speak the truth, "
		"\nor did he lie?");
	puzzles.push_back("A slim crocodile living in the Nile took a child. His mother "
		"\nbegged to have him back. The crocodile responded, \"If you guess correctly "
		"\nwhat I will do with him, I will return him. However, if you don't predict his "
		"\nfate correctly, I'll eat him.\"What statement should the mother make to save"
		"\nher child? ");
	
	responses.push_back("\nThe robot whirrs at you in annoyance from the riddle.");
	responses.push_back("\nThe robot is not happy about these riddles at all!");
	responses.push_back("\nThe robot thrashes toward angrily!");
	responses.push_back("\nThe robot has had enough! It opens the airlock door and tosses"
			" you out!");

}

/*********************************************************************
 ** Function: Robot::~Robot()
 ** Description: destructor does nothing
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Robot::~Robot() {



}

/*********************************************************************
 ** Function: std::vector<int> Robot::update_switches()
 ** Description: determines which menu options are valid to output, and maps the the option
 ** index to the menu number.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
std::vector<int> Robot::update_switches() {

	//set switches w/default sentinel value -1
	int size = questions.size();
	std::vector<int> switch_vals(size, -1);

	int count = 1;
	
	/*can you open the airlock, please?*/
	switch_vals[0] = count;
	count++;
	
	/*puzzle option*/
	if(book_read) {
		switch_vals[1] = count;
		count++;
	}
	
	/*pull lever*/
	switch_vals[2] = count;
	count++;
	
	/*return to previous*/
	switch_vals[3] = count;
	
	return switch_vals;


}

/*********************************************************************
 ** Function: void Robot::talk()
 ** Description: updates the switches and outputs menu options. calls function with the
 ** option chosen by the user.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Robot::talk() {
	
	std::cout << "\nThe robot looks angry, and slightly deranged." << std::endl;
	
	int opt = menu(questions, update_switches());
	
	talk_responses(opt);

}

/*********************************************************************
 ** Function: void Robot::talk_responses(int n)
 ** Description: returns the appropriate action depending on the paramater.
 ** Parameters: int n.
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Robot::talk_responses(int n) {

	random_shuffle(puzzles.begin(), puzzles.end());

	switch(n) {
	
		case 0:
			std::cout << "\nThe robot buzzes at you threateningly. You take this as a no."
				<< std::endl;
			break;
		
		case 1:
			std::cout << "You ask the robot: " << puzzles[0] << std::endl;
			std::cout << responses[annoyed] << std::endl;
			annoyed++;
			
			if(annoyed == 3) {
			
				std::cout << responses[annoyed] << std::endl;
				tossed = true;
				
			}
			break;
		
		case 2:
			std::cout << "\nThe robot blocks your path!" << std::endl;
			break;
		
		default:
			break;
	
	}

}