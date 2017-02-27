/*********************************************************************
 ** Program Filename: menu.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: outputs menu options and gets user input.
 ** Input:
 ** Output:
**********************************************************************/

#include "menu.hpp"
#include <iostream>
#include <sstream>

/*********************************************************************
 ** Function: int menu(std::vector<std::string> opts, std::vector<int> switch_vals, std::string message)
 ** Description: outputs menu options using a switch to make sure they are valid menu
 ** options. Switch is also used to map the menu number to the option index.
 ** Parameters: std::vector<std::string> opts, std::vector<int> switch_vals, std::string message
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
int menu(std::vector<std::string> opts, std::vector<int> switch_vals, std::string message) {
	
	/*this will be the index of the opts entry chosen*/
	int opt = 0;
	
	/*menu greeting*/
	std::cout << message << std::endl;
	
	/*this will hold the highest switch value, ie largest menu option available*/
	int switch_max = 0;
	
	for(unsigned i = 0; i < switch_vals.size(); i++) {
		if(switch_vals[i] > 0) {
			std::cout << "   " << switch_vals[i] << ")   " << opts[i] << std::endl;
			
			/*don't actually need to compare? it should be invariant that last val is largest*/
			if(switch_vals[i] > switch_max)
				switch_max = switch_vals[i];
		}
	
	}
	
	bool input = false;
	while(!input) {
		std::cout << "Enter a menu option: ";
		std::string in;
		std::getline(std::cin, in);
		int n;
		
		if(std::istringstream(in) >> n && n > 0 && n <= switch_max) {
			input = true;
			/*
			 * this loop maps the menu option back to the correct index. I realize I could
			 * have also mapped the menu option to the index using an STL Map inside the
			 * update_switches() method, but that seemed like too much overhead for such 
			 * a small set of values.
			 */
			 for(unsigned i = 0; i < switch_vals.size(); i++) {
				if(switch_vals[i] == n)
					opt = i;
			 }
			
			
		} else
			std::cout << "That is not a menu option. ";
	}

	return opt;
}

/*********************************************************************
 ** Function: int menu(std::vector<std::string> opts, std::string message)
 ** Description: simply outputs menu options and gets user input.
 ** Parameters: std::vector<std::string> opts, std::string message
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
int menu(std::vector<std::string> opts, std::string message) {
	
	/*this will be the index of the opts entry chosen*/
	int opt = 0;
	
	std::cout << message << std::endl;
	
	for(unsigned i = 0; i < opts.size(); i++)
		std::cout << "   " << (i + 1) << ")   " << opts[i] << std::endl;
	
	
	bool input = false;
	while(!input) {
		std::cout << "Enter a menu option: ";
		std::string in;
		std::getline(std::cin, in);
		
		if(std::istringstream(in) >> opt && opt > 0 && opt <= (int) opts.size()) {
			input = true;
		} else
			std::cout << "That is not a menu option. ";
	}

	/*n = index + 1 so we subtract one now.*/
	opt--;
	
	return opt;
}