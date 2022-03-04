/*module;

#pragma once

#include <string>
#include <deque>
#include <tuple>
#include <memory>
#include <vector>
#include <optional>



export module dunefactions;



import dunedefs;
import discord_profile_filesystem;
import dunemap;
import dune_decks;

export */

#pragma once

#include <string>
#include <deque>
#include <tuple>
#include <memory>
#include <vector>
#include <optional>

#include "dunedefs.hpp"
#include "discord_profile_filesystem.hpp"
#include "dunemap.hpp"
#include "dune_decks.hpp"
namespace dunegame {


struct general: public force_token{
    

    void general_invoke();
//constructor that fulfills force_token()
};
struct ascendancy{};

struct hero{

std::string art_file_path;
unsigned short strength;
std::string name;
terri location;  //Location once deployed
std::pair<bool,basefaction*> isprisoner;  //starts at 0, if its 1, after a battle, all prisoners are returned to their original faction, held as the basefaction*. Upon constructing this, set their basefaction to be the owner from the outset. 
bool isdead;  //if dead, they are suceptible to the tleilaxu revival
bool isfacedown;  //if theyre dead and this is the case, they may not be revived again until etc etc.
traitor_card accompanying_card;  //The traitor deck will be loaded up with these very cards.


};


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
std::vector<hero> heroes;
std::pair<bool,basefaction*> isallied;  //once they are allied, their ally is placed here
std::string alliance_ability;  //a blurb of the alliance ability sent to the players
std::string faction_abilities;  //a blurb of the faction abilities sent to the players
faction_hand treachery_cards;
faction_hand traitor_cards; 

//In the basefaction constructor have the traitor cards add themselves to the traitor card deck

void move_forces_to_map(board_map* the_map, terri location, unsigned short sector_travelling_to, std::vector<force_token*>& forces_to_remove) {
    the_map->unit_placements.push_back(unit_node{ the_map->match_map(location),sector_travelling_to,this,forces_to_remove });
    //This does NOT move units from one vector to another; a faction is always in possession of their troops.
};







};  //End of basefaction.









};