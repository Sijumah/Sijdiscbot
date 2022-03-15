//module;

#pragma once 

#include <vector>
#include <thread>
#include <iostream>

//export module miscfunctions;


template <class T>
void delete_and_swap_from_vectors(std::vector<T*>& deleter, std::vector<T*>& reciever){
    reciever.insert(deleter.begin(),deleter.end());
    //delete from old one; this function seems redundant... will investigate
};

#ifdef yes
#define prompt_console_instead_of_discord
std::string prompt (const std::string& supprompt)
#ifdef prompt_console_instead_of_discord

{ return Sijf::prompt_console(std::move(supprompt)); };
#else
std::string prompt_discord(const std::string& supprompt) {};//todo. Later on, use #define prompt prompt_console_temp and then change it to prompt_discord
#endif


#endif //endif ifdef yes
