#pragma once 

#include "Sijf.hpp"

#include <string.h>
#include <string>
#include <deque>
#include <tuple>
#include <array>
#include<vector>
#include <optional>





namespace Sijdisc {

struct gameprofile {


    std::string game_name;
    std::deque<std::pair<std::string,double>> game_stats;  //A deque of for instance, "Total Soldiers Placed","300.0". This is retrieved by reading and saving to files. 
    std::deque<std::pair<std::string,std::string>> achievements;  //Achievements on a game-per-game basis ie... "Aggressive!","Place 500 soldiers".

    gameprofile(const std::string& supgame_name, const std::deque<std::pair<std::string, double>>& supgame_stats = {},
        const std::deque<std::pair<std::string, std::string>>& supachievments = {}) :
        game_name(supgame_name), game_stats(supgame_stats), achievements(supachievments)
    {}

    bool has_achievement_by_name(const std::string& searched_achievment) { for (auto&& it : achievements) { if (it.first == searched_achievment) { return true; } }return false; }
    std::optional<std::pair<std::string, double>*> find_stat_by_name(const std::string& supname) { for (auto&& it : game_stats) { if (it.first == supname) { return &it; } }return std::nullopt; }

};




struct profile {



    std::string discord_id;
    std::string personal_nickname;  //prompt for a nickname when creating the profile

    std::deque<gameprofile> game_ledger;

    profile(const std::string& supid = {}, const std::string& supnickname = {}, 
            const std::deque<gameprofile>& supprofile = {}) : 
        discord_id(supid), personal_nickname(supnickname), game_ledger(supprofile)
    {};

    std::optional<gameprofile*> 
    find_game_in_ledger(const std::string& game_name) { for (auto&& it : this->game_ledger) { if (it.game_name == game_name) { return &it; } }return std::nullopt; }

    void add_game_to_ledger(const std::string& game_name, const std::deque<std::pair<std::string, double>>& supgame_stats = {},
                                 const std::deque<std::pair<std::string, std::string>>& supachievments = {}) { 
        if (find_game_in_ledger(game_name)) { return; }  //If game already exists, return.
        game_ledger.emplace_back(game_name,supgame_stats,supachievments); }  //Otherwise add it to the list of games with the given achievements and stats.

    void add_modify_achievement_by_names(const std::string& gamename,const std::pair<std::string,std::string>& supachiev) {
        auto game = find_game_in_ledger(gamename);
        if (game) {  //If the game was found
             if (!(* game)->has_achievement_by_name(supachiev.first)) {  //If it doesnt already have the achievment,
             (*game)->achievements.push_back(supachiev); }  //Add it.
        }
    }

    void add_modify_stat_by_names(const std::string& gamename,const std::pair<std::string ,double>& supstat) {
        auto game= find_game_in_ledger(gamename);  //Find the game
        std::optional<std::pair<std::string, double>*> stat;
        if (game) {stat = (*game)->find_stat_by_name(supstat.first);  //IF a game was found, find the stat by name.
             if (stat) { *stat.value() = supstat; }  //If the stat was found, modify it,
                 else { game.value()->game_stats.push_back(supstat); }  //else, make a new entry for the stat.
        }
    };



};  //End of profile

//╣├






struct profile_collection {
    std::deque<profile> collection;
    std::string path;  //path to the folder where all of the people are stored


    void add_new_profile(const std::string& discord_id, const std::string& nickname) {
        this->collection.push_back(profile(discord_id, nickname, std::deque<gameprofile>{}));
    };

    std::optional<profile*> get_profile_by_name(const std::string& supname) { 
        for (auto&& it : this->collection) { if (it.personal_nickname == supname) return &it; }
        return std::nullopt; 
    };

    void add_games_to_profiles_by_name(const std::string& game_name, const Sijc::stl_ish auto& profile_names) {
        std::optional<profile*> helper;
        for (auto&& it : profile_names) { helper = get_profile_by_name(it); if (helper) { (*(helper))->add_game_to_ledger(game_name); } }
    }



/*
profile and gameprofile text file:
personalnickname.txt:
name >personal_nick<
12345 >discordid<
dune#poker >gamelist<   //list of game names separated by #'s
soldiers placed#15%spice gained#20>dunestats< //The stats for a specific game in the form of thing#number%nextthing#nextnumber; the title being gamename+stats
Agressive!#Play 500 Soldiers%Winner#Win 10 games >duneachievs<   //the above except for achievements

If I can these >< delimiters will be ╣ ├   */

void write_to_files() {    //Oh god this was painful. I should have made it into a class system and so on. I was like "oh, it wont take too long to do manually". Ugh.
    for (auto&& it : collection) {  //For each player,
        std::vector<std::string> to_write{};  //Less efficient than it could be, but it won't matter for this program.
        to_write.emplace_back(it.personal_nickname+">personal_nick<\n"+it.discord_id+">discordid<\n");  //Add their personal nickname and discord ids with identifiers to be found later
        std::string game_list_string{};
        for (auto&& gameit : it.game_ledger) {  //For each game, of each player:
            game_list_string += gameit.game_name+"#";  //add the name of the game to the string containing all games ie dune#poker
            std::string individual_game_stats{};
            for (auto&& statsit : gameit.game_stats) { individual_game_stats += statsit.first + "#" + std::to_string(statsit.second) + "%"; }  //for the gamestats, which is a container, make a string of the concactenation of the statname and its value ie soldiers placed#10; separate them with % for each new stat
            if (individual_game_stats.size() != 0) { if (individual_game_stats.back() == '%') { individual_game_stats.pop_back(); } }  //remove an erroneous trailing %
            to_write.emplace_back(individual_game_stats+">" + gameit.game_name + "stats<\n");  //add that thing to the writing table, along with its identifier ie ">dunestats<"
            std::string individual_game_achievs{};
            for (auto&& achievsit : gameit.achievements) { individual_game_achievs += achievsit.first + "#" + achievsit.second + "%"; }  //Repeat that process with achievements which are two strings instead of a string and float
            if (individual_game_achievs.size() != 0) { if (individual_game_achievs.back() == '%') { individual_game_achievs.pop_back(); } }  //remove an erroneous trailing %
            to_write.emplace_back(individual_game_achievs + ">" + gameit.game_name + "achievs<\n");  //Add THAT to the writing table with ">duneachievs<"
        }
        if (game_list_string.size() != 0) { if (game_list_string.back() == '#') { game_list_string.pop_back(); } }  //remove an erroneous trailing # 
        to_write.emplace_back(game_list_string + ">gamelist<\n");  //add the games list string to the doc such that its dune#poker>gamelist<
        Sijf::printtofile(to_write,path+"/"+it.personal_nickname+".txt",1);
    }
};

~profile_collection() { this->write_to_files(); };

profile_collection(const std::string& folder_path, const std::vector<std::string>& names_without_txt) { //it is only folder PATH, that way the constructor can just open the individual text files for the individual players.
    this->path = folder_path;
    std::fstream stream;
    
    //std::array<std::string, 3> 
    std::vector<std::string>  templat{"personal_nick","discordid","gamelist"};
        
    for (auto&& it : names_without_txt) {    ///One loop is one name-- one profile, one person, one body in christ everlasting, amen.
        stream.open(folder_path + "/"+it + ".txt");
        std::deque<gameprofile> sup_gameprofiles;
        auto helper = Sijf::ret_many_file_lines<std::vector<std::string>>(stream, '>', '<',/*'╣', '├',*/ templat,false);
        
        
        //spits out personalnickname discordid gamelist
        auto gamelistseparated = Sijf::breakstring(helper.at(2), '#');  //separate the gamelist into for instance 'dune','poker'

 //  soldiers placed#15 % spice gained#20 > dunestats< //The stats for a specific game in the form of thing#number%nextthing#nextnumber; the title being gamename+stats
  //          Agressive!#Play 500 Soldiers % Winner#Win 10 games >duneachiev<   //the above except for achievements

        
        for (auto gameit : gamelistseparated) {  //Each of these is a game within each name's txt file
            auto gamestats = Sijf::retfileline(stream, '>', '<', (gameit + "stats"));  ///*'╣', '├',*/
            auto broken_game_stats = Sijf::breakstring(*gamestats, '%');  //Breaks into the category: "soldiers placed#15"

            std::deque<std::pair < std::string, double >> individual_game_stats{};
            std::deque<std::pair<std::string, std::string>> individual_game_achievements{};

            for (auto&& lesserit : broken_game_stats) {
                auto fully_broken_stat = Sijf::breakstring(lesserit, '#');  //Breaks into {"soldiers placed", "15"}
                individual_game_stats.emplace_back(fully_broken_stat.at(0), std::stod(fully_broken_stat.at(1)));
            };  //creates the pair and the "15" to a double

            auto gameachievs = Sijf::retfileline(stream, '>', '<',/*'╣', '├',*/ (gameit + "achievs"));


            auto broken_game_achievs = Sijf::breakstring(*gameachievs, '%');

            for (auto&& lesserit : broken_game_achievs) {
                auto fully_broken_achiev = Sijf::breakstring(lesserit, '#');  //Breaks into {"barbaric!" "win 10 games"}
                individual_game_achievements.emplace_back(fully_broken_achiev.at(0), fully_broken_achiev.at(1));
            }


            sup_gameprofiles.emplace_back(std::string{ gameit }, individual_game_stats, individual_game_achievements);

        }

//  gameprofile(const std::string & supgame_game, const std::deque<std::pair<std::string, double>>&supgame_stats,
      //        const std::deque<std::pair<std::string, std::string>>&supachievments) :

            
        collection.emplace_back(helper.at(1),helper.at(0),sup_gameprofiles);
        
        stream.close();
         }

};








};  //End of profile_collection.






};  //End of export sijdisc namespace

