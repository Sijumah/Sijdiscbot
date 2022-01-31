module;

#include <string>
#include <deque>
#include <tuple>
#include <memory>

export module dunefactions;



import dunedefs;
import discord_profile_filesystem;

export namespace dunegame {

struct general{};
struct ascendancy{};


struct basefaction {

unsigned short faction_position;  //A faction's token position in terms of storm sectors. Usually will go in these sector positions in accordance with the board image file: 1-4-7-10-13-16
Sijdisc::profile player_profile;
factions identifier;
std::string name;
unsigned int spice_amount;
unsigned int forces_in_reserve;
std::deque<force_token> faction_army;
general faction_general;
ascendancy faction_ascendancy;
unsigned int internal_game_id;  //A randomized number incase the game needs a specific identifier for this faction. 

};









};