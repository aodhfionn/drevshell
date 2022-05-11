#include <iostream>
#include <dpp/dpp.h>

#ifndef CMDMAP_HPP
#define CMDMAP_HPP

namespace cmds
{

    void test(int);
    void say(dpp::cluster*, std::string);

} // namespace cmds

inline std::map<std::string, std::function<void(dpp::cluster*, std::string)>> commands; // funky inline holds this together

void assign_map();

#endif // CMDMAP_HPP