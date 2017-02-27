/*********************************************************************
 ** Program Filename: robot.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Robot is an object that the Player must deal with to gain access to the
 ** Outside space. Mainly dialoge and action descriptions.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <vector>
#include <string>

class Robot {

	private:
	
		bool tossed;
		bool book_read;
	
		int annoyed;
	
		std::vector<std::string> questions;
		
		std::vector<std::string> responses;
		
		std::vector<std::string> puzzles;
	
	public:
	
		Robot();
		
		~Robot();
		
		void talk();

		void talk_responses(int n);

		std::vector<int> update_switches();
		
		void set_book_read(bool book_read) { this->book_read = book_read; }
		bool get_book_read() { return book_read; }
		
		void set_tossed(bool tossed) { this->tossed = tossed; }
		bool get_tossed() { return tossed; }
		
};

#endif