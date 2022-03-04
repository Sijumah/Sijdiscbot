/*module;
#include <string>
#include <list>
#include <tuple>
#include <deque>
#include <vector>
#include <memory>
#include <array>

export module dunemap;



import dunedefs;

export */
#pragma once

#include <string>
#include <list>
#include <tuple>
#include <deque>
#include <vector>
#include <memory>
#include <array>

#include "dunedefs.hpp"

namespace dunegame {



struct map_territory {

std::string name;
terri value;
short spice_present;
std::vector<unsigned short> sectors_present;
bool is_storm_protected;
bool qhasworm;



};





struct unit_node {

map_territory* territory;
unsigned short sector_present;  //Ie 0 for 'Storm Start'
basefaction* internal_faction_id;
//unsigned int internal_faction_id;  //This is 'internal_game_id' from the factions module which will identify the specific faction. I could save some processing power by saving a pointer but I don't 
std::vector<force_token*> forces;



};


struct board_map {

std::deque<unit_node> unit_placements;  //All placements on the map at the moment.
unsigned short storm_pos;  //Current storm position.

map_territory Broken_Land{"Broken Land",broken_land,0,std::vector<unsigned short>{10,11},0,false};
map_territory Old_Gap{ "Old Gap",old_gap,0,std::vector<unsigned short>{8,9,10},0,false };
map_territory Basin{ "Basin", basin,0,std::vector<unsigned short>{8},0 ,false };
map_territory Sihaya_Ridge{ "Sihaya Ridge",sihaya_ridge ,0,std::vector<unsigned short>{8},0,false };
map_territory Gara_Kulon{ "Gara Kulon", gara_kulon,0,std::vector<unsigned short>{7},0,false };
map_territory Red_Chasm{ "Red Chasm", red_chasm,0,std::vector<unsigned short>{6},0 ,false };
map_territory South_Mesa{ "South Mesa",south_mesa ,0,std::vector<unsigned short>{3,4,5},0,false };
map_territory Cielago_East{ "Cielago East", cielago_east,0,std::vector<unsigned short>{2,3},0,false };
map_territory Cielago_South{ "Cielago South", cielago_south,0,std::vector<unsigned short>{1,2},0,false };
map_territory Meridian{ "Meridian", meridian,0,std::vector<unsigned short>{0,1},0 ,false };
map_territory Habbanya_Ridge_Flat{ "Habbanya Ridge Flat", habbanya_ridge_flat,0,std::vector<unsigned short>{16,17},0 ,false };
map_territory Habbanya_Sietch{ "Habbanya Sietch",habbanya_sietch ,0,std::vector<unsigned short>{16},0,false };
map_territory Habbanya_Erg{ "Habbanya Erg", habbanya_erg,0,std::vector<unsigned short>{15,16},0 ,false };
map_territory The_Greater_Flat{ "The Greater Flat", the_greater_flat,0,std::vector<unsigned short>{15},0 ,false };
map_territory The_Great_Flat{ "The Great Flat", the_great_flat,0,std::vector<unsigned short>{14},0 ,false };
map_territory Funeral_Plain{ "Funeral Plain",funeral_plain ,0,std::vector<unsigned short>{14},0 ,false };
map_territory Bight_Of_The_Cliff{ "Bight Of The Cliff",bight_of_the_cliff ,0,std::vector<unsigned short>{13,14},0 ,false };
map_territory Sietch_Tabr{ "Sietch Tabr",sietch_tabr ,0,std::vector<unsigned short>{13},1 ,false };
map_territory Rock_Outcroppings{ "Rock Outcroppings",rock_outcroppings ,0,std::vector<unsigned short>{12,13},0 ,false };
map_territory Tsimpo{ "Tsimpo", tsimpo,0,std::vector<unsigned short>{10,11,12},0,false };
map_territory Imperial_Basin{ "Imperial Basin",imperial_basin ,0,std::vector<unsigned short>{8,9,10},1 ,false };
map_territory Arrakeen{ "Arrakeen",arrakeen ,0,std::vector<unsigned short>{9},1 ,false };
map_territory Rim_Wall_West{ "Rim Wall West", rim_wall_west,0,std::vector<unsigned short>{8},1 ,false };
map_territory Hole_In_The_Rock{ "Hole In The Rock",hole_in_the_rock ,0,std::vector<unsigned short>{8},0 ,false };
map_territory Shield_Wall{ "Shield Wall",shield_wall ,0,std::vector<unsigned short>{7,8},1 ,false };
map_territory Pasty_Mesa{ "Pasty Mesa",pasty_mesa ,0,std::vector<unsigned short>{4,5,6,7},1 ,false };
map_territory Tueks_Sietch{ "Tuek's Sietch",tueks_sietch ,0,std::vector<unsigned short>{4},1 ,false };
map_territory False_Wall_South{ "False Wall South", false_wall_south,0,std::vector<unsigned short>{3,4},1 ,false };
map_territory Cielago_Depression{ "Cielago Depression", cielago_depression,0,std::vector<unsigned short>{0,1,2},0 ,false };
map_territory Cielago_West{ "Cielago West",cielago_west ,0,std::vector<unsigned short>{0,17},0 ,false };
map_territory False_Wall_West{ "False Wall West",false_wall_west ,0,std::vector<unsigned short>{15,16,17},1 ,false };
map_territory Plastic_Basin{ "Plastic Basin", plastic_basin,0,std::vector<unsigned short>{11,12,13},1,false };
map_territory Hagga_Basin{ "Hagga Basin", hagga_basin ,0,std::vector<unsigned short>{11,12},0 ,false };
map_territory Carthag{ "Carthag",carthag ,0,std::vector<unsigned short>{10},1 ,false };
map_territory Arsunt{ "Arsunt", arsunt,0,std::vector<unsigned short>{10,11},0 ,false };
map_territory False_Wall_East{ "False Wall East",false_wall_east ,0,std::vector<unsigned short>{4,5,6,7,8},1,false };
map_territory The_Minor_Erg{ "The Minor Erg",the_minor_erg ,0,std::vector<unsigned short>{4,5,6,7},0,false };
map_territory Harg_Pass{ "Harg Pass",harg_pass ,0,std::vector<unsigned short>{3,4},0 ,false };
map_territory Cielago_North{ "Cielago North",cielago_north ,0,std::vector<unsigned short>{0,1,2},0 ,false };
map_territory Wind_Pass_North{ "Wind Pass North", wind_pass_north,0,std::vector<unsigned short>{16,17},0,false };
map_territory Wind_Pass{ "Wind Pass",wind_pass ,0,std::vector<unsigned short>{13,14,15,16},0 ,false };
map_territory Polar_Sink{ "The Polar Sink",polar_sink ,0,std::vector<unsigned short>{},1 ,false };
map_territory Reserves{"Reserves",reserves,0,std::vector<unsigned short>{},1,false };
map_territory Tleilexu_Tanks{"Tleilexu Tanks", tleilexu_tanks,0,std::vector<unsigned short>{},1,false };

std::array<map_territory*,43> map_conglomerate;  //I realise now that I probably shouldnt have made them all separate (as seen above), but this isn't a processing intensive program.

map_territory* match_map(terri to_search){
    for (auto& it: map_conglomerate){if (it->value==to_search){return it;}}
}


};



//https://cf.geekdo-images.com/camo/ffd65441820d78ce1515895c46814c4326cc5650/68747470733a2f2f692e696d6775722e636f6d2f3072316e7555432e6a7067
//https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/a9755b04-7225-464f-a4cc-41c03cdf8617/d34h16b-1d66766f-6596-4ec4-b8e3-347693c4ee1f.jpg/v1/fill/w_848,h_942,q_70,strp/dune___board_game_map_by_ilya_b_d34h16b-pre.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOjdlMGQxODg5ODIyNjQzNzNhNWYwZDQxNWVhMGQyNmUwIiwiaXNzIjoidXJuOmFwcDo3ZTBkMTg4OTgyMjY0MzczYTVmMGQ0MTVlYTBkMjZlMCIsIm9iaiI6W1t7ImhlaWdodCI6Ijw9MTE1MCIsInBhdGgiOiJcL2ZcL2E5NzU1YjA0LTcyMjUtNDY0Zi1hNGNjLTQxYzAzY2RmODYxN1wvZDM0aDE2Yi0xZDY2NzY2Zi02NTk2LTRlYzQtYjhlMy0zNDc2OTNjNGVlMWYuanBnIiwid2lkdGgiOiI8PTEwMzYifV1dLCJhdWQiOlsidXJuOnNlcnZpY2U6aW1hZ2Uub3BlcmF0aW9ucyJdfQ.PAUlwEvKujb4-fEOqQhPtkAFIAbSt-4WxLlhFwXbWMo











};  //End of namespace dunegame.