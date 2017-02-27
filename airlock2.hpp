/*********************************************************************
 ** Program Filename: airlock2.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space that contains a Robot object Player must deal with for the game
 ** to progress.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef AIRLOCK2_HPP
#define AIRLOCK2_HPP

#include "space.hpp"
#include "robot.hpp"

#include <string>

class Airlock2 : public Space {

	private:

		Robot *robot;


	public:
		Airlock2();
		~Airlock2();
		void special();

		Robot * get_robot() { return robot; }

};

#endif