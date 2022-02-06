module;

#include <string>

export module dune_decks;

export namespace dunegame {

struct card{};

struct treachery_card: public card{};

struct spice_card: public card{};

struct traitor_card: public card{};

struct storm_card: public card{};


struct dune_deck{


//Has functions like "shuffle" and so on.
//Has the raw cards and then the shuffled, pointer versions that also hold who owns them atm.


};

struct spice_deck : public dune_deck {




};

struct treachery_deck : public dune_deck {


};

struct traitor_deck: public dune_deck{
    //unknown if this one is necessary. Be sure to make it work with having multiple of the same faction.

};












};  //End of namespace dunegame.