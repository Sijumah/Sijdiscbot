module;

#include <string>
#include <deque>
#include <tuple>
#include <memory>
#include <vector>
export module dunefactions;



import dunedefs;
import discord_profile_filesystem;
import dunemap;


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
std::vector<force_token> faction_army;
general faction_general;
ascendancy faction_ascendancy;
unsigned int internal_game_id;  //A randomized number incase the game needs a specific identifier for this faction. 




void move_forces_to_map(board_map* the_map, terri location, unsigned short supsector_present,std::vector<force_token*>& forces_to_remove){
    //the_map->unit_placements.push_back(unit_node{the_map->match_map(location),supsector_present,this,forces_to_remove});
the_map->hii.push_back(6);
};







};









};