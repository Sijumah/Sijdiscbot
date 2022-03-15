#pragma once


#include "dunedefs.hpp"
#include "dunemap.hpp"
#include "dunefactions.hpp"
#include "dune_decks.hpp"
#include "dunespicecards.hpp"

namespace dunegame {

//TODO: remember to number the territories on the map
//TODO reminder to check if factions are separated by a storm-- if they are, they don't have to fight. 
//TODO add a "hints" level for the game. On high level it will provide walkthroughs for the whole game as it happens, for lower, it will give reminders about certain things, and lowest, only describe the nessessities
//TODO: Remember to prompt players to choose 1-4-7-10-13-16 on the board map for their factions unless overriding the rules
//TODO: Make a "token location chooser" that accepts the factions in the game and lets it choose between random, in-order placement in the event of two factions allying, justaposed (two allies opposite eachother), or specific placement done by discord message input
//TODO: Add the force token pathnames to dunefactions's factions' force tokens
//TODO: Add debug tools like changing force positions
//TODO: allow for peopel to be recognised as admins for the purposes of undoing moves etc
//TODO: have a repository of game rules that one can resent so one doesnt have to retype all the time
//TODO: add the ability to add the notes on the fly (sent and given to files)
//TODO: the game must export and import a list of stats and achievements to track from the stats and achievements file; see discord_profile_filesystem.ixx
//TODO: //For truthtrance, have a game option that enables an admin to... enter an "enduring condition" like >player1 must not invade X this turn. and a turn number for it to expire on.
//TODO: in dune decks:   /*ADD PATH FOR BLANK CARD*/
//in dunemap: map_territory create the spawnworm() function
//TODO: write to console/discord that spice was placed. dunespicecards.hpp
//TODO: create the ability to change when worms appear or disappear (ie, when NEW worms appear, or just the turn after)
//TODO: reset "numworms" in the dune spice deck every turn (yes, even if we're following the 'worms persist until new worms appear' rule)
//dune_deck constructor:   sentinel(this->cards.begin()), blank_card("hello"/*ADD PATH FOR BLANK CARD*/),
//spice_worm_card member top of discard pile pointer may need to be a pointer to a pointer
/*TODO: add prompt messages to spice_worm_card for if sandtrout is active or not*/
//worms are path/dunefiles/wormcard+cif and sandtrout are path/dunefiles/sandtroutcard+cif
//reenable hvylog in dunedefs and so far, its only appearance in dune_decks::card::card()

//Helping notes:
//For dune_deck and spice deck and so on, you deal players cards by using the dune_deck players_hands pointer holder
//Spice cards are discord_bot_filepath+/dunefiles/spice_ and then a lowercase instanciation of the map territory ie wind_pass_north and then "cif" which is the chosen filetype like png. So: bot_filepath/dunefiles/spice_cielago_south.png"
//wormcards are bot_filepath/dunefiles/wormcard.cif where .cif is png probably




struct dunegame {

board_map game_map;
std::vector<basefaction> factions;



spice_deck spice_deck;  //For this, create a 'faction hand' right here owned by the game, so to speak. 

//dune_deck treachery_deck;
//dune_deck traitor_deck;  //Load this with the traitor cards found in the factions' hands themselves. 













};  //End of dunegame struct








};