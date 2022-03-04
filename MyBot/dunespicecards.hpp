#pragma once

#include "dune_decks.hpp"

namespace dunegame {




	
struct spice_card: public card{


    map_territory* linked_territory;
    short amount;  //Amount of spice bestowed.
    virtual void play() { 
        linked_territory->spice_present += amount; 


    };  

    spice_card(const std::string& sup_card_image,map_territory* suplinked_territory,short supamount) :card(sup_card_image), linked_territory(suplinked_territory), amount(supamount) {};
    };

struct spice_worm_card : public spice_card {

    (spice_card*)* top_of_discard_pile_pointer;  //The top of the discard pile determines where the worm spawns.
    void play() { linked_territory->qhasworm = true; }
    
    spice_worm_card(const spice_card& sup_spice_card, spice_card** suptop_of_discard_pile_pointer) :
        spice_card(sup_spice_card), top_of_discard_pile_pointer(suptop_of_discard_pile_pointer) 
    {};

};






struct spice_deck : public dune_deck {



    short numworms;
    bool qissandtroutactive;
    std::vector<spice_card> spice_cards;
    std::vector<spice_worm_card> shai_hulud_cards;

    spice_deck(const std::vector<faction_hand*>& supplayers_hands, const std::string& discord_bot_filepath,board_map* supboardmap) :
        dune_deck(supplayers_hands, std::vector<card*>{}), numworms(0), qissandtroutactive(false),
               spice_cards({
                    //"dune game spice deck construct"
                    #define dgsdc(filename, maploc,spiceamount) spice_card{std::string{discord_bot_filepath+"/dunefiles/spice_"+filename+cif},&supboardmap->##maploc,spiceamount},
                    spice_card{ std::string{discord_bot_filepath + "/dunefiles/spice_cielago_south" + cif},& supboardmap->Cielago_South,12},
                    //Normal constructed version followed by shortcuts
                    dgsdc("wind_pass_north", Wind_Pass_North, 6)
                    dgsdc("red_chasm", Red_Chasm, 8)
                    dgsdc("hagga_basin", Hagga_Basin, 6)
                    dgsdc("sihaya_ridge", Sihaya_Ridge, 6)
                    dgsdc("habbanya_erg", Habbanya_Erg, 8)
                    dgsdc("the_great_flat", The_Great_Flat, 10)
                    dgsdc("funeral_plain", Funeral_Plain, 6)
                    dgsdc("habbanya_ridge_flat", Habbanya_Ridge_Flat, 10)
                    dgsdc("rock_outcroppings", Rock_Outcroppings, 6)
                    dgsdc("south_mesa", South_Mesa, 10)
                    dgsdc("broken_land", Broken_Land, 8)
                    dgsdc("cielago_north", Cielago_North, 8)
                    dgsdc("the_minor_erg", The_Minor_Erg, 8)
                    dgsdc("old_gap", Old_Gap, 6)
                    #undef dgsdc
                    }),  //end of spice_cards
               shai_hulud_cards({
                    spice_worm_card {spice_card{ std::string{discord_bot_filepath + "/dunefiles/wormcard" + cif},&supboardmap->Polar_Sink,0 }, top_of_discard_pile
    }
)
    {/*reinitialise the dunedeck pointers for active cards*/ }

    


    /*
    cielago_south
    12

    wind_pass_north
    6

    Shai-Hulud
    6

    red_chasm
    8

    hagga_basin
    6

    sihaya_ridge
    6

    (as opposed to Habanya?)
    habbanya_erg
    8

    the_great_flat
    10

    funeral_plain
    6

    sandtrout

    (not habanya?)
    habbanya_ridge_flat
    10

    (and not outcropping?)
    rock_outcroppings
    6

    south_mesa
    10

    broken_land
    8

    cielago_north
    8

    the_minor_erg
    8

    old_gap
    6

    */




}



};










};  //End of dunegame namespace.
