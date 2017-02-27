/*********************************************************************
 ** Program Filename: game.hpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Game creates game elements, links them, and runs game until Player wins
 ** or loses.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "airlock1.hpp"
#include "control_room.hpp"
#include "space.hpp"
#include "player.hpp"
#include "pal.hpp"
#include "deck.hpp"
#include "object.hpp"
#include "airlock2.hpp"
#include "robot.hpp"
#include "outside.hpp"

#include <vector>
#include <string>

#include <ctime>

class Game {

	private:
	
		Player *player;
		
		bool lose;
		bool win;
		
		Control_Room *control_room;
		Deck *north_deck;
		Deck *south_deck;
		Deck *east_deck;
		Airlock1 *airlock1;
		Airlock2 *airlock2;
		Deck *bunk;
		Deck *storage;
		Deck *galley;
		Outside *outside;
	
		Object *gum1;
		Object *gum2;
		Object *book;
		Object *ducttape1;
		Object *ducttape2;
		Object *spacesuit;
		
		bool update_variables();
		
		void make_rooms();
		void make_objects();
		void link_world();
		
		bool warning1;
		bool warning2;
		bool warning3;
		bool warning4;
		
		std::time_t start;
	
		void timer();
	
	public:
	
		Game();
		
		~Game();

		void play_game();
};

#endif