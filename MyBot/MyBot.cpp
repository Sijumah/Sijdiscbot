#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "dunedefs.hpp"
//#include "Sijf.hpp"

//F:\Folder in Which Things are Storesd\Hobbies, etc\Coding\discord_bot_files\dunefiles
std::string get_token() {

    std::ifstream reader("C:\\Users\\Sijumah\\Desktop\\discordtoken.txt",std::ifstream::in);
    //char buffer[61];
    std::string answer;
    std::getline(reader, answer);
    reader.close();
    return answer;
    

};
std::string Sbot_token = get_token();


#define mainver 1
#define buttontestver 2
#define messagetestver 3
#define menutestver 4
#define manybuttonver 5


#define selector mainver




#if selector == mainver

#include "discord_profile_filesystem.hpp"

int main() {
    
    //C:\SijPrograms\accounts
    //"C:/Users/sicma/Desktop/accounts"
  //  Sijdisc::profile_collection bob("C:/SijPrograms/accounts", std::vector<std::string>{"kent","billhelm"});
   // bob.add_new_profile("12345", "janus2");
    
    hvylog("hi")
    
    return 0; };



#endif



#if selector == manybuttonver

#include <dpp/dpp.h>

using json = nlohmann::json;

int main()
{

    dpp::cluster bot(Sbot_token);

    bot.on_button_click([&bot](const dpp::button_click_t& event) {
        if (event.custom_id == "10") {
            event.reply(dpp::ir_channel_message_with_source, dpp::message("Correct").set_flags(dpp::m_ephemeral));
        }
        else {
            event.reply(dpp::ir_channel_message_with_source, dpp::message("Incorrect").set_flags(dpp::m_urgent));
        }
        });

    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if (event.msg.content == "!ping2") {
            bot.message_create(
                dpp::message(event.msg.channel_id, "What is 5+5?").add_component(
                    dpp::component().add_component(
                        dpp::component().set_label("9").
                        set_style(dpp::cos_primary).
                        set_id("9")
                    ).add_component(
                        dpp::component().set_label("10").
                        set_style(dpp::cos_primary).
                        set_id("10")
                    ).add_component(
                        dpp::component().set_label("11").
                        set_style(dpp::cos_primary).
                        set_id("11")
                    )
                )
            );
        }
        });

    bot.start(false);

return 0;

}
#endif



#if selector == menutestver
#include <dpp/dpp.h>

using json = nlohmann::json;

int main()
{

    dpp::cluster bot(Sbot_token);

    /* Message handler to look for a command called !select */
    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if (event.msg.content == "!select") {
            /* Create a message containing an action row, and a select menu within the action row. */
            dpp::message m(event.msg.channel_id, "this text has a select menu");
            m.add_component(
                dpp::component().add_component(
                    dpp::component().set_type(dpp::cot_selectmenu).
                    set_placeholder("Pick something").
                    add_select_option(dpp::select_option("label1", "value1", "description1")).
                    add_select_option(dpp::select_option("label2", "value2", "description2")).
                    set_id("myselid")
                )
            );
            bot.message_create(m);
        }
        });
    /* When a user clicks your select menu , the on_select_click event will fire,
     * containing the custom_id you defined in your select menu.
     */
    bot.on_select_click([&bot](const dpp::select_click_t& event) {
        /* Select clicks are still interactions, and must be replied to in some form to
         * prevent the "this interaction has failed" message from Discord to the user.
         */
        event.reply(dpp::ir_channel_message_with_source, "You clicked " + event.custom_id + " and chose: " + event.values[0]);
        });

    bot.on_log([](const dpp::log_t& event) {
        if (event.severity > dpp::ll_trace) {
            std::cout << event.message << "\n";
        }
        });

    bot.start(false);

    return 0;
}

#endif





#if selector == buttontestver

#include <dpp/dpp.h>
#include <iostream>
#include <dpp/message.h>
 
int main()
{
    dpp::cluster bot(Sbot_token);
 

    bot.on_ready([&bot](const dpp::ready_t& event) {
        bot.log(dpp::ll_info, "Logged in as " + bot.me.username);
        });


    /* Message handler to look for a command called !button */
    bot.on_message_create([&bot](const dpp::message_create_t & event) {
        if (event.msg.content == "!ping") {
            bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
        }
        if (event.msg.content == "!button") {
            /* Create a message containing an action row, and a button within the action row. */
            bot.message_create(
                dpp::message(event.msg.channel_id, "this text has buttons").add_component(
                    dpp::component().add_component(
                        dpp::component().set_label("Click me!").
                        set_type(dpp::cot_button).
                        //set_emoji(":smiling_imp:").//u8"😄").
                        set_style(dpp::cos_danger).
                        set_id("myid")
                    )
                ).add_component(dpp::component().add_component(dpp::component().set_label("Click meee").set_type(dpp::cot_button).set_style(dpp::cos_secondary).set_id("mrow")))
            );
        }
    });
 
    /* When a user clicks your button, the on_button_click event will fire,
     * containing the custom_id you defined in your button.
     */
    bot.on_button_click([&bot](const dpp::button_click_t & event) {
        /* Button clicks are still interactions, and must be replied to in some form to
         * prevent the "this interaction has failed" message from Discord to the user.
         */
        event.reply(dpp::ir_channel_message_with_source, "You clicked: " + event.custom_id);
    });
 
    bot.start(false);
 
    return 0;
}

#endif



#if selector ==  messagetestver

#include <dpp/dpp.h>
#include <iostream>


int main()
{
    try {
        dpp::cluster bot(Sbot_token);
        //remember to not upload this to github like you did the last time idiot 

        bot.on_ready([&bot](const dpp::ready_t& event) {
            bot.log(dpp::ll_info, "Logged in as " + bot.me.username);
        });

        bot.on_message_create([&bot](const dpp::message_create_t& event) {
            if (event.msg.content == "!ping") {
                bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
            }
        });

        bot.on_log([](const dpp::log_t& event) {
            if (event.severity > dpp::ll_trace) {
                std::cout << dpp::utility::loglevel(event.severity) << ": " << event.message << "\n";
            }
        });

        bot.start(false);
 
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }


    return 0;
}

#endif