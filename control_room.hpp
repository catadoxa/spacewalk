/*********************************************************************
 ** Program Filename: control_room.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Space contains a Pal object the Player can talk to in order to get
 ** information and progress the game.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef CONTROL_ROOM_HPP
#define CONTROL_ROOM_HPP

#include "space.hpp"
#include "pal.hpp"

class Control_Room : public Space {
	
	private:
		
		Pal *pal;
		
		
	public:
		Control_Room();
		~Control_Room();
		void special();
		Pal * get_pal() { return pal; }
};

#endif