module;

#include <vector>


export module dunegame;

import dunemap;
import dunefactions;

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
export namespace dunegame {



struct dunegame {

board_map game_map;
std::vector<basefaction> factions;


};  //End of dunegame struct








};