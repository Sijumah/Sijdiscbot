#pragma once


#include <tuple>
#include <string>
#include <deque>

#include "dunefactions.hpp"
#include "dunedefs.hpp"


namespace dunegame {

std::deque<std::pair<std::string,std::string>> event_flags;  //Ie "fremen have gone yet", "yes".


std::deque<basefaction*> raw_order;
std::deque<basefaction*> this_turn_order;

void initial_unit_placements(){
    //if fremen is in game, put them last, then, if bene is in game, put them last in order. Using the order, call the "Set up" functions.

};

void prompt_player(){};  //includes dpp things. Have arguments for "is ephemeral message, is timelimit, is button confirm, is dropdown menu, etc"

void configure_game_options(){};  //options for this game, this time.

void message_everyone_their_ruleset(){};  //self explanatory

void worm_appearance() {};  //continue drawing for next worms (do many cards all at once). Also remember to do nexus. Have 'alliances enabled' be a toggleable rule

void spice_blow(){};  //if worm, call above function inside this one

void storm_movement(){};  //if fremen are in game... etc.

void check_storm_kill_for_current_sector(){};

void choam_charity(){};  //any allied people recieve 2 for free, then 4 if they're all under.

void free_revival_phase(){};  //handle free revival, preferring to give stronger troops first.

void paid_revival_phase(){};  //prompts people if they want to pay. 

void shipping_and_movement(){};  //every time have a 7~ sec prompt button for the spacing guild to go when they want;

bool sector_is_in_storm_check();  //for movement purposes and dying purposes

bool territory_has_ally();  //if so, disallow movement and beaming into that territory for those people

bool stronghold_has_two_already();  //if so, disallow movement and beaming into that territory

basefaction* determine_aggressor();  //for tiebreaking purposes

void scout_battles_for_faction(){};  //Scans the unit nodes for the current faction's turn, if they are in any battles. I could make a whole container system for holding all battles at once but I like this and processing speed doesn't matter here.

void prompt_choice_for_battle(){};  //if a single faction is in many.

bool has_heroes_left();  //simple check for a battle

void perform_battle();

bool for_this_phase_treachery_card_scan();  //scans all the factions to see if they have a card that can be used this phase

void for_this_phase_treachery_card_prompt(){};  //prompts the current (or maybe all?) faction(s) for 7~ if they want to use a card this phase.











};  //End of namespace dunegame.
