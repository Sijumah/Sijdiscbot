module;

#include <deque>
#include <string>


export module dunedefs;


export namespace dunegame {


enum terri {
        broken_land, old_gap, basin, sihaya_ridge, gara_kulon,
        red_chasm, south_mesa, cielago_east, cielago_south, meridian,
        habanya_ridge_flat, habanya_sietch, habanya_erg, the_greater_flat, the_great_flat,
        funeral_plain, bight_of_the_cliff, rock_outcroppings, plastic_basin, tsimpo,
        hagga_basin, arsunt, carthag, imperial_basin, arrakeen,
        rim_wall_west, hole_in_the_rock, shield_wall, false_wall_east, pasty_mesa,
        the_minor_erg, tueks_sietch, false_wall_south, harg_pass, cielago_north,
        cielago_depression, cielago_west, wind_pass_north, false_wall_west, wind_pass,
        sietch_tabr, polar_sink, reserves, tleilexu_tanks
    };

enum factions { atreides, harkonnen, fremen, emperor, guild, bene, ixian, tleilexu };

struct force_token {

std::string appearance_filename_path;  //"For the picture of this token's artwork, go to this pathname".
short force_value;  //Almost always 1 or 2.
terri location;
//Generals are elsewhere, and override this class nonetheless.


};

struct basefaction;




};  //End of namespace dunegame.