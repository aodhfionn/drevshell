#include <iostream>
#include <dpp/dpp.h>

#include "cmdmap.hpp"

void assign_map()
{
    commands["say"] = cmds::say;
}

void cmds::say(dpp::cluster* bot, std::string input)
{
        std::cout << "\"" << input << "\"" << std::endl;
        
        dpp::snowflake channel_id = 970053852583854190; // placeholder id
        dpp::message msg(channel_id, input);
        bot->message_create(msg);
        
}