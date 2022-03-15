#pragma once 

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
       
        //hvylog("structt card(base)'s play function called");

       

    };  //Each overridden card has members that they can access themselves, and then call the play function with.

    //virtual int fetch_card_info() { return 0; };
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


template <class top_of_discard_pile_type>
struct dune_deck{


    std::vector<faction_hand*> players_hands;  //The deck is loaded with players to own the cards. 
    std::vector<card*> cards;  //These are pointers because dune_deck doesn't actually handle anything, the class overrides will contain the true cards.
    decltype(cards.begin()) sentinel;
    decltype(cards.end()) end_sentinel;
    
    top_of_discard_pile_type blank_card;  //Done so the top of the discard pile can have something at the beginning.

    //card* sentinel;  //This traverses the deck; personally I prefer having two containers that exchange pointers but this sentinel method along with the bool==isinplay is probably MARGINALLY faster.
    top_of_discard_pile_type* top_of_discard_pile;  //Players are always able to see the top card of the discard pile. 
    
    card* pick_at_random();
    void shuffle();
    void place_at_bottom();
    void place_at_top();
    void set_in_discard(card* supplied);
    void set_not_in_deck(card* supplied) { supplied->qis_in_discard = true; };
    card* draw_from_top();
    void initialize() { sentinel = cards.begin(); end_sentinel = cards.end(); top_of_discard_pile = &blank_card; }


    dune_deck(const std::vector<faction_hand*>& supplayers_hands, const std::vector<card*>& pointers_to_real_deck_cards) :
        players_hands(supplayers_hands), cards(pointers_to_real_deck_cards),
        
        blank_card(top_of_discard_pile_type{ std::string{ "path" } })
            ,/*ADD PATH FOR BLANK CARD*/
            //const std::string& sup_card_image,map_territory* suplinked_territory,short supamount
        top_of_discard_pile(&blank_card) 
    {};


};




};  //End of namespace dunegame.