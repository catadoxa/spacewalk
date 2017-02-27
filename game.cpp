/*********************************************************************
 ** Program Filename: game.cpp
 ** Author: Joshua Kluthe
 ** Date: 03.15.2016
 ** Description: Game creates game elements, links them, and runs game until Player wins
 ** or loses.
 ** Input:
 ** Output:
**********************************************************************/

#include "game.hpp"

#include <iostream>

/*********************************************************************
 ** Function: Game::Game()
 ** Description: initialize variables, play the game.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Game::Game() {

	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	
	make_objects();
	
	make_rooms();
	
	link_world();
	
	player = new Player(name, bunk);
	player->add_object(gum1);

	
	lose = false;
	win = false;
	play_game();
	
	warning1 = warning2 = warning3 = warning4 = false;
	
	
}

/*********************************************************************
 ** Function: Game::~Game()
 ** Description: Destroy ALL THE THINGS!!!
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Game::~Game() {

	delete player;
	player = NULL;
	
	delete control_room;
	control_room = NULL;
	
	delete north_deck;
	north_deck = NULL;
	
	delete south_deck;
	south_deck = NULL;
	
	delete east_deck;
	east_deck = NULL;
	
	delete airlock1;
	airlock1 = NULL;
	
	delete airlock2;
	airlock2 = NULL;
	
	delete bunk;
	bunk = NULL;
	
	delete storage;
	storage = NULL;
	
	delete galley;
	galley = NULL;
	
	delete outside;
	outside = NULL;
	
	delete gum1;
	gum1 = NULL;
	
	delete gum2;
	gum2 = NULL;
	
	delete book;
	book = NULL;
	
	delete ducttape1;
	ducttape1 = NULL;
	
	delete ducttape2;
	ducttape2 = NULL;
	
	delete spacesuit;
	spacesuit = NULL;

}

/*********************************************************************
 ** Function: void Game::play_game()
 ** Description: runs game loop until win or lose
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Game::play_game() {


	std::time(&start);
	while(!lose && !win) {

		update_variables();
		
		player->get_location()->print_space();
		
		bool moved = false;
		
		while(!moved) {
		
			timer();
			
			if(!lose) {
			
				moved = update_variables();
			
				if(!moved)
					moved = player->space_options();
			} else
				moved = true;
		}
	}
	
	if(win) 
		std::cout << "\nCongratulations! you won!" << std::endl;
	else
		std::cout << "\nSorry, you lost!" << std::endl;
	
	
}

/*********************************************************************
 ** Function: void Game::timer()
 ** Description: times the player and issues warnings.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Game::timer() {
	
	std::time_t now;
	std::time(&now);
	
	if(!warning1) {
		std::cout << "\nA disembodied void calmly declares: \"Warning: hull breach imminent."
			"\nYou have 15 minutes until catastrophic system failure, likely resulting in"
			"\nDeath. Have a nice day.\"" << std::endl;
		warning1 = true;
	}
	
	if(!warning2 && (std::difftime(now, start) > 420)) {
		std::cout << "\nA disembodied void calmly declares: \"Warning: hull breach imminent."
			"\nYou have 8 minutes until catastrophic system failure, likely resulting in"
			"\nDeath. Have a nice day.\"" << std::endl;
		warning2 = true;
	}
	
	if(!warning3 && (std::difftime(now, start) > 720)) {
		std::cout << "\nA disembodied void calmly declares: \"Warning: hull breach imminent."
			"\nYou have 3 minutes until catastrophic system failure, likely resulting in"
			"\nDeath. Have a nice day.\"" << std::endl;
		warning3 = true;
	}
	
	if(!warning4 && (std::difftime(now, start) > 840)) {
		std::cout << "\nA disembodied void calmly declares: \"Warning: hull breach imminent."
			"\nYou have 1 minutes until catastrophic system failure, likely resulting in"
			"\nDeath. Have a nice day.\"" << std::endl;
		warning4 = true;
	}
	
	if(std::difftime(now, start) > 900) {
		std::cout << "\nA disembodied void calmly declares: \"Hull breached."
			"\nAll systems have failed. I hope your death is quick.\"" << std::endl;
		lose = true;
	}
	
}

/*********************************************************************
 ** Function: bool Game::update_variables()
 ** Description: Checks various game conditions, and updates other game conditions as it
 ** is needed. Basically the game demon that makes everything work. This is the guts of 
 ** it right here. Could have been avoided or greatly simplified with the use of global
 ** variables. Another option I considered was a struct of requirements all game objects
 ** would be aware of, but that also felt a lot like global variables. Anyway, heres the 
 ** demon in the box, Deus Ex Machina, etc...
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
bool Game::update_variables() {

	/*sets moved to true if we need to break out of the loop, or if player moves.*/
	bool moved = false;

	/*check button and Dodd-Paye door statuses*/
	control_room->get_pal()->set_button(airlock1->get_button());
	airlock1->set_doors(control_room->get_pal()->get_doors());

	/*if airlock doors open, set links between rooms*/
	if(airlock1->get_doors()) {
	
		airlock1->set_west(airlock2);
		airlock2->set_east(airlock1);
		
	}
	
	/*if spacesuit has been dropped, set unused = true. Probably should have just made
	* spacesuit a derived class of object but there is only so much time in the day*/
	if(!spacesuit->get_in_inv())
		spacesuit->set_used(false);
	
	/*update the robot on stuff*/
	/*check to see if player has read the book*/
	airlock2->get_robot()->set_book_read(book->get_used());
	
	/*update location and other variables if the robot tosses you from the airlock*/
	if(airlock2->get_robot()->get_tossed()) {
		player->move(outside);
		airlock2->set_south(outside);
		outside->set_north(airlock2);
		moved = true;
		airlock2->get_robot()->set_tossed(false);
	}
		
	/*reset various inventory options if the player is outside the space station*/
	if(player->get_location() == outside) {

		/*make the gum useful*/
		if(gum1->get_in_inv() && gum1->get_used()) {
		
				gum1->set_can_unuse(true);
				gum1->set_name("gum holding wires together");
				
		}
		if(gum2->get_in_inv() && gum2->get_used()) {
		
				gum2->set_can_unuse(true);
				gum2->set_name("gum holding wires together");
				
		}
		
		/*ducttape can be used to cover hole*/
		if(ducttape2->get_in_inv())
			ducttape2->set_can_use(true);
			
		if(ducttape2->get_in_inv())
			ducttape2->set_can_use(true);
		
		/*test to see if objects where used and update appropriately*/
		if(gum1->get_in_inv() && gum1->get_can_unuse() && !gum1->get_used()) {
			
			outside->set_fixed_antenna(true);
			player->drop_object(gum1);
			player->get_location()->remove_object(gum1);
			
			
		}
		
		if(gum2->get_in_inv() && gum2->get_can_unuse() && !gum2->get_used()) {
			
			outside->set_fixed_antenna(true);
			player->drop_object(gum2);
			player->get_location()->remove_object(gum2);
			
		}
		
		if(ducttape1->get_used() || ducttape2->get_used())
			outside->set_fixed_puncture(true);
	
	}
	/*if you fixed the antenna and the hull, you win!*/
	if(outside->get_fixed_puncture() && outside->get_fixed_antenna())
		win = moved = true;
	/*if you aren't wearing the spacesuit in vaccuum, you lose*/
	else if(airlock2->get_south() == outside && spacesuit->get_used() != true)
		lose = moved = true;
	
	return moved;
}

/*********************************************************************
 ** Function: void Game::make_objects()
 ** Description: creates all the objects used in the game, including descriptions.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Game::make_objects() {

	gum1 = new Object();
	gum1->set_name("gum");
	gum1->set_description("\nA stick of gum. Mint.");
	gum1->set_use_option("Chew the gum.");
	gum1->set_used_name("Chewed gum");
	gum1->set_used_description("\nA chewed piece of gum. Sticky.");
	gum1->set_used_use_option("Use the gum to stick the wires together.");
	gum1->set_describe_use("\nThe gum tastes slightly minty, mainly stale.");
	gum1->set_describe_unuse("\nYou jam the wires together and stick the gum on.");
	
	gum2 = new Object();
	gum2->set_name("gum");
	gum2->set_description("\nA stick of gum. Mint.");
	gum2->set_use_option("Chew the gum.");
	gum2->set_used_name("Chewed gum");
	gum2->set_used_description("\nA chewed piece of gum. Sticky.");
	gum2->set_used_use_option("Use the gum to stick the wires together.");
	gum2->set_describe_use("\nThe gum tastes slightly minty, mainly stale.");
	gum2->set_describe_unuse("\nYou jam the wires together and stick the gum on.");
	
	book = new Object();
	book->set_name("book");
	book->set_description("\nA book of logic puzzles.");
	book->set_use_option("Read the book.");
	book->set_used_name("book (read)");
	book->set_used_description("\nA book of logic puzzles you have already read through.");
	book->set_used_use_option("\nYou can do nothing with this right now.");
	book->set_describe_use("\nThe book contains some logical impossibilities, good for\n"
		"annoying robots, probably.");
		
	ducttape1 = new Object();
	ducttape1->set_name("ducttape");
	ducttape1->set_description("\nA normal roll of ducttape.");
	ducttape1->set_use_option("Put ducttape over the hole in the hull.");
	ducttape1->set_used_name("ducttape");
	ducttape1->set_used_description("\nA normal roll of ducttape.");
	ducttape1->set_used_use_option("\nNothing to use this for right now.");
	ducttape1->set_describe_use("\nYou apply a couple layers of ducttape over the hole.");	
	ducttape1->set_can_use(false);
	
	ducttape2 = new Object();
	ducttape2->set_name("ducttape");
	ducttape2->set_description("\nA normal roll of ducttape.");
	ducttape2->set_use_option("Put ducttape over the hole in the hull.");
	ducttape2->set_used_name("ducttape");
	ducttape2->set_used_description("\nA normal roll of ducttape.");
	ducttape2->set_used_use_option("Nothing to use this for right now.");
	ducttape2->set_describe_use("You apply a couple layers of ducttape over the hole.");	
	ducttape2->set_can_use(false);
	
	spacesuit = new Object();
	spacesuit->set_name("spacesuit");
	spacesuit->set_description("\nA standard issue spacesuit.");
	spacesuit->set_use_option("Put on spacesuit.");
	spacesuit->set_used_name("spacesuit (worn)");
	spacesuit->set_used_description("\nYou are wearing a standard issue spacesuit.");
	spacesuit->set_used_use_option("Remove spacesuit.");
	spacesuit->set_describe_use("\nYou put on the spacesuit.");
	spacesuit->set_describe_unuse("\nYou remove the spacesuit.");
	spacesuit->set_can_use(true);
	spacesuit->set_can_unuse(true);
	
	
}

/*********************************************************************
 ** Function: void Game::make_rooms()
 ** Description: creates all the spaces used in the game, including descriptions.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Game::make_rooms() {

	control_room = new Control_Room();
	airlock1 = new Airlock1();
	airlock2 = new Airlock2();
	outside = new Outside();
	
	north_deck = new Deck();
	north_deck->set_name("Deck Area One");
	north_deck->set_description("\nAn open section of deck with a door to the galley.");
	north_deck->set_special_string("\nYou see a beautiful view of the Earth rotating below you.");
	
	east_deck = new Deck();
	east_deck->set_name("Deck Area Two");
	east_deck->set_description("\nAn open section of deck with a door to a storage room.");
	east_deck->set_special_string("\nYou see some kind of monolith thing. It's weird and makes no sense");
	
	south_deck = new Deck();
	south_deck->set_name("Deck Area Three");
	south_deck->set_description("\nAn open section of deck with a door to a bedroom.");
	south_deck->set_special_string("\nYou see a beautiful starscape.");
	
	bunk = new Deck();
	bunk->set_name("Bunk Room");
	bunk->set_description("This room contains two bunks and a small night stand.");
	bunk->set_special_name("A radio transceiver with a blinking light");
	bunk->set_special_option("Listen to the radio transmission.");
	bunk->set_special_string("\nYou push the play button, and here a static-y message:\n"
		"\"This is mission control. Um, I'm afraid there has been a bit of an\n"
		"incident here... We were, uh, sending an update to PAL, and it looks like\n"
		"there was some corruption... Anyway, there was a system overload and it\n"
		"may have blown out the antenna. Hopefully you get this transmission, and\n"
		"hopefully you can get that fixed. There, uh, may have been some hull damage\n"
		"as well...\"\nThe message cuts out. Huh, that sucks.");
		
	storage = new Deck();
	storage->set_name("Storage Room");
	storage->set_description("This room contains some useless junk, like ducttape,\n"
		"and a spacesuit. It is rather gloomy. Perhaps turning on a light would help.");
	storage->set_special_name("light switch");
	storage->set_special_option("Flip the light switch.");
	storage->set_special_string("You flip the light switch. The gloom remains.");
	
	galley = new Deck();
	galley->set_name("Galley");
	galley->set_description("This room is used for preparing food, and contains a few\n"
		"random foodstuffs. They really didn't provision this ship very well. It also\n"
		"contains an ancient cassette player for some unknown reason.");
	galley->set_special_name("cassette player");
	galley->set_special_option("Listen to the cassette player.");
	galley->set_special_string("You turn on the cassette player, and hear Freddy Mercury\n"
		"singing about Galileo. No surprise there, really. It's a universal law that\n"
		"cassettes left alone long enough morph into Best of Queen albums.\n"
		"You turn it back off.");
		

}

/*********************************************************************
 ** Function: void Game::link_world()
 ** Description: links game elements together
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Game::link_world() {

	bunk->add_object(book);
	
	galley->add_object(gum2);
	
	galley->add_object(ducttape1);
	
	storage->add_object(ducttape2);
	
	storage->add_object(spacesuit);
	
	control_room->set_directions(north_deck, south_deck, east_deck, airlock1);
	
	airlock1->set_directions(north_deck, south_deck, control_room, NULL);
	
	airlock2->set_directions(NULL, NULL, NULL, NULL);
	
	outside->set_directions(NULL, NULL, NULL, NULL);
	
	north_deck->set_directions(galley, control_room, east_deck, airlock1);
	
	south_deck->set_directions(control_room, bunk, east_deck, airlock1);
	
	east_deck->set_directions(north_deck, south_deck, storage, control_room);
	
	bunk->set_directions(south_deck, NULL, NULL, NULL);
	
	galley->set_directions(NULL, north_deck, NULL, NULL);
	
	storage->set_directions(NULL, NULL, NULL, east_deck);
	
}
