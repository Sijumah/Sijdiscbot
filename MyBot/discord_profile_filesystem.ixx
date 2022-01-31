module;

#include <string.h>
#include <string>
#include <deque>
#include <tuple>


export module discord_profile_filesystem;




export namespace Sijdisc {

struct gameprofile {


std::string game_name;
std::deque<std::pair<std::string,double>> game_stats;  //A deque of for instance, "Total Soldiers Placed","300.0". This is retrieved by reading and saving to files. 
std::deque<std::pair<std::string,std::string>> achievements;  //Achievements on a game-per-game basis ie... "Aggressive!","Place 500 soldiers".



};




struct profile {



std::string discord_id;
std::string personal_nickname;  //prompt for a nickname when creating the profile

std::deque<gameprofile> game_ledger;



};






















};  //End of export namespace.