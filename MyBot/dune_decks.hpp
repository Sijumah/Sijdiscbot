/*
module;

#include <vector>
#include <string>

export module dune_decks;

import dunedefs;
import dunemap;

export 
*/
#pragma once 
#include <vector>
#include <string>
#include <iostream>

#include "dunedefs.hpp"
#include "dunemap.hpp"

namespace dunegame {



struct card{
    
    std::string appearance_path;
    //basefaction* owner;
    bool qis_in_discard;
    card(const std::string& suppath/*, basefaction* supowner*/) :appearance_path(suppath), /*owner(supowner),*/ qis_in_discard(false) {};
    virtual void play() {
        std::cout << "hi";
       
        hvylog("structt card(base)'s play function called");

       

    };  //Each overridden card has members that they can access themselves, and then call the play function with.
};




struct traitor_card: public card{
    std::string hero_name;  //Works on any hero with the name, which is important for same-faction gameplay.
    void play() {};
    //Constructor
};

struct storm_card: public card{
    unsigned short value; 
    storm_card(unsigned short supvalue, const std::string& suppath,basefaction* supowner) :card(suppath/*, supowner*/), value(supvalue) {};
    void play() {};  //Advances the storm

    //1-6
    
};


struct faction_hand {
    short hand_limit;
    std::vector<card*> cards;

};


struct dune_deck{


    std::vector<faction_hand*> players_hands;  //The deck is loaded with players to own the cards. 
    std::vector<card*> cards;
    decltype(cards.begin()) sentinel;
    
    card blank_card;  //Done so the top of the discard pile can have something at the beginning.

    //card* sentinel;  //This traverses the deck; personally I prefer having two containers that exchange pointers but this sentinel method along with the bool==isinplay is probably MARGINALLY faster.
    card* top_of_discard_pile;  //Players are always able to see the top card of the discard pile. 
    
    card* pick_at_random();
    void shuffle();
    void place_at_bottom();
    void place_at_top();
    void set_in_discard(card* supplied);
    void set_not_in_deck(card* supplied) { supplied->qis_in_discard = true; };
    card* draw_from_top();



    dune_deck(const std::vector<faction_hand*>& supplayers_hands, const std::vector<card*>& supcards) :
        players_hands(supplayers_hands), cards(supcards),
        sentinel(this->cards.begin()), blank_card("hello"/*ADD PATH FOR BLANK CARD*/),
        top_of_discard_pile(&blank_card) 
    {};


};




};  //End of namespace dunegame.