#include <iostream>
#include <fstream>
#include <vector>

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

#include "cmdmap.hpp"
#include "argparse.hpp"

void killbot(dpp::cluster* bot)
{
    std::cout << "Killed " << bot->me.username << std::endl;
    // placeholder
}

json load_config(const std::string path)
{
    json config;
    std::ifstream file(path);
    file >> config;

    return config;
}

std::string prompt()
{
    std::cout << "\n> ";

    std::string input;
    getline(std::cin, input);

    return input;
}

int main()
{
    assign_map();
    json config = load_config("config.json");

    dpp::cluster bot(config["token"]); // loads bot using token from config.json

    bool running = true;
    
    // pass address of outside variables into lambda in order for them to become accessible
    bot.on_ready([&bot, &running](const dpp::ready_t& event) 
    {
        
        std::cout << "Logged in as " << bot.me.username << std::endl;

        while (running)
        {
            std::string input = prompt();
            std::vector<std::string> vector = ap::split(input);

            if (commands.find(vector.at(0)) != commands.end())
            {
                std::string args = ap::combine(vector);

                commands[vector.at(0)](&bot, args);
            }
        }
        
        killbot(&bot);
    });

    if (running)
        bot.start(false);
    
    return 0;
}